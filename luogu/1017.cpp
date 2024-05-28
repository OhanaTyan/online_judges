#include <cstdio>
#include <cstdlib>

char mp[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int a[40];
int main(){
    int n, r;

    scanf("%d%d", &n, &r);
    int nn = n;

    if (n==0){
        printf("0=0(base%d)\n", r);
        return 0;
    }

    r = -r;
    int r2 = r*r;
    int i;
    if (n>0){
        a[0] = n%r;
        n /= r;

        for (i=1; n; i+=2){
            int b = n%r2;
            n /= r2;
            if (b%r == 0){
                a[i+1] = b/r;
            } else {
                a[i+1] = b/r+1;
                if (a[i+1] == r){
                    n++;
                    a[i+1] = 0;
                }
                a[i] = r-b%r;
            }
        }
        printf("%d=", nn);
        for (i--; i>=0; i--){
            putchar(mp[a[i]]); 
        }
        printf("(base-%d)\n", r);
    } else {
        n = -n;
        for (i=0; n; i+=2){
            int b = n%r2;
            n /= r2;
            if (b%r == 0){
                a[i+1] = b/r;
            } else {
                a[i+1] = b/r+1;
                if (a[i+1] == r){
                    n++;
                    a[i+1] = 0;
                }
                a[i] = r-b%r;
            }
        }
        printf("%d=", nn);
        for (i--; i>=0; i--){
            putchar(mp[a[i]]);
        }
        printf("(base-%d)\n", r);
    }

    return 0;
}