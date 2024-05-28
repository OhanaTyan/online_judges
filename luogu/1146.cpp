#include <cstdio>
#include <cstdlib>

int main(){
    int n;
    scanf("%d", &n);
    int a[110] = {0};
    printf("%d\n", n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i!=j) {
                a[j] = 1-a[j];
            }
            printf("%d", a[j]);
        }
        printf("\n");
    }
    return 0;
}