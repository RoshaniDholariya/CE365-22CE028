#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<string> keywords = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
    "else", "enum", "extern", "float", "for", "goto", "if", "int", "long",
    "register", "return", "short", "signed", "sizeof", "static", "struct", "switch",
    "typedef", "union", "unsigned", "void", "volatile", "while"
};

unordered_set<string> operators = {
    "+", "-", "*", "/", "%", "=", "==", "!=", "<", ">", "<=", ">=", "&&", "||", "++", "--"
};

unordered_set<char> punctuation = {';', ',', '(', ')', '{', '}', '[', ']'};

vector<string> symbolTable;

unordered_set<char> delimiters = {' ', '\t', '\n', '(', ')', '{', '}', '[', ']', ';', ',', '+', '-', '*', '/', '=', '<', '>', '!', '&', '|', '"', '\''};

bool isIdentifier(const string& token) {
    if (!isalpha(token[0]) && token[0] != '_') return false;
    for (char ch : token) {
        if (!isalnum(ch) && ch != '_') return false;
    }
    return true;
}

bool isConstant(const string& token) {
    bool hasDecimal = false;
    if (token.empty()) return false;
    for (size_t i = 0; i < token.length(); i++) {
        if (!isdigit(token[i])) {
            if (token[i] == '.' && !hasDecimal) {
                hasDecimal = true;
            } else {
                return false;
            }
        }
    }
    return true;
}

bool isPunctuation(char ch) {
    return punctuation.find(ch) != punctuation.end();
}

vector<string> tokenize(string line) {
    vector<string> tokens;
    string token = "";
    for (size_t i = 0; i < line.length(); i++) {
        char ch = line[i];

        if (ch == '"' || ch == '\'') {
            if (!token.empty()) {
                tokens.push_back(token);
                token = "";
            }
            char quote = ch;
            token += ch;
            i++;
            while (i < line.length() && line[i] != quote) {
                token += line[i];
                i++;
            }
            token += quote;
            tokens.push_back(token);
            token = "";
            continue;
        }
        if (delimiters.find(ch) != delimiters.end()) {
            if (!token.empty()) {
                tokens.push_back(token);
                token = "";
            }
            if (isPunctuation(ch) || operators.find(string(1, ch)) != operators.end()) {
                string op(1, ch);
                if (i + 1 < line.length()) {
                    string possibleOp = op + line[i + 1];
                    if (operators.find(possibleOp) != operators.end()) {
                        tokens.push_back(possibleOp);
                        i++;
                        continue;
                    }
                }
                tokens.push_back(op);
            }
        } else {
            token += ch;
        }
    }
    if (!token.empty()) tokens.push_back(token);
    return tokens;
}

void lexicalAnalysis(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file." << endl;
        return;
    }

    string modifiedCode = "";
    string line;
    bool inMultiLineComment = false;

    cout << "TOKENS:\n";

    while (getline(file, line)) {
        size_t singleLineCommentPos = line.find("//");
        if (singleLineCommentPos != string::npos) {
            line = line.substr(0, singleLineCommentPos);
        }

        size_t startComment = line.find("/*");
        size_t endComment = line.find("*/");

        if (startComment != string::npos) {
            inMultiLineComment = true;
        }
        if (endComment != string::npos) {
            inMultiLineComment = false;
            line = line.substr(endComment + 2);
        }
        if (inMultiLineComment) {
            continue;
        }

        modifiedCode += line + "\n";

        vector<string> tokens = tokenize(line);
        for (const string& token : tokens) {
            if (keywords.find(token) != keywords.end()) {
                cout << "Keyword: " << token << endl;
            } else if (isConstant(token)) {
                cout << "Constant: " << token << endl;
            } else if (isIdentifier(token)) {
                cout << "Identifier: " << token << endl;
                symbolTable.push_back(token);
            } else if (operators.find(token) != operators.end()) {
                cout << "Operator: " << token << endl;
            } else if (token.front() == '"' || token.front() == '\'') {
                cout << "String: " << token << endl;
            } else if (isPunctuation(token[0])) {
                cout << "Punctuation: " << token << endl;
            } else {
                cout << "Lexical Error: Invalid token '" << token << "'" << endl;
            }
        }
    }

    file.close();

    cout << "\nSymbol Table:\n";
    for (const auto& id : symbolTable) {
        cout << id << endl;
    }

    ofstream outputFile("modified_" + filename);
    if (outputFile.is_open()) {
        outputFile << modifiedCode;
        outputFile.close();
        cout << "\nModified source code saved as 'modified_" << filename << "'\n";
    } else {
        cout << "Error: Could not save modified source code.\n";
    }
}

int main() {
    string filename;
    cout << "Enter the C source code filename: ";
    cin >> filename;
    lexicalAnalysis(filename);
    return 0;
}
