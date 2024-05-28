/*
 * @lc app=leetcode.cn id=1535 lang=cpp
 * @lcpr version=30202
 *
 * [1535] 找出数组游戏的赢家
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start

#include <list>

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        std::list<int> l;
        int n = arr.size();
        for (auto i: arr){
            l.push_back(i);
        }
        int i=0;

        while (i < min(k, n+10)){
            int front = l.front();
            l.pop_front();
            int second = l.front();
            l.pop_front();
            if (front > second){
                l.push_front(front);
                l.push_back(second);
                i++;
            } else {
                l.push_front(second);
                l.push_back(front);
                i = 1;
            }
        }

        return l.front();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3,5,4,6,7]\n2\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n10\n
// @lcpr case=end

// @lcpr case=start
// [1,9,8,2,3,7,6,4,5]\n7\n
// @lcpr case=end

// @lcpr case=start
// [1,11,22,33,44,55,66,77,88,99]\n1000000000\n
// @lcpr case=end

 */

