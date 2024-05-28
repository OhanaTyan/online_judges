#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct A{
    string name;
    int birthday;
    int count;

    bool operator<(A& other){
        if (this->birthday != other.birthday){
            return this->birthday < other.birthday;
        }
        return this->count > other.count;
    }
};

A a[120];

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        a[i].count = i;
        cin >> a[i].name;
        int y, m, d;
        cin >> y >> m >> d;
        a[i].birthday = y*10000 + m * 100 + d;
    }

    std::sort(a, a+n);

    for (int i=0; i<n; i++){
        cout << a[i].name << endl;
    }

    return 0;

}




