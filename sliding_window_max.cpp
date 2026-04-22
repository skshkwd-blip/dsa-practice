// Problem: Sliding Window Maximum (LeetCode 239)

#include<iostream>
#include<vector>
#include<queue>
#include<deque> 
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;

        //for first window
        for(int i=0; i<k; i++){
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for(int i=k; i<nums.size(); i++){
            result.push_back(nums[dq.front()]);

            while(dq.size() > 0 && dq.front() <= i-k){
                dq.pop_front();
            }

            while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        result.push_back(nums[dq.front()]);

        return result;
    }
};

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    Solution sol;

    vector<int> s = sol.maxSlidingWindow(nums,k);

    for(int val : s){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}