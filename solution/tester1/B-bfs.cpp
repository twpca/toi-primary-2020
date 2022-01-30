#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000 + 10;

vector<pair<int,int>> v[MAX];
int n;
int dis[MAX];

int find(int x) {
    // find the farthest point
    memset(dis, -1, sizeof(dis));
    dis[x] = 0;
    queue<int> q;
    q.push(x);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(auto pr: v[now]) {
            if(dis[pr.first] == -1) {
                dis[pr.first] = dis[now] + pr.second;
                q.push(pr.first);
            }
        }
    }
    int ret = 0;
    for(int i = 0 ; i < n ; i++) {
        if(dis[i] > dis[ret]) {
            ret = i;
        }
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for(int i = 0 ; i < n-1 ; i++) {
        int x, y, d;
        scanf("%d %d %d", &x, &y, &d);
        v[x].push_back(make_pair(y, d));
        v[y].push_back(make_pair(x, d));
    }
    int x = find(0);
    int y = find(x);
    int ans = 0;
    for(int i = 0 ; i < n ; i++) {
        if(dis[i] < dis[y] && dis[i] > ans) {
            ans = dis[i];
        }
    }
    int z = find(y);
    for(int i = 0 ; i < n ; i++) {
        if(dis[i] < dis[z] && dis[i] > ans) {
            ans = dis[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
