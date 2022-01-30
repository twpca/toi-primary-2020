#include<climits>
#include<cstdio>
#include<algorithm>
#include<array>
#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;

int c2i(char c){
   switch(c){
      case 'r': return 0;
      case 'g': return 1;
      case 'b': return 2;
      default: return 3;
   }
}

struct Ac{
   vector<int> fail;
   vector<array<int, 3>> chld;
   vector<int> sw;
   Ac(): fail(1), chld(1, {0, 0, 0}), sw(1){}
   void insert(char const *p, int w){
      int i = 0;
      for(; *p; ++p){
         int c = c2i(*p);
         if(!chld[i][c]){
            chld[i][c] = fail.size();
            fail.push_back(0);
            chld.push_back({0, 0, 0});
            sw.push_back(0);
         }
         i = chld[i][c];
      }
      sw[i] += w;
   }
   void build(){
      queue<int> bfs;
      for(int i=0; i<3; ++i) if(chld[0][i]){
         bfs.push(chld[0][i]);
      }
      while(!bfs.empty()){
         int u = bfs.front(); bfs.pop();
         for(int i=0; i<3; ++i){
            if(chld[u][i]){
               fail[chld[u][i]] = chld[fail[u]][i];
               bfs.push(chld[u][i]);
            }else{
               chld[u][i] = chld[fail[u]][i];
            }
         }
         sw[u] += sw[fail[u]];
      }
   }
};

int main(){
   int n, m;
   cin >> n >> m;
   Ac ac;
   while(m--){
      string s;
      int w;
      cin >> s >> w;
      ac.insert(s.data(), w);
   }
   ac.build();
   vector<int> dp[2];
   dp[0] = vector<int>(ac.fail.size(), INT_MIN);
   dp[1] = vector<int>(ac.fail.size());
   dp[0][0] = 0;
   string s;
   cin >> s;
   for(size_t i=0; i<s.size(); ++i){
      fill(dp[i+1&1].begin(), dp[i+1&1].end(), INT_MIN);
      vector<int> chld;
      if(int c=c2i(s[i]); c<3){
         chld = {c};
      }else{
         chld = {0, 1, 2};
      }
      for(size_t u=0; u<ac.chld.size(); ++u){
         for(int j: chld){
            int v = ac.chld[u][j];
            dp[i+1&1][v] = max(dp[i+1&1][v], dp[i&1][u]+ac.sw[v]);
         }
      }
   }
   printf("%d\n", *max_element(dp[s.size()&1].cbegin(), dp[s.size()&1].cend()));
}
