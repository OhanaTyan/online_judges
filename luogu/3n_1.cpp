#include <stdio.h>
#include <stdlib.h>

int f(int x){
    int i=0;
    while (1){
        i++;
        if (x==1){
            return i;
        }
        if (x%2==0){
            x/=2;
        } else {
            x = 3*x+1;
        }
    }
}

int a[10010];


int main(){
    for (int i=1; i<=10000; i++){
        a[i] = f(i);
    }
    while (1){
        int i, j;
        scanf("%d%d", &i, &j);
        int result = 0;
        for (int k=i; k<=j; k++){
            result = __max(result, a[k]);
        }
        printf("%d %d %d\n", i, j, result);
    }
    return 0;
}