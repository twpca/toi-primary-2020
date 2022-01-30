#include<bits/stdc++.h>
#include"testlib.h"

using namespace std;

int main(int argc, char* argv[]){
    registerValidation(argc, argv);

    int MIN_C = 1;
    int MAX_C = 1000;
    
    char regEx[20];
    sprintf(regEx, "[0-9a-z]{%d,%d}", MIN_C, MAX_C);

    string s = inf.readToken(regEx, "Input string C");
    inf.readChar('\n');
    inf.readEof();

    int coe = 0;
    char last = 0;
    for (auto c: s) {
        if (isdigit(c)) {
            coe = coe * 10 + c - '0';
            ensuref(coe <= 9, "Special rule for subtask 1: coefficient at most 9");
        } else {
            last = c;
            coe = 0;
        }
    }
    
    return 0;
}
