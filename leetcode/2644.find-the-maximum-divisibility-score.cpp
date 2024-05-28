/*
 * @lc app=leetcode.cn id=2644 lang=cpp
 * @lcpr version=30202
 *
 * [2644] 找出可整除性得分最大的整数
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
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int n=nums.size(), m = divisors.size();
        int ans = 0x3f3f3f3f;
        int max_cnt = -1;
        for (int j=0; j<m; j++){
            int cnt = 0;
            for (int i=0; i<n; i++){
                if (nums[i] % divisors[j] == 0){
                    cnt ++;
                }
            }
            if (cnt > max_cnt){
                ans = divisors[j];
                max_cnt = cnt;
            } else if (cnt == max_cnt){
                ans = min(ans, divisors[j]);
            }
        }

        return ans;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,7,9,3,9]\n[5,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [20,14,21,10]\n[5,7,5]\n
// @lcpr case=end

// @lcpr case=start
// [12]\n[10,16]\n
// @lcpr case=end

 */

