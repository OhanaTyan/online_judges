#include <cstdio>
#include <cstdlib>

int a[20];
int n;
int result_count = 0;

void f(int depth){
    if (depth == n){
        if (result_count < 3){
            for (int i=0; i<n; i++){
                printf("%d ", a[i]+1);
            }
            printf("\n");
        }
        result_count++;
        return;
    }
    for (int i=0; i<n; i++){
        bool is_ok = true;
        for (int j=0; j<depth; j++){
            if (i==a[j]){
                is_ok = false;
                break;
            }
            if (abs(depth-j) == abs(i-a[j])){
                is_ok = false;
                break;
            }
        }
        if (!is_ok) {
            continue;
        }
        a[depth] = i;
        f(depth+1);
        a[depth] = 0;
    }
}

int main(){
    scanf("%d", &n);
    f(0);
    printf("%d\n", result_count);
}