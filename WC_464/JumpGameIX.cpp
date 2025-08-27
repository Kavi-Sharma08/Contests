#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums){
    int n = nums.size();

    vector<int> prefix(n) , suffix(n) , res(n);
    prefix[0] = nums[0];
    suffix[n-1] = nums[n-1];

    // Storing max values from the left index
    for(int i = 1 ; i < n ; i++){
        prefix[i] = max(nums[i] , prefix[i-1]);
    }

    // Storing min values from the right index
    for(int i = n-2 ; i >=0 ;i--){
        suffix[i] = min(nums[i] , suffix[i+1]);
    }

    res[n-1] = prefix[n-1];

    for(int i = n-2 ; i>=0 ; i--){
        res[i] = prefix[i];
        if(prefix[i] > suffix[i+1]){  /**But, if prefix[i] > suffix[i+1], 
                                       this means there exists a smaller value to the right (suffix[i+1]) that you can jump down to.**/
            res[i] = res[i+1];
        }
    }
    return res;

}
int main(){
    vector<int> nums = {2,3,1};
    solve(nums);

}


// class Solution {
// public:
//     vector<int> maxValue(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> pre(n), suff(n), res(n);

//         pre[0] = nums[0], suff[n - 1] = nums[n - 1];
//         for (int i = 1; i < n; i++) {
//             pre[i] = max(nums[i], pre[i - 1]);
//         }

//         for (int i = n - 2; i >= 0; i--) {
//             suff[i] = min(nums[i], suff[i + 1]);
//         }

//         res[n - 1] = pre[n - 1];

//         for (int i = n - 2; i >= 0; i--) {
//             res[i] = pre[i];
//             if (pre[i] > suff[i + 1]) {
//                 res[i] = res[i + 1];
//             }
//             // res[i] = (pre[i] > suff[i + 1])? res[i+1] : pre[i];
//         }
//         return res;
//     }
// };