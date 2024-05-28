#include <cstdio>
#include <cstdlib>
// #include <algorithm>

constexpr int maxi = 2010;

int a[maxi][maxi]; // a[i][j] = C(i, j) mod k
int b[maxi][maxi];

int main(){
    int t, k;
    scanf("%d%d", &t, &k);

    for (int i=0; i<maxi; i++){
        a[i][0] = a[i][i] = 1;
    }
    for (int i=2; i<maxi; i++){
        for (int j=1; j<=i; j++){
            a[i][j] = a[i-1][j-1] + a[i-1][j];
            a[i][j] %= k;
        }
        for (int j=1; j<maxi; j++){
            b[i][j] = b[i-1][j] + b[i][j-1] - b[i-1][j-1];
            if (j<i && a[i][j] == 0){
                b[i][j] += 1;
            }  
        }
    }

    while (t--){
        int n, m;
        scanf("%d%d", &n, &m);
        if (m>n) m = n;
        printf("%d\n", b[n][m]);
    }

    return 0;
}

