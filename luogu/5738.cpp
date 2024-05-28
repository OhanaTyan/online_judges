#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    double max_point = 0;
    while (n--){
        double points = 0;
        int min = 0x3f3f3f3f;
        int max = 0;

        for (int i=0; i<m; i++){
           int tmp;
           scanf("%d", &tmp);
           points += tmp;
           min = min<tmp?min:tmp;
           max = max>tmp?max:tmp;
        }

        points -= min;
        points -= max; 
        points /= (m-2);
        max_point = max_point>points?max_point:points;
    }

    printf("%.2f", max_point);
}