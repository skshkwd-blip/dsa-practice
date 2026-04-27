// Problem: Container With Most Water
// Approach: Brute Force

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {//time complexity= O(n^2)
        int maxWater = 0;//ans
        int w, ht, currWater;
        
        for(int i=0;i<height.size();i++) {
            for(int j=i+1; j<height.size();j++){
                w=j-i;
                ht= min(height[i],height[j]);
                currWater = w * ht;
                maxWater = max(maxWater,currWater);

            }
        }
        return maxWater;
    }
};

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};  // Example input
    Solution sol;
    int result = sol.maxArea(height);

    cout << "maximum amount of water that container can store = " << result << endl;

    return 0;
}
