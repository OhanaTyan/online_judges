/*
 * @lc app=leetcode.cn id=75 lang=cpp
 * @lcpr version=30201
 *
 * [75] 颜色分类
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
    void sortColors(vector<int>& nums) {
        int num0 = 0, num1 = 0, num2 = 0;
        for (auto i: nums){
            if (i==0)       num0++;
            else if (i==1)  num1++;
            else            num2++;
        }
        int i=0;
        for(int j=0; j<num0; j++){
            nums[i] = 0;
            i++;
        }
        for (int j=0; j<num1; j++){
            nums[i] = 1;
            i++;
        }
        for (int j=0; j<num2; j++){
            nums[i] = 2;
            i++;
        }
        return;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,0,2,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,0,1]\n
// @lcpr case=end

 */

