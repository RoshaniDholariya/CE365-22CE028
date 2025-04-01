#include <iostream>
using namespace std;

int in = 0;
bool flag = true;

void S(string& st);
void L(string& st);
void Ldash(string& st);

void S(string& st) {
    if (st[in] == '(') {
        in++;
        L(st);
        if (st[in] == ')') {
            in++;
            flag=true;
        } else {
            flag = false;
        }
    } else if (st[in] == 'a') {
        in++;
        flag=true;
    } else {
        flag = false;
    }
}

void L(string& st) {
    S(st);
    Ldash(st);
}

void Ldash(string& st) {
    if (st[in] == ',') {
        in++;
        S(st);
        Ldash(st);
    }
    else if(st[in]=='\0'){
        flag=true;
    }
    else{
        flag=false;
    }
}

int main() {
    string st;
    cout << "Enter the string: ";
    cin >> st;

    in = 0;
    flag = true;

    S(st);

    if (flag && in == st.length()) {
        cout << "Valid string" << endl;
    } else {
        cout << "Invalid string" << endl;
    }
    return 0;
}
