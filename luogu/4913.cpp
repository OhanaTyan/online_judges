#include <cstdio>
#include <cstdlib>
#include <queue>
constexpr int maxn = 1000010;

int left[maxn], right[maxn];

int ans = 0;


int main(){
    int n;
    scanf("%d", &n);

    for (int i=1; i<=n; i++){
        scanf("%d%d", left+i, right+i);
    }

    std::queue<int> q1, q2;
    q1.push(1);

    while (!q1.empty()){
        ans++;
        while (!q1.empty()){
            int cur = q1.front();
            q1.pop();
            if (left[cur]){
                q2.push(left[cur]);
            }
            if (right[cur]){
                q2.push(right[cur]);
            }
        }
        q1.swap(q2);
    }

    printf("%d\n", ans);
}

