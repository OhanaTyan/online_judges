/*
 * @lc app=leetcode.cn id=2903 lang=cpp
 * @lcpr version=30202
 *
 * [2903] 找出满足差值条件的下标 I
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
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (abs(i-j) >= indexDifference){
                    if (abs(nums[i]-nums[j]) >= valueDifference){
                        return vector<int>({i, j});
                    }
                }
            }
        }
        return vector<int>({-1, -1});
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,1,4,1]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n0\n0\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n2\n4\n
// @lcpr case=end

 */

