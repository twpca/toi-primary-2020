#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <set>
#include <sstream>
#include <vector>
using i32 = std::int32_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using dot_t = std::array<u64, 2>;
struct query_t{
    u64 N;
    u64 A;
    u64 B;
    dot_t s;
    dot_t t;
};
struct data_t {
    std::vector<query_t> a;
    u64 A, B, N;
    u64 phi;
    auto add(u64 x, u64 y) const
    {
        auto r = x + y;
        if (r >= N)
            r -= N;
        return r;
    }
    auto subtract(u64 x, u64 y) const { return add(x, N - y); }
    auto the_pow(u64 x, u64 y) const
    {
        u64 ans = 1;
        u64 p = x;
        for (; y; y /= 2) {
            if (y & 1) {
                ans *= p;
                ans %= N;
            }
            p *= p;
            p %= N;
        }
        return ans; // assume N!=1
    }
    auto division(u64 x, u64 y) const { return x * the_pow(y, N - 2) % N; }
    auto set(query_t x){
        A = x.A;
        B = x.B;
        N = x.N;
        // pre-calculation start
        phi = N - 1;
        // pre-calculation end
    }
    auto merge(dot_t l, dot_t r) const -> dot_t;
    auto solve() -> std::vector<dot_t>{
        std::vector<dot_t> anss(a.size());
        for(size_t i=0;i<a.size();++i){
            set(a[i]);
            anss[i] = merge(a[i].s,a[i].t);
        }
        return anss;
    }
};
auto operator>>(std::istream &is, data_t &d) -> std::istream &
{
    i32 n;
    is >> n;
    if (!is)
        return is;
    d.a = decltype(d.a)(n);
    for (auto &x : d.a) {
        is >> x.N >> x.A >> x.B >> x.s[0] >> x.s[1] >> x.t[0] >> x.t[1];
    }
    return is;
}
auto operator<<(std::ostream &os, const data_t &d) -> std::ostream &
{
    const i32 n = d.a.size();
    os << n << '\n';
    for (auto &x : d.a) {
        os << x.N << ' ' << x.A << ' ' << x.B << ' ' << x.s[0] << ' ' << x.s[1]
           << ' ' << x.t[0] << ' ' << x.t[1] << '\n';
    }
    return os;
}
auto data_t::merge(dot_t l, dot_t r) const -> dot_t
{
    u64 dx = subtract(r[0], l[0]);
    u64 dy = subtract(r[1], l[1]);
    u64 slope = 0;
    bool cut = false;
    if (dx == 0 && dy == 0) {
        cut = true;
        // supposed to solve cut line here
        auto x = l[0];
        auto y = l[1];
        slope = division(add(3 * x % N * x % N, A), 2 * y % N);
    } else if (dx == 0) {
        return l;
    } else {
        slope = division(dy, dx);
    }
    auto x3 = subtract(add(l[0], slope * slope % N),
                       add((1 - cut) * dx, 3 * l[0] % N));
    auto y3 = subtract(add(l[1], slope * slope % N * slope % N),
                       add((1 - cut) * dy, 3 * l[0] % N * slope % N));
    return {x3, y3};
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    data_t d;
    while (std::cin >> d) {
        auto ans = d.solve();
        for(auto a:ans){
            std::cout << a[0] << ' ' << a[1] << '\n';
        }
    }
}