#include <cstdio>
#include <cstdlib>

int a[128];
int b[128];

int main(){
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", a+i);
    }
    int ans = 0;
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            for (int k=0; k<n; k++){
                if (a[i]+a[j]==a[k]){
                    b[k]++;
                }
            }
        }
    }
    for (int i=0; i<n; i++){
        if (b[i]){
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}