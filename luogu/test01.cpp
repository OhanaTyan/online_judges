#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector<int> a = {2, 4, 6, 8, 10};
    auto iter = a.begin()+2;
    cout << iter - a.begin() << endl;
}