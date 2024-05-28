#include <list>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
int last_digit(list<int> array){
    if (array.size() == 0){
        return 1;
    } else if (array.size() == 1){
        return array.front()%10;
    } 
    

    int lower = 0;
    int b = array.back();
    int a;
    array.pop_back();
    lower = b;

    while (array.size() >= 2){
        a = array.back();
        array.pop_back();
        // try to get (a**b)%4
        if (a==0){
            if (lower==0){
                assert(b%4==0);
                b = 1;
                lower=1;
                continue;
            } else {
                b = 0;
                lower = 0;
                continue;
            }
        }
        if (lower==0){
            assert(b==0);
            b = 1;
            lower = 1;
            continue;
        }
        switch (a%4){
        case 0:
            b = 0;
            break;
        case 1:
            b = 1;
            break;
        case 2:
            if (lower == 1){
                b = 2;
            } else {
                b = 0;
            }
            break;
        case 3:
            switch(b%2){
                case 0: b=1; break;
                case 1: b=3; break;
            }
        }
            
        lower = a;
    }

    a = array.back();
    a %= 10;

    if (lower == 0){
        return 1;
    } 
    if (a%10==0){
        return 0;
    }
    if (lower == 1){
        return a%10;
    }

    int ans = 1;
    b %= 4;
    b += 4;
    while (b--) {
        ans *= a;
        ans %= 10;
    }
    
    return ans%10;
}





int main(){


    assert(last_digit({2,2,3,2})==6);
    assert(last_digit({3,1,1})==3);
    assert(last_digit({3,1,3})==3);
    assert(last_digit({0, 0})==      1);
    assert(last_digit({0, 0, 0})==   0);
    assert(last_digit({4,0,0})==4);
    assert(last_digit({4,0,0,0})==1);
    assert(last_digit({1,2})==1);
    assert(last_digit({3,4,5})==1);
    assert(last_digit({4,3,6})==    4);
    assert(last_digit({7,6,21})==    1);
    assert(last_digit({12,30,21})==6);
    assert(last_digit({2,2,2,0})==4);
    assert(last_digit({937640,767456,981242})==0);
    assert(last_digit({123232,694022,140249})==6);
    assert(last_digit({499942,898102,846073})==6);
    assert(last_digit({7,3,2})==7);
    assert(last_digit({7,3,5})==3);
    assert(last_digit({3,2,0})==3);
    assert(last_digit({3,2,1})==9);
    assert(last_digit({7,2,0})==7);
    assert(last_digit({7,2,1})==9);
    assert(last_digit({7,2,2})==1);
    assert(last_digit({7,2,3})==1);
    assert(last_digit({3,3,0,0})==7);


    return 0;
}