#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
using i64 = long long;

struct Rp1{
   int x, y;
   Rp1() = default;
   constexpr Rp1(int x0, int y0) noexcept: x(x0), y(y0){
      if(y<0 || y==0 && x<0){
         x = -x, y = -y;
      }
   }
   bool operator<(Rp1 q) const noexcept{
      return (i64)x*q.y-(i64)y*q.x > 0;
   }
   bool operator==(Rp1 q) const noexcept{
      return (i64)x*q.y-(i64)y*q.x == 0;
   }
};

int main(){
   int n;
   scanf("%d", &n);
   vector<pair<Rp1, int>> bulb;
   bulb.reserve(n);
   int sw = 0;
   for(int i=0; i<n; ++i){
      int x, y, w;
      scanf("%d%d%d", &x, &y, &w);
      bulb.emplace_back(Rp1{x, y}, w);
      sw += w;
   }
   sort(bulb.begin(), bulb.end());
   int ans = 0, smin = 0, smax = 0, si = 0;
   for(int i=0; i<n; ++i){
      si += bulb[i].second;
      while(i+1<n && bulb[i].first==bulb[i+1].first){
         si += bulb[++i].second;
      }
      smin = min(smin, si);
      smax = max(smax, si);
      ans = max({ans, si-smin, sw-(si-smax)});
   }
   printf("%d\n", ans);
}
