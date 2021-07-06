/**
 * @see 字符串 双指针 https://leetcode-cn.com/problems/3sum/
 */

#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1])continue;
        for (int j = i + 1, k = nums.size() - 1; j < k; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1])continue;
            while (j < k - 1 && nums[i]+nums[j]+nums[k-1] >= 0)k--;
            if (nums[i] + nums[j] + nums[k]== 0) {
                res.push_back({nums[i], nums[j], nums[k]});
            }

        }
    }
    return res;
}

int main(){

    vector<int> arr = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSum(arr);


}