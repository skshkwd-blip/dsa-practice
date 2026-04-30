#include <iostream>
#include <vector> // include vector header
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int val : nums) {  // use correct variable name: nums
            ans ^= val;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {2, 3, 2, 4, 4}; // only 3 is non-repeating

    cout << "The single (non-repeating) number is: " << sol.singleNumber(arr) << endl;

    return 0;
}
