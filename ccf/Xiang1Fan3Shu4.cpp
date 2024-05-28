#include <cstdio>
#include <cstdlib>

constexpr int maxi = 512;
int a[maxi];
int main(){
    int n;
    int ans = 0;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", a+i);
        for (int j=0; j<i; j++){
            if (a[i] + a[j] == 0){
                ans ++; 
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}