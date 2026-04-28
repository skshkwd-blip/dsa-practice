#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> arr) {//Iterative code
    int st=1,end=arr.size()-2;//as (st,end)!=peak value
    while(st <= end){
        int mid = st +(end - st) / 2;//optimized formula

        if(arr[mid-1] < arr[mid] && arr[mid]>arr[mid+1]){
            return mid;
        } else if(arr[mid-1]<arr[mid]) {
            st = mid+1;
        } else{
            end=mid-1;
        }
        
    }
    return -1;

}

int main() {
    vector<int> arr={0,3,8,9,5,2};
    int tar = 0;

    cout << "peak element is at index : " << binarySearch(arr) << endl;

    return 0;
}