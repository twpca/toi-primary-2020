#include<cctype>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

int main(){
   string s, ans;
   cin >> s;
   int cnt = 0;
   for(char c: s){
      if(isdigit(c)){
         cnt = 10*cnt+c-'0';
      }else{
         ans += string(max(cnt, 1), c);
         cnt = 0;
      }
   }
   puts(ans.data());
}
