#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int check(string str) {
    for(int i = 0; i < str.size(); i++) {
        if(str[i] != str[str.size() - 1 - i])
            return 0;
    }
    return 1;
}

int main() {
    string str, tmp;
    string test;
    cin >> str;
    tmp = "";
    for(int i = 0; i < str.size(); i++) {
        tmp = str[i] + tmp;
        test = str + tmp;
        if(check(test)) {
            cout << test;
            return 0;
        }
    }
    return 0;
}

