#include <cstdio>
#include <cstdlib>

#ifdef DEBUG
constexpr int maxn = 100;
#else
constexpr int maxn = 1e5+10;
#endif

int prev[maxn], next[maxn], val[maxn];

int n;
void print(){
    for (int node=next[n+1]; node!=0&&node!=n+1; node=next[node]){
        printf("%d ", node);
    } 
    printf("\n");
}

int main(){
    scanf("%d", &n); 
    val[1] = n+1;
    prev[1] = next[1] = n+1;
    prev[n+1] = next[n+1] = 1;
 
    for (int i=2; i<=n; i++){
        int k, p;
        scanf("%d%d", &k, &p);
        val[i] = i;
        if (p==0){
            next[prev[k]] = i;
            prev[i] = prev[k];
            next[i] = k;
            prev[k] = i;
        } else {
            prev[next[k]] = i;
            next[i] = next[k];
            prev[i] = k;
            next[k] = i;
        }
#ifdef DEBUG
        print();
#endif
    }   

    int m;
    scanf("%d", &m);
    for (int i=0; i<m; i++){
        int x;
        scanf("%d", &x);
        if (val[x] == 0){
            continue;
        }
        val[x] = 0;
        next[prev[x]] = next[x];
        prev[next[x]] = prev[x];
        prev[x] = next[x] =  0;
#ifdef DEBUG
        print();
#endif
    }

    print();
    return 0;
}
