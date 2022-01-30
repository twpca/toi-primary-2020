#include <algorithm>
#include <numeric>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <array>
using i32 = std::int32_t;
using i64 = std::int64_t;
struct rule_t {
    i32 code;
    i32 len;
    i32 w;
};
struct data_t {
    std::vector<char> street;
    std::vector<rule_t> rules;
    int max_rule;
    auto solve() -> i32;
};
auto decode(char x) -> i32{
    switch(x){
    case 'r': return 0;
    case 'g': return 1;
    case 'b': return 2;
    default: return 3;
    }
}
auto operator>>(std::istream &is, data_t &d) -> std::istream &
{
    i32 n, k;
    is >> n >> k;
    if (!is)
        return is;
    d.max_rule = 0;
    d.rules = decltype(d.rules)(k);
    for (auto &x : d.rules) {
        std::string s;
        is >> s >> x.w;
        x.len = s.size();
        x.code = std::accumulate(s.begin(),s.end(),0,[](i32 x, char c){
            return x * 3 + decode(c);
        });
        d.max_rule = std::max(d.max_rule, x.len);
    }
    d.street = decltype(d.street)(n);
    for(auto &x:d.street){
        char c;
        is >> c;
        x = decode(c);
    }
    return is;
}
auto pow3(i32 x) -> i32{
    return x?pow3(x-1) * 3:1;
}
auto data_t::solve() -> i32 {
    const i32 pre_len = max_rule - 1;
    const i32 pre_size = pow3(pre_len);
    using VI = std::vector<i32>;
    VI v(pre_size * 3);
    auto add_rule = [this, &v](auto r){
        auto var = pow3(max_rule - r.len);
        auto invar = pow3(r.len);
        for(i32 i=0;i<var;++i){
            v[i*invar + r.code] += r.w;
        }
    };
    VI cr(pre_size), nx(pre_size);
    const std::array<VI, 4> list{
        VI({0}),
        VI({1}),
        VI({2}),
        VI({0,1,2})
    };
    for(i32 i=0,n=street.size();i<n;++i){
        for(auto r:rules){
            if(r.len != i+1)continue;
            add_rule(r);
        }
        std::fill(nx.begin(),nx.end(),-(1<<30));
        for(int j=0;j<pre_size;++j){
            for(auto c:list[street[i]]){
                auto &nv = nx[(j*3)%pre_size + c];
                nv = std::max(nv, cr[j] + v[j * 3 + c]);
            }
        }
        std::swap(cr, nx);
    }
    return *std::max_element(cr.begin(), cr.end());
}
int main()
{
    std::ios::sync_with_stdio(false);
    data_t d;
    while (std::cin >> d) {
        std::cout << d.solve() << '\n';
    }
    std::cout.flush();
}