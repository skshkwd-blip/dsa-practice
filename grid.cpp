// Problem: Find Missing and Repeated Values

#include <iostream>
#include <vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid){
        vector<int> ans;
        unordered_set<int> s;
        int n = grid.size();
        int a,b;
        int expSum = 0, actSum = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                actSum += grid[i][j];

                if(s.find(grid[i][j]) != s.end()){
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }

        expSum = (n * n) * (n * n + 1) /2;
        b = expSum + a - actSum;
        ans.push_back(b);

        return ans;
    }
    
};

int main() {
    vector<vector<int>> grid = {{9,1,7},{8,9,2},{3,4,6}};
    
    Solution sol;
    vector<int> result = sol.findMissingAndRepeatedValues(grid);
    
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    
    return 0;
}
