#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000 + 10;

vector<pair<int,int>> v[MAX];
int n;
int dis[MAX];

void go(int x, int p) {
    for(auto pr: v[x]) {
        if(pr.first == p) continue;
        dis[pr.first] = dis[x] + pr.second;
        go(pr.first, x);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0 ; i < n-1 ; i++) {
        int x, y, d;
        scanf("%d %d %d", &x, &y, &d);
        v[x].push_back(make_pair(y, d));
        v[y].push_back(make_pair(x, d));
    }
    go(0, -1);
    dis[0] = 0;
    int p = 0;
    for(int i = 0 ; i < n ; i++) {
        if(dis[i] > dis[p]) p = i;
    }
    dis[p] = 0;
    go(p, -1);
    int ans = 0;
    for(int i = 0 ; i < n ; i++) {
        ans = max(ans, dis[i]);
    }
    printf("%d\n", ans-1);
    return 0;
}
