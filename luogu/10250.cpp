#include <cstdio>
#include <cstdlib>

long long a[100];

int main(){
    int n;
    scanf("%d", &n);

    a[1] = 1;
    a[2] = 2;
    a[3] = 4; //1,1,1; 1,2; 2,1; 3

    for (int i=4; i<=n; i++){
        a[i] = a[i-1]+a[i-2]+a[i-3];
    }
//    return a[n];
    printf("%lld\n", a[n]);
}