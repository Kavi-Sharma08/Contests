#include<bits/stdc++.h>
using namespace std;

// Recursive Code
int helper(vector<vector<int>> &grid , int m , int n , int i , int j , int &count , int dir){
    if(i == m-1 && j == n-1){
        return 1;
    }
    if(i >= m || j >= n){
        return 0;
    }
    int right = 0 ;
    int down = 0;
    if(grid[i][j]==1){
        if(dir == 0){
            right = helper(grid , m , n , i+1 , j , count , 1 );

        }
        else if(dir == 1){
            down = helper(grid , m , n , i , j+1 , count , 0);
        }
    }
    else{
        
        right = helper(grid , m , n , i , j+1 , count , 0);
        down = helper(grid , m , n , i+1 , j , count , 1);

    }
    return (right+down);

}
int main(){
    vector<vector<int>> grid = {
        {0,1,1},
        {1,1,0},
    };
    int m = grid.size();
    int n = grid[0].size();
    int count = 0 ;
    int dir = -1;
    cout<<helper(grid , m , n , 0 , 0 , count , dir);

}