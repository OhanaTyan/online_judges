/*
 * @lc app=leetcode.cn id=2244 lang=cpp
 * @lcpr version=30201
 *
 * [2244] 完成所有任务需要的最少轮数
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
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        std::unordered_map<int, int> mp;
        for (auto i: tasks){
            mp[i] += 1;
        }

        int ans = 0;
        for (auto&& [k, v]: mp){
            if (v==1){
                return -1;
            } 
            if (v%3 == 0){
                ans += v/3;
            } else if (v%3 == 1){
                ans += 2;
                v -= 4;
                ans += v/3;
            } else if (v%3 == 2){
                ans += v/3 + 1;
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,3,3,2,4,4,4,4,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,3]\n
// @lcpr case=end

 */

