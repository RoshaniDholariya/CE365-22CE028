#include <iostream>
#include <sstream>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if a string is a number
bool isNumber(const string &s) {
    return all_of(s.begin(), s.end(), [](char c) { return isdigit(c) || c == '.'; });
}

// Function to evaluate an operation
double applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : 0; // Avoid division by zero
    }
    return 0;
}

// Function to perform constant folding without using stack
string constantFolding(const string &expr) {
    istringstream tokens(expr);
    string token;
    vector<string> output;
    double result = 0;
    char lastOp = '+';
    bool hasConstant = false;

    while (tokens >> token) {
        if (isNumber(token)) {
            double num = stod(token);
            if (lastOp == '+') result += num;
            else if (lastOp == '-') result -= num;
            else if (lastOp == '*') result *= num;
            else if (lastOp == '/') result = (num != 0) ? (result / num) : 0;
            hasConstant = true;
        } else if (token.size() == 1 && string("+-*/").find(token) != string::npos) {
            lastOp = token[0];
        } else {
            if (hasConstant) {
                output.push_back(to_string(result));
                hasConstant = false;
                result = 0;
                lastOp = '+';
            }
            output.push_back(token);
        }
    }

    if (hasConstant) {
        output.push_back(to_string(result));
    }

    string optimizedExpr;
    for (const string &s : output) {
        optimizedExpr += s + " ";
    }
    return optimizedExpr;
}

int main() {
    string input;
    cout << "Enter an arithmetic expression: ";
    getline(cin, input);  // Taking input from user

    cout << "Optimized Expression: " << constantFolding(input) << "\n";

    return 0;
}
