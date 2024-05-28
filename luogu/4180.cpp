#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include <queue>

// TODO: if RE 
constexpr int maxn = 1001;
constexpr int maxm = 3001;

using namespace std;

int fa[maxn];

int get_fa(int a){
    if (fa[a] == a) return a;
    return fa[a] = get_fa(fa[a]);
}

struct edge{
    int from, to, dis;
    bool operator<(struct edge& obj){
        return dis < obj.dis;
    }
};
edge edges[maxm];
edge chosen_edges[maxn];

int cnt = 1;
int from[2*maxn], to[2*maxn], nxt[2*maxn], head[maxn], dis[2*maxn];
bool visited[maxn];
int last[maxn];
int last_dis[maxn];

void add_tree_edge(int x, int y, int z){
    int nnext = head[x];
    head[x] = cnt;
    nxt[cnt] = nnext;
    to[cnt] = y;
    dis[cnt] = z;
    cnt++;
    nnext = head[y];
    head[y] = cnt;
    nxt[cnt] = nnext;
    to[cnt] = x;
    dis[cnt] = z;
    cnt++;
}

int main(){
    int n, m, i, j;
    scanf("%d%d", &n, &m);
    for (int i=0; i<=n; i++){
        fa[i] = i;
    }
    for (i=0,j=0; i<m; i++){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (x == y){
            continue;
        }
        edges[j].from = x;
        edges[j].to = y;
        edges[j].dis = z;
        j++;
    }
    m = j;

    std::sort(edges, edges+m);

    long long min_tree = 0;
    int longest_edge_of_tree = 0;
    int longest_edge_index = 0;
    for (i=0; i<m; i++){
        int x=edges[i].from, y=edges[i].to;
        int x_fa = get_fa(x), y_fa = get_fa(y);
        if (x_fa == y_fa){
            continue;
        } else {
            int z = edges[i].dis;
            min_tree += z;
            fa[x_fa] = y_fa;
            longest_edge_of_tree = z;
            longest_edge_index = i;
            j++;
            add_tree_edge(x, y, z);   
        }
    }

    for (i=longest_edge_index+1; i<m; i++){
        if (edges[i].dis == longest_edge_of_tree){
            continue;
        } else {
            longest_edge_of_tree = edges[i].dis;
            break;
        }
    }
    long long ans = longest_edge_of_tree + min_tree;
    for (; i<m; i++){
        if (edges[i].dis != longest_edge_of_tree){
            break;
        }
        for (int j=0; j<=n; j++){
            visited[j] = 0;
            last[j] = 0;
            last_dis[i] = 0;
        }
        std::queue<int> q;
        q.push(edges[i].from);

        visited[edges[i].from] = true;
        // if edges[i].to visited then break
        while (!q.empty()){
            int from = q.front();
            printf("from=%d\n", from);
            q.pop();
            for (int node=head[from]; node!=0; node=nxt[node]){
                int tto = to[node];

                if (visited[tto]){
                    continue;
                }
                q.push(tto);
                last[tto] = from;
                visited[tto] = true; 
                last_dis[tto] = dis[node];
                if (tto == edges[i].to){
                    goto OUT_OF_LOOP;
                }
            }
        }
OUT_OF_LOOP:
        int longest_edge_of_round = 0;
        for (int v=edges[i].to; v!=edges[i].from; v=last[v]){
            longest_edge_of_round = max(longest_edge_of_round, last_dis[v]);
        }
        ans = min(ans, longest_edge_of_tree+min_tree-longest_edge_of_round);
    }

    printf("%lld\n", ans);

}