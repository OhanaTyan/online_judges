#include <cstdio>
#include <cstdlib>
#include <cmath>

constexpr int maxn = 100000000;
int a[maxn];
int b[maxn];
int c[maxn];
int x, xx;

int get_min_factor(int x, int begin){
    for (int i=begin; i<=sqrt(x); i++){
        if (x%i == 0){
            return i;
        }
    }
    return x;
}

int main(){
    scanf("%d", &x);
    xx = x;

    // xx for a copy of x
    int min_factor=2, j;
    // the j_th prime number
    j=0;

    while (xx != 1){
        min_factor = get_min_factor(xx, min_factor);
        while (1){
            a[j] = min_factor;
            if (xx%min_factor==0){
                xx /= min_factor;
                b[j]++;
            } else {
                min_factor++;
                break;
            }
        }
        j++;
    }


    int n = j;

#ifdef DEBUG
    for (int i=0; i<n; i++){
        printf("%d\t%d\n", a[i], b[i]);
    }
#endif

    if (n==1){
        printf("%d\n", x);
        return 0;
    } else if (n==2){
        printf("1\n");
        return 0;
    } 
    int count1 = 0; 
    int count2 = 0;
    for (int i=1; i<n; i++){
        if (b[i] == 1)  count1++;
        else            count2++;
    }
 
    if (b[0] == 1){
       if (count2 == 0){
            if (count1%2 == 0) {
                printf("%d\n", a[0]);
            } else {
                printf("1\n");
            }
            return 0;
        } else if (count2 == 1){
            printf("1\n");
            return 0;
        } else {
           printf("1\n");
           return 0; 
        }
    }

    printf("1\n");
    return 0;
}