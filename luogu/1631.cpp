#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>

#ifndef DEBUG
#define NDEBUG
#endif

#include <cassert>
#ifdef DEBUG
constexpr int maxn = 100;
#else
constexpr int maxn = 1e5+10;
#endif

int a[maxn], b[maxn];

int main(){
    int n;
    scanf("%d", &n);

    for (int i=0; i<n; i++){
        scanf("%d", a+i);
    }

    std::priority_queue<int> q;
    int tmp;
    scanf("%d", &tmp);
    for (int i=0; i<n; i++){
        q.push(a[i] + tmp);
    }

    for (int i=1; i<n; i++){
        scanf("%d", &tmp);
        for (int j=0; j<n; j++){
            assert(q.size() == n);
            if (a[j] + tmp < q.top()){
                q.pop();
                q.push(a[j] + tmp);
            } else {
                break;
            }
        }
    }

    std::stack<int> stk;
    while (!q.empty()){
        stk.push(q.top());
        q.pop();
    }
    while (!stk.empty()){
        printf("%d ", stk.top());
        stk.pop();
    }
    printf("\n");
    return 0;
}

