#include<bits/stdc++.h>
#include "testlib.h"
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 
using namespace std;
using LL = long long;
string decode(string s) {
    string res = "";
    int n = s.length();
    REP(i,0,n-1) {
        int j = i;
        bool isd = isdigit(s[i]);
        while (isd && j+1<n && isdigit(s[j+1])) j++;

        int rep = 1;
        char c = s[i];
        int nxt = i;
        if (isd) {
            rep = atoi(s.substr(i, j-i+1).c_str());
            c = s[j+1];
            nxt = j+1;
        }

        REP(_t,1,rep) res += c;
        i = nxt;
    }
    return res;
}
string encode(string s) {
    string res = "";
    int n = s.length();
    REP(i,0,n-1) {
        int j = i;
        while (j+1<n && s[j+1]==s[i]) j++;

        if (j-i+1 > 1) {
            res += to_string(j-i+1);
        }
        res += s[i];
        i = j;
    }
    return res;
}
int max_dup(string s) {
    int n = s.length();
    int res = 0;
    REP(i,0,n-1) {
        int j = i;
        while (j+1<n && s[j+1]==s[i]) j++;

        res = max(res, j-i+1);
        i = j;
    }
    return res;
}
int main(int argc, char* argv[])
{
    registerValidation(argc, argv);

    int MXN = 1000;
    int MXD = 100;
    char cmd[50];

    sprintf(cmd, "[0-9a-z]{1,%d}", MXN);
    string in = inf.readToken(cmd, "ins");
    inf.readChar('\n');
    inf.readEof();

    string out = decode(in);
    ensuref(encode(out)==in, "encode(decode(input)) == input");

    ensuref(max_dup(out)<=MXD, "max duplicate <= 100");

    return 0;
}

