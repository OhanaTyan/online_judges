#include <cstdio>
#include <cstdlib>

int main(){
    int n;
    int ans=0;
    scanf("%d", &n);
    while (n--){
        int tmp;
        scanf("%d", &tmp);
        ans ^= tmp;
    }
    printf("%d\n", ans);
    return 0;
}