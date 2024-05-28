#include <cstdio>
#include <cstdlib>

int main(){
    int a, b, cur_max=0, max_idx=0;
    bool is_solution_exist = false;
    for (int i=0; i<7; i++){
        scanf("%d%d", &a, &b);
        // 如果不对就改成 >=
        if (a+b > 8){
            is_solution_exist = true;
            if (a+b > cur_max){
                max_idx = i+1;
                cur_max = a+b;
            }
        }
    }

    if (is_solution_exist){
        printf("%d\n", max_idx);
    } else {
        printf("0\n");
    }
    
}