#include <cstdio>
#include <cstdlib>
#include <algorithm>

constexpr int maxm = 5010;

class milk{
public:
    int p, a;
};

milk milks[maxm];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++){
        scanf("%d%d", &milks[i].p, &milks[i].a);
    }

    std::sort(
        milks, 
        milks+m,
        [](milk &a, milk&b){
            if (a.p<b.p){
                return true;
            } else if (a.p>b.p){
                return false;
            } else {
                return a.a < b.a;
            }
        }
    );

    int result = 0;
    for (int i=0; i<m; i++){
        if (n > milks[i].a){
            n -= milks[i].a;
            result += milks[i].a * milks[i].p;
        } else {
            result += n * milks[i].p;
            n = 0;
            break;
        }
    }
    printf("%d\n", result);
    return 0;
}