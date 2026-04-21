//BY RECURSION
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void getPermute(vector<int>& nums, int idx, vector<vector<int>>& ans){
        if(idx == nums.size()){
            ans.push_back({nums});
            return;
        }
        for(int i=idx; i<nums.size(); i++){
            swap(nums[idx], nums[i]);
            getPermute(nums,idx+1,ans);

            swap(nums[idx], nums[i]);//backtracking
        }
    }
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> ans;
        getPermute(nums,0,ans);
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution sol;
    vector<vector<int>> result = sol.permute(nums);

    // Print all permutations
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}