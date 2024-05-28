#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <unordered_map>

#ifndef DEBUG
constexpr int maxn = 4* (3e5+10);
#else
constexpr int maxn = 100;
#endif

int prev[maxn], next[maxn];
int val[maxn];

struct A{
    long long x, w;
    bool operator<(A&other){
        return this->x < other.x;
    }
};
A as[maxn];

int main(){
    int c, m, n;
    scanf("%d%d%d", &c, &m, &n);
    for (int i=1; i<=m; i++){
        scanf("%lld%lld", &as[i].x, &as[i].w);
    }

    std::sort(as+1, as+m+1);
    /*next[as[0].x] = as[1].x;
    val[as[0].x] = as[0].w;
    for (int i=1; i<m-1; i++){
        val[as[i].x] = as[i].w;
        prev[as[i].x] = as[i-1].x;
        next[as[i].x] = as[i+1].x;
    }
    prev[as[m-1].x] = as[m-2].x;
    val[as[m-1].x] = as[m-1].w;
    */

    std::unordered_map<long long, int> mp;
    mp[as[1].x] = 1;
    mp[as[m].x] = m;
    next[1] = 2;
    prev[m] = m-1;
    val[1] = as[1].w;
    val[m] = as[m].w;
    for (int i=2; i<=m-1; i++){
        prev[i] = i-1;
        next[i] = i+1;
        val[i] = as[i].w;
        mp[as[i].x] = i;
    }
    int ans = m;
    while (n--){
        int p;
        scanf("%d", &p);
        p = mp[p];
        val[p]++;
        if (val[p] < 5) {
            printf("%d\n", ans);
            continue;
        }
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> q;
        q.push(p);
        while (!q.empty()){
            long long cur = q.top();
            q.pop();
            if (val[cur] == 0){
                continue;
            }
            ans--;
            val[cur] = 0;
            int pre = prev[cur],
                nxt = next[cur];
            next[pre] = nxt;
            prev[nxt] = pre;
            if (pre != 0){
                val[pre]++;
                if (val[pre] >= 5){
                    q.push(pre);
                }
            }
            if (nxt != 0){
                val[nxt]++;
                if (val[nxt] >= 5){
                    q.push(nxt);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}