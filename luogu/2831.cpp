#include <cstdio>
#include <cstdlib>
#include <cmath>

int main(){
    int t;
    scanf("%d", &t);

    while (t--){
        int n, m;
        scanf("%d%d", &n, &m);
        double xs[20], ys[20];
        bool is_shooted[20]; 
        int ans = 0;
        for (int i=0; i<n; i++){
            scanf("%lf%lf", xs+i, ys+i);
            is_shooted[i] = false;
        }

        for (int i=0; i<n-2; i++){
            for (int j=i+1; j<n-1; j++){
                double  x1=xs[i], y1=ys[i],
                        x2=xs[j], y2=ys[j];
                double m = x1*x2*(x2-x1);
                double a = -(y1*x2-y2*x1)/m;
                if (a>=0){
                    continue;
                }
                double b = (y1*x2*x2-y2*x1*x1)/m;
                for (int k=i+2; k<n; k++){
                    double x = xs[i];
                    double yy = a*x*x+b*x;
                    double y = ys[i];

                    if (fabs(yy-y) < 1e-5){
                        is_shooted[k] = true;
                        if (is_shooted[i] && is_shooted[j]){
                            // do nothing
                        } else {
                            ans++;
                            is_shooted[i] = is_shooted[j] = true;
                        }
                    }
                }
            }
        }

        ans += (not_shooted + 1)/2;
        printf("%d\n", ans);
    }
    
    return 0;
}
