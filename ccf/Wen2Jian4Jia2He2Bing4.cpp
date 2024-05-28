#include <cstdio>
#include <cstdlib>
#include <vector>

#ifdef DEBUG
constexpr int maxn = 100;
#else 
constexpr int maxn = 5e5+10;
#endif

int fa[maxn], is_merged[maxn];
long long file[maxn]; // how many bytes under the folder
int head[maxn];
int node_val[maxn];  
int next[maxn];
int rear[maxn];
int num_of_child[maxn];
int cnt = 1;

int qread(){
    char c = getchar();
    while (c==' '&&c=='\n'&&c=='\r'){
        c = getchar();
    }
    int ans = 0;
    if (c == '-'){
        return -qread();
    }
    while (c>='0'&&c<='9'){
        ans *= 10;
        ans += c-'0';
        c = getchar();
    }
    return ans;
}

void add_edge(int father, int child){
    fa[child] = father;
    next[cnt] = head[father];
    if (head[father] == 0){
        rear[father] = cnt;
    }
    head[father] = cnt;
    node_val[cnt] = child;
    num_of_child[father]++;
    cnt++;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    //n = qread();
    //m = qread();
    for (int i=2; i<=n; i++){
        int father;
        scanf("%d", &father);
        //father = qread();
        add_edge(father, i);
    }
    for (int i=1; i<=n; i++){
        scanf("%lld", file+i);
        //file[i] = qread();
    }

    while (m--){
        int op, f;
        scanf("%d%d", &op, &f);
        //op = qread();
        //f = qread();
        if (op == 1){
            int node = head[f];
            head[f] = 0;
            int* pointer = &head[f];
            num_of_child[f] = 0;
            for (; node!=0; node=next[node]){
                int cur = node_val[node];
                num_of_child[f] += num_of_child[cur];
                num_of_child[cur] = 0;
                file[f] += file[cur];
                file[cur] = 0;
                is_merged[cur] = true;
                if (head[cur] == 0){
                    continue;
                } 
                *pointer = head[cur];
                // pointer = rear[cur];
                pointer = &next[rear[cur]];
                head[cur] = 0;
            }
            printf("%d %lld\n", num_of_child[f], file[f]);

        } else {
            int ans = 1;
            int f_copy = f;
            f = fa[f];
            while (f){
                if (is_merged[f]){
                    // do nothing
                } else {
                    fa[f_copy] = f;
                    f_copy = f;
                    ans++;
                }
                f = fa[f];
            }
            printf("%d\n", ans);
        }
    }
}

