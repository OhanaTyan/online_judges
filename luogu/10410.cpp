#include <cstdio>
#include <cstdlib>
#include <cmath>

int main(){
    double l, r, x1, y1, x2, y2, x3, y3;
    double q; // q for p given in question
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &l, &r, &x1, &y1, &x2, &y2, &x3, &y3);
    if (l>0.5){
        q = 1-l;
    }  else if (r < 0.5){
        q = r;
    } else {
        q = 0.5;
    }
    double ans = 0;
    double a = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    double b = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
    double c = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
    double p = (a+b+c)/2;
    double s = sqrt(p*(p-a)*(p-b)*(p-c));
    ans = s*(1-3.0*q*(1-q));
    printf("%f\n", ans);
    return 0;
}