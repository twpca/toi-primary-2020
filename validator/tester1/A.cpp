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
            ensuref(!(c == '0' && coe == 0), "No leading zeroes");
            coe = coe * 10 + c - '0';
            ensuref(coe <= 100, "Coefficient should be less than or equal to 100");
        } else {
            ensuref(coe != 1, "Coefficient should not be 1");
            ensuref(last != c, "Same character shouldn't be together");
            last = c;
            coe = 0;
        }
    }
    
    return 0;
}
