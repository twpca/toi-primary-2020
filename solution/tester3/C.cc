#include<cstdio>
#include<utility>
using namespace std;
using i64 = long long;

pair<i64, i64> extgcd(i64 a, i64 b) noexcept{
   if(!b) return {1, 0};
   i64 k = a/b;
   auto p = extgcd(b, a%b);
   return {p.second, p.first-k*p.second};
}

struct Zp{
   static i64 p;
   i64 x;
   Zp() = default;
   explicit Zp(i64 x) noexcept: x((x%p+p)%p){}
   Zp operator+(Zp b) const noexcept{
      return Zp(x+b.x);
   }
   Zp operator-(Zp b) const noexcept{
      return Zp(x-b.x);
   }
   Zp operator*(Zp b) const noexcept{
      return Zp(x*b.x);
   }
   Zp inv() const noexcept{
      return Zp(extgcd(x, p).first);
   }
   Zp operator/(Zp b) const noexcept{
      return Zp(*this*b.inv());
   }
};
i64 Zp::p;

int main(){
   int T;
   scanf("%d", &T);
   while(T-->0){
      int c[7];
      for(int i=0; i<=6; ++i){
         scanf("%d", c+i);
      }
      Zp::p = c[0];
      Zp a(c[1]), b(c[2]), x1(c[3]), y1(c[4]), x2(c[5]), y2(c[6]);
      Zp slope = (y2-y1)/(x2-x1);
      Zp x3 = slope*slope-x1-x2;
      Zp y3 = slope*x3+(x2*y1-x1*y2)/(x2-x1);
      printf("%lld %lld\n", x3.x, y3.x);
   }
}
