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
    int ans = 0, mmax = 0;
    for(int i = 0 ; i < n ; i++) {
        dis[i] = 0;
        go(i, -1);
        for(int j = 0 ; j < n ; j++) {
            if(dis[j] > mmax) {
                ans = mmax;
                mmax = dis[j];
            } else if(dis[j] < mmax && dis[j] > ans) {
                ans = dis[j];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
