#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>

double pow(double a, int n){
    double ans = 1;
    double tmp = a;
    while (n){
        if (n&1)    ans *= tmp;
        tmp *= tmp;
        n /= 2;
    }
    return ans;
}

using namespace std;

int main(){
    long long n;
    long long x;
    scanf("%lld%lld", &x, &n);
    if (x == 2){
        if (n==1)   printf("0\n");
        else if (n==2)  printf("1\n");
        else printf("inf\n");
        return 0;
    }
    // x >= 3 then x*x >= 9
    if (n==1){
        printf("0\n");
        return 0;
    } else if (n==2||n==3){
        printf("1\n");
        return 0;
    }

    long double lnx = log(((long double) x) * x);
    long double ln2 = log((long double) 2);
    long double dans = log(
        (long double)(n-2) * ln2 /(lnx - 2*log(2))
    ) / ln2 + 1e-5;

    printf("%lld\n", (long long)dans + 2);
    // cout << ((__int128) ans + 2) << endl;
    return 0;

}