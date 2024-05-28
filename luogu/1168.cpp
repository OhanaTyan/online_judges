#include <cstdio>
#include <cstdlib>
#include <queue>
#include <ctime>
#include <cassert>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    // little top
    priority_queue<int, vector<int>, greater<int>> q1;
    // big top 
    priority_queue<int, vector<int>, less<int>> q2;
    int a;
    scanf("%d", &a);
    q1.push(a);
    printf("%d\n", a);
    for (int i=2; i<n; i+=2){
        int a, b;
        scanf("%d%d", &a, &b);
        q1.push(a);
        q2.push(b);
        assert(q1.size() == q2.size()+1);
        while (q1.top() < q2.top()){
            a = q1.top();
            q1.pop();
            b = q2.top();
            q2.pop();
            q1.push(b);
            q2.push(a);
        }
        printf("%d\n", q1.top());
    }

    return 0;
}

