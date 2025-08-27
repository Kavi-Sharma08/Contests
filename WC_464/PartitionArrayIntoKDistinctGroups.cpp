#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> &nums , int k){
    int n = nums.size();

    if(n % k != 0){
        return false;
    }

    unordered_map<int , int> freq;

    for(int i = 0 ; i < n ; i++){
        
        freq[nums[i]]++;

        if(freq[nums[i]] > n/k){
            return false;
        }
    }
    return true;



}
int main(){
    vector<int> nums = {3,5,2,2};
    int k = 2;
    cout<<solve(nums , k);
}
