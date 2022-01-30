#include<climits>
#include<cstdio>
#include<algorithm>
#include<array>
#include<vector>
using namespace std;

struct Edge{
   int v, w;
   Edge() = default;
   constexpr Edge(int v, int w) noexcept: v(v), w(w){}
};

void update12(int &a1, int &a2, int x){
   if(x > a1){
      a2 = a1, a1 = x;
   }else if(x < a1 && x > a2){
      a2 = x;
   }
}

array<int, 4> dfs(vector<vector<Edge>> const &g, int u, int p){
   array<int, 4> ans{0, INT_MIN, 0, INT_MIN};
   for(auto [v, w]: g[u]){
      if(v == p){
         continue;
      }
      auto av = dfs(g, v, u);
      update12(ans[0], ans[1], av[0]);
      update12(ans[0], ans[1], av[1]);
      update12(ans[0], ans[1], ans[2]+av[2]+w);
      update12(ans[0], ans[1], ans[2]+av[3]+w);
      update12(ans[0], ans[1], ans[3]+av[2]+w);
      update12(ans[2], ans[3], av[2]+w);
      update12(ans[2], ans[3], av[3]+w);
   }
   return ans;
}

int main(){
   int n;
   scanf("%d", &n);
   vector<vector<Edge>> g(n);
   for(int i=n-1; i-->0; ){
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
   }
   printf("%d\n", dfs(g, 0, 0)[1]);
}
