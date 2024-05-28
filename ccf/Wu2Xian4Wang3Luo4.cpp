#include <cstdio>
#include <cstdlib>
#include <queue>

#define ll long long
constexpr int maxn = 256;

ll x[maxn], y[maxn];
bool is_luyou[maxn];
int dis[maxn];
int luyous[maxn];

constexpr int maxm = 2*maxn;

int nxt[maxn], hed[maxn], val[maxn];
int cnt = 1;

using namespace std;

void add_edge(int from, int to){
#ifdef DEBUG
    printf("%d\t%d\n", from, to);
#endif
    int new_node = ++cnt;
    nxt[new_node] = hed[from];
    hed[from] = new_node;
    val[new_node] = to;
    new_node = ++cnt;
    nxt[new_node] = hed[to];
    hed[to] = new_node;
    val[new_node] = from;
}

int n, m, k;
ll r;
int main(){
    scanf("%d%d%d%lld", &n, &m, &k, &r);

    for (int i=1; i<=n+m; i++){
        scanf("%lld%lld", x+i, y+i);
        if (i>n)    is_luyou[i] = 1;
        dis[i] = 0x3f3f3f3f;
        luyous[i] = 0x3f3f3f3f;
        for (int j=1; j<i; j++){
            int dx = x[i]-x[j];
            int dy = y[i]-y[j];
            if (dx*dx+dy*dy <= r*r) add_edge(i, j);
        }
    }

    // node, num of luyou from root to here
    std::queue<std::pair<int, int>> q1, q2;
    q1.push(std::make_pair(1, 0));
    dis[1] = 1;
    luyous[1] = 0;
    
    int ans = 1;
    for (; !q1.empty(); ans++){
        while (!q1.empty()){
            int cur_node    = q1.front().first;
            int cur_luyou   = q1.front().second;
            q1.pop();
            if (cur_luyou>k)    continue;
            if (cur_node == 2) {
                printf("%d\n", ans-1);
                return 0;
            }
            for (int nd=hed[cur_node]; nd; nd=nxt[nd]){
                int to = val[nd];
                int to_luyou = cur_luyou + (is_luyou[to]);
                if (to_luyou > k)   continue;
                if (luyous[to] > to_luyou){
                    dis[to] = ans+1;
                    luyous[to] = to_luyou;
                    q2.push(make_pair(to, to_luyou));
                    continue;
                } else if (dis[to] > ans+1){
                    dis[to] = ans+1;
                    luyous[to] = to_luyou;
                    q2.push(make_pair(to, to_luyou));
                }
            }
        }
        q1.swap(q2);
    }
    return 0;
}