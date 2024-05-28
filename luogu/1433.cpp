#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

constexpr int maxn = 20;
int n;
double xs[maxn], ys[maxn];

double ans = 1e10;

vector<pair<double, int>> v[maxn];
double dis(double x1, double y1, double x2, double y2){
    double dx = x2-x1;
    double dy = y2-y1;
    return sqrt(dx*dx+dy*dy);
}

bool is_visited[maxn];

// get the dis by searching the nearest
/*
void f(int from, double cur_dis){
    is_visited[from] = 1;
    for (auto&& [to_dis, to]: v[from]){
        if (is_visited[to]){
            continue;
        } else {
            f(to, cur_dis+to_dis);
            is_visited[from] = 0;
            return; 
        }
    }
    ans = min(ans, cur_dis);
    is_visited[from] = 0;
}
*/
void g(int from, double cur_dis){
    if (cur_dis >= ans) return;
    is_visited[from] = 1;
    bool all_visited = true;
    // vector<pair<double, int>> cv = v[from];
    // breakpoint here
    // std::shuffle(cv.begin(), cv.end(), rand);
    for (auto&& [to_dis, to]: v[from]){
        if (is_visited[to]){
            continue;
        } else {
            all_visited = false;
            g(to, cur_dis+to_dis);
        }
    } 
    if (all_visited){
        ans = min(cur_dis, ans);   
    }
    is_visited[from] = 0;
    return;
}


int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        scanf("%lf%lf", xs+i, ys+i);
        for (int j=0; j<i; j++){
            double d = dis(xs[i], ys[i], xs[j], ys[j]);
            v[i].push_back(make_pair(d, j));
            v[j].push_back(make_pair(d, i));
        }
    }

    for (int i=0; i<=n; i++){
        std::sort(v[i].begin(), v[i].end());
    }
    
    //f(0, 0);
    g(0, 0);
    printf("%.2f\n", ans);
    return 0;
}