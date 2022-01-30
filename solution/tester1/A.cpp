#include<bits/stdc++.h>
using namespace std;

void validate(string s) {
    assert(s.length() <= 1000);
    assert(s.length() > 0);
    for (auto c: s) {
        assert(isdigit(c) || c >= 'a' && c <= 'z');
    }
}

int main() {
    string n;
    cin >> n;

    validate(n);

    int last = 0;
    for (auto c: n) {
        if(isdigit(c)) {
            last = last * 10 + c - '0';
        } else {
            if(last == 0) last = 1;
            while(last--) putchar(c);
            last = 0;
        }
    }
    return 0;
}
