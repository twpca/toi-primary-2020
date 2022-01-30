#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000 + 10;

vector<pair<int,int>> v[MAX];
bool vis[MAX];
int dp[MAX][2];

void update(int value, int &mmax, int &smax) {
    if(value > mmax) smax = mmax, mmax = value;
    else if(value < mmax && value > smax) smax = value;
}

pair<int,int> go(int x) {
    vis[x] = true;
    int largest = 0;
    int slargest = 0;
    for(auto pr: v[x]) {
        if(vis[pr.first]) continue;
        pair<int,int> tmp = go(pr.first);
        tmp.first += pr.second;
        tmp.second += pr.second;
        update(largest + tmp.first, dp[x][0], dp[x][1]);
        update(largest + tmp.second, dp[x][0], dp[x][1]);
        update(slargest + tmp.first, dp[x][0], dp[x][1]);
        update(tmp.first, largest, slargest);
        update(tmp.second, largest, slargest);
    }
    update(largest, dp[x][0], dp[x][1]);
    update(slargest, dp[x][0], dp[x][1]);
    return make_pair(largest, slargest);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n-1 ; i++) {
        int x, y, d;
        scanf("%d %d %d", &x, &y, &d);
        v[x].push_back(make_pair(y, d));
        v[y].push_back(make_pair(x, d));
    }
    go(0);
    int ans = 0, mmax = 0;
    for(int i = 0 ; i < n ; i++) {
        update(dp[i][0], mmax, ans);
        update(dp[i][1], mmax, ans);
    }
    printf("%d\n", ans);
    return 0;
}
