#include <cstdio>
#include <cstdlib>


int main(){
    int x, t;
    scanf("%d%d", &x, &t);

    if (x==1){
        for (int i=0; i<t; i++){
            int n;
            scanf("%d", &n);
            if (n==1){
                printf("2 1\n");
                continue;
            }
            if (n%2 == 1){
                printf("0\n");
            } else {
                printf("2 ");
                for (int j=0; j<n; j++){
                    if (j%2 == 0){
                        printf("%d ", n-(j/2));
                    } else {
                        printf("%d ", (j+1)/2);
                    }
                }
            }
            printf("\n");
        }
    } else {
        // x==2
        for (int i=0; i<t; i++){
            int n;
            scanf("%d", &n);
            if (n==2){
                printf("2 1 2\n");
                continue;
            }
        }
    }
    return 0;
}

