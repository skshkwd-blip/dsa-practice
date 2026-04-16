// Problem: Painter's Partition Problem
// Approach: Binary Search + Greedy

#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int> &arr, int n, int m,int maxAllowedTime){//O(n)
    int painter = 1, time = 0;
    for(int i=0;i<n;i++){
        if (arr[i] > maxAllowedTime){
            return false;
        }

        if(time+arr[i] <= maxAllowedTime){
            time += arr[i];
        } else{
            painter++;
            time = arr[i];
        }
    }
    return painter > m ? false : true;
}

int painterPartition(vector<int> &arr, int n, int m) {//O(logN * n)
    if(m > n){
        return -1;
    }
    int sum = 0,maxVal=INT_MIN;
    for(int i=0;i<n;i++) {//O(n)
        sum += arr[i];
        maxVal=max(maxVal,arr[i]);
    }
    int ans = -1;
    int st = maxVal, end = sum;//range of possible ans

    while(st <= end){//O(logN)
        int mid = st + (end - st) / 2;

        if(isValid(arr,n,m,mid)){
            ans = mid;
            end=mid-1;
        } else {
            st = mid +1;
        }
    }
    return ans;
}
int main () {
    vector<int> arr = {40,30,10,20,60,80,20};
    int n = 7,m = 3;

    cout << painterPartition(arr,n,m) << endl;

    return 0;
}
