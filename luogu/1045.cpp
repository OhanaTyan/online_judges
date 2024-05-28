#include <cstdio>
#include <cstdlib>
#include <cmath>

// #define DEBUG

int a[1000];
int b[30][1000];

void f(int p, int depth){
    int c[1024];
    for (int i=0; i<1024; i++){
        c[i] = 0;
    }
    if (p==0){
        return;
    }
    if (depth == 0){
        b[depth][0] = 2;
    } else {
        for (int i=0; i<500; i++){
            c[i] = b[depth-1][i];
        }
        for (int i=0; i<500; i++){
            for (int j=0; j<500; j++){
                b[depth][i+j] += b[depth-1][i] * c[j];
            }
        }
        for (int i=0; i<500; i++){
            b[depth][i+1] += b[depth][i] / 10;
            b[depth][i] %= 10;
        }
    }

    if (p&1){
#ifdef DEBUG
        printf("1");
#endif
        for (int i=0; i<500; i++){
            c[i] = a[i];
            a[i] = 0;
        }
        for (int i=0; i<500; i++){
            for (int j=0; j<500; j++){
                a[i+j] += b[depth][i] * c[j];
            }
        }
        for (int i=0; i<500; i++){
            a[i+1] += a[i]/10;
            a[i] %= 10;
        }
    } else {
#ifdef DEBUG
        printf("0");
#endif
    }
    f(p/2, depth+1);
}

int main(){
    int p;
    scanf("%d", &p);
    /*for (int i=0; i<100000; i++){
        printf("%d\n", int(log10(2)*i)+1);
    }*/
    // 打表验证成立
    printf("%d", int(log10(2)*p)+1);
    a[0] = 1;
    f(p, 0);
    a[0] -= 1;

#ifdef DEBUG
    printf("\n");
#endif
    for (int i=0; i<500; i++){
        a[i+1] += a[i] / 10;
        a[i] %= 10;
    }

    for (int i=499; i>=0; i--){
        if (i%50 == 49){
            printf("\n");
        }
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}

