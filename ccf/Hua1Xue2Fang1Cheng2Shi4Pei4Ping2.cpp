#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <cassert>
#include <vector>

using namespace std;

bool is_digit(char c){
    return c>='0'&&c<='9';
}

bool is_zero(double a){
    return a>=-1e-5 && a<=1e-5;
}

vector<double> operator*(const vector<double>&v, const double a){
    int n = v.size();
    vector<double> ans(n);
    for (int i=0; i<n; i++){
        ans[i] = v[i]*a;
    }
    return ans;
}

vector<double> operator*(double a, const vector<double>& v){
    return v*a;
}

vector<double> operator/(const vector<double>& v, double a){
    return v*(1/a);
}

vector<double> operator+(const vector<double>& v1, const vector<double>& v2){
    int n = v1.size();
    assert(v1.size() == v2.size());
    vector<double> v(n);
    for (int i=0; i<n; i++){
        v[i] = v1[i] + v2[i];
    }
    return v;
}

vector<double> operator-(const vector<double>& v){
    int n=v.size();
    vector<double> ans(n);
    for (int i=0; i<n; i++){
        ans[i] = -v[i];
    }
    return ans;
}

vector<double> operator-(const vector<double>& v1, const vector<double>& v2){
    return v1 + (-v2);
}

vector<double>& operator-=(vector<double>& v1, const vector<double>& v2){
    v1 = v1-v2;
    return v1;
}

void f(){
    int n;
    cin >> n;
    // genso -> index
    unordered_map<string, int> mp;
    vector<vector<double>> matrix;
    for (int i=0; i<n; i++){
        string s;
        cin >> s;
        string genso;
        int k = 0;
        for (char c: s){
            if (is_digit(c)){
                // check genso in mp;
                if (mp.find(genso) == mp.end()){
                    // add new genso to mp
                    mp[genso] = mp.size();
                    // add new genso to matrix
                    matrix.push_back(vector<double>(n));
                }
                k *= 10;
                k += c-'0';
            } else {
                if (k!=0){
                    matrix[mp[genso]][i] = k;
                    k = 0;
                    genso = "";
                }
                genso.push_back(c);
            }
        }
        // a genso is left here
        if (mp.find(genso) == mp.end()){
            mp[genso] = mp.size();
            matrix.push_back(vector<double>(n));
        }
        matrix[mp[genso]][i] = k;
    }

    // we get the matrix here, then we should thech
    // the rank of it
    // the correctness of the matrix have been tested

    int m = matrix.size();
    // the sub_matrix is from [ii....][jj....]
    int ii=0, jj=0;
    while (ii<m && jj<n){
        bool is_all_zero = true;
        for (int i=ii; i<m; i++){
            if (is_zero(matrix[i][jj])){
                continue;
            } else {
                is_all_zero = false;
                break;
            }
        }
        if (is_all_zero){
            jj++;
            continue;
        }
        if (is_zero(matrix[ii][jj])){
            for (int i = ii+1; i<m; i++){
                if (!is_zero(matrix[i][jj])){
                    std::swap(matrix[i], matrix[ii]);
                    break;
                }
            }
        }
        for (int i=ii+1; i<m; i++){
            matrix[i] -= matrix[ii]*(matrix[i][jj]/matrix[ii][jj]);
        }
        ii++;
        jj++;
    }
    int i;
    for (i=0; i<m; i++){
        bool is_all_zero = true;
        for (int j=0; j<n; j++){
            if (is_zero(matrix[i][j])){
                continue;
            } else {
                is_all_zero = false;
                break;
            }
        }
        if (is_all_zero==true){
            break;
        }
    }
    // then we can know that rank(matrix) is i
    if (i<n){
        printf("Y\n");
    } else {
        printf("N\n");
    }

    return;
}


int main(){
    int n;
    cin >> n;
    while (n--){
        f();
    }
}