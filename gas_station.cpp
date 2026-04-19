// Problem: Gas Station (LeetCode)
// Approach: Greedy

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;

        for(int val : gas){
            totalGas += val; 
        }

        for(int val : cost){
            totalCost += val;
        }

        if(totalGas < totalCost){
            return -1;
        }

        int start = 0, currGas = 0;

        for(int i=0; i<gas.size(); i++){
            currGas = (gas[i] - cost[i]);

            if(currGas < 0){
                start = i+1;
                currGas = 0;
            }
        }

        return start;
    }
};

int main(){
    vector<int> gas = {1,2,4,5,9};
    vector<int> cost = {3,4,1,10,1};

    Solution sol;
    int result = sol.canCompleteCircuit(gas,cost);

    cout << "Starting idx of tour : " << result << endl;

    return 0;
}