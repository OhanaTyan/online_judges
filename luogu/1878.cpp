#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cassert>
#include <cstring>

struct B{
    int diff, l, r;
    bool operator>(const B& other)const{
        /*if (this->diff > other.diff)    return true;
        else if (this->diff<other.diff) return false;
        else {
            return this->l > other.l;
        }*/
        if (this->diff != other.diff){
            return this->diff > other.diff;
        }
        return this->l > other.l;
    }

    B(int d, int l, int r):diff(d), l(l), r(r){}
};
#ifdef DEBUG
constexpr int maxn = 100;
#else
constexpr int maxn = 2e5+10;
#endif
int a[maxn];
char g[maxn];
int is_visited[maxn];
int k;
int ls[maxn], rs[maxn];

int pre[maxn], next[maxn];

int main(){
    int n;
    scanf("%d", &n);
    scanf("%s", g+1);
    // assert(strlen(g) == n);
    for (int i=1; i<=n; i++){
        scanf("%d", a+i);
        pre[i] = i-1;
        next[i] = i+1;
    }

    pre[1] = 1;
    next[n] = n;
    std::priority_queue<B, std::vector<B>, std::greater<B>> q;

    for (int i=1; i<=n-1; i++){
        if (g[i]!=g[i+1]){
            q.push(B(abs(a[i]-a[i+1]), i, i+1));
        }
    }

    while (!q.empty()){
        B b = q.top();
        q.pop();
        int l=b.l, r=b.r;
        if (is_visited[l]==false && is_visited[r]==false){
            ls[k] = l;
            rs[k] = r;
            k++;
            is_visited[l]=is_visited[r] = 1;

            int ll = pre[l],
                rr = next[r];
            if (ll==0 || rr==0){
                continue;
            }            
            pre[rr] = ll;
            next[ll] = rr;
 
            if (g[ll] != g[rr]){
                q.push(B(abs(a[ll]-a[rr]), ll, rr));
            }
        }
    }

    printf("%d\n", k);
    for (int i=0; i<k; i++){
        printf("%d %d\n", ls[i], rs[i]);
    }
    return 0;
}


/*
15
1.00 0.00
0.90 0.43
0.62 0.78
0.22 0.97
-0.22 0.97
-0.62 0.78
-0.90 0.43
-1.00 0.00
-0.90 -0.43
-0.62 -0.78
-0.22 -0.97
0.22 -0.97
0.62 -0.78
0.90 -0.43
200 200

*/