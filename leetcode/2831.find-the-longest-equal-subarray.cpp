/*
 * @lc app=leetcode.cn id=2831 lang=cpp
 * @lcpr version=30202
 *
 * [2831] 找出最长等值子数组
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
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> v(n+1);
        for (int i=0; i<n; i++){
            v[nums[i]].push_back(i);
        }
        int ans = 1;
        for (int i=1; i<=n; i++){
            vector<int>& vv = v[i];
            if (vv.size() <= 1){
                continue;
            }
            int m = vv.size();
            int l=0, r=1;
            while (r<m && l<=r){
                if (l==r) {
                    r++;
                    continue;
                }
                int diff = vv[r]-vv[l]-(r-l) ;
                if (diff <= k){
                    ans = max(ans, r-l+1);
                    r++;
                } else {
                    l++;
                }
            }
        }
        return ans;   
    }
};
// @lc code=end

int main(){
    vector<int> v;
    v = {1, 3, 2, 3, 1, 3};
    cout << Solution().longestEqualSubarray(v, 3) << endl;
    v = {1, 1, 2, 2, 1, 1};
    cout << Solution().longestEqualSubarray(v, 2) << endl;
}


/*
// @lcpr case=start
// [1,3,2,3,1,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,2,1,1]\n2\n
// @lcpr case=end

 */

