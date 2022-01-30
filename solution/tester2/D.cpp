#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <vector>
using i32 = std::int32_t;
using i64 = std::int64_t;
struct dot_t {
    i32 x;
    i32 y;
    i64 w;
};
struct data_t {
    std::vector<dot_t> a;
    i64 max_substring() const;
    i64 solve();
};
auto operator>>(std::istream &is, data_t &d) -> std::istream &
{
    i32 n;
    is >> n;
    if (!is)
        return is;
    d.a = decltype(d.a)(n);
    for (i32 i = 0; i < n; ++i) {
        i32 x, y;
        i64 w;
        is >> x >> y >> w;
        if (x < 0 || (x == 0 && y < 0)) {
            y *= -1;
            x *= -1;
        }
        d.a[i] = decltype(d.a)::value_type{x, y, w};
    }
    return is;
}
auto data_t::max_substring() const -> i64
{
    i64 ans = 0;
    i64 sum = 0;
    for (auto x : a) {
        auto tmp = sum + x.w;
        sum = tmp < 0 ? 0 : tmp;
        ans = std::max(ans, sum);
    }
    return ans;
}
auto data_t::solve() -> i64
{
    // sort and unique by slope
    std::sort(a.begin(), a.end(), [](auto &l, auto &r) {
        // return l.second/l.first < r.second/r.first;
        return i64(r.x) * l.y < i64(l.x) * r.y;
    });
    auto equ = [](auto &l, auto &r) {
        return i64(r.x) * l.y == i64(l.x) * r.y;
    };
    auto ot = a.begin();
    for (auto it = a.begin(); it < a.end();) {
        auto jt = it++;
        for (; it < a.end() && equ(*jt, *it); ++it) {
            (*jt).w += (*it).w;
        }
        *(ot++) = *jt;
    }
    a.erase(ot, a.end());
    i64 mx = max_substring();
    i64 sum = 0;
    for (auto &x : a) {
        sum += x.w;
        x.w *= -1;
    }
    i64 mn = max_substring();
    return std::max(mx, sum + mn);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    data_t d;
    while (std::cin >> d) {
        std::cout << d.solve() << '\n';
    }
    std::cout.flush();
}