#include<bits/stdc++.h>
using namespace std;

// Recursive Code
// int helper(vector<vector<int>> &grid , int m , int n , int i , int j , int &count , int dir){
//     if(i == m-1 && j == n-1){
//         return 1;
//     }
//     if(i >= m || j >= n){
//         return 0;
//     }
//     int right = 0 ;
//     int down = 0;
//     if(grid[i][j]==1){
//         if(dir == 0){
//             right = helper(grid , m , n , i+1 , j , count , 1 );

//         }
//         else if(dir == 1){
//             down = helper(grid , m , n , i , j+1 , count , 0);
//         }
//     }
//     else{
        
//         right = helper(grid , m , n , i , j+1 , count , 0);
//         down = helper(grid , m , n , i+1 , j , count , 1);

//     }
//     return (right+down);

// }


//************************************************************************************************************* */
// if we are at the mirror cell then if dir = 0 it means it comes from the right and it need to move down
// if we are ar the mirror cell then if dir = 1 it means it comes from the upper cell and it need to move right 
int MOD = 1e9+7;
int helper(vector<vector<int>> &grid , int m , int n , int i , int j , int dir ,  vector<vector<vector<int>>> &dp){
    if(i >= m || j >=n){
        return 0;
    }
    if(i==m-1 && j==n-1){
        return 1;
    }
    if(dp[i][j][dir] != -1){
        return dp[i][j][dir];
    }

    if(grid[i][j]==1){
        if(dir == 0){
            return dp[i][j][dir] = helper(grid ,  m , n , i+1 , j , 1 , dp);

        }
        if(dir == 1){
            return dp[i][j][dir] =  helper(grid , m , n , i , j+1 , 0 , dp);
        }
    }

    int right = helper(grid , m , n , i , j+1 , 0 , dp);
    int down = helper(grid , m , n , i+1 , j , 1 , dp);
    return dp[i][j][dir] = (right + down)%MOD;


}
int main(){
    vector<vector<int>> grid = {
        {0,1,0},
        {0,0,1},
        {1,0,0}
    };
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> dp(m , vector<vector<int>>(n , vector<int> (3,-1)));
    int dir = 2; // do not use negative index it will give out of bound use 0,1,2 only because 0 amd 1 are occupied use 2 because the inner most vector has 3 index value only
    cout<<helper(grid , m , n , 0 , 0 , dir ,dp);

}