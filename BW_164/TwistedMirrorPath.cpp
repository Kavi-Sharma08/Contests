#include<bits/stdc++.h>
using namespace std;

// Recursive Code
void helper(vector<vector<int>> &grid , int m , int n , int i , int j , int &count , int dir){
    if(i == m-1 && j == n-1){
        count++;
        return;
    }
    if(i >= m || j >= n){
        return ;
    }
    if(grid[i][j]==1){
        if(dir == 0){
            helper(grid , m , n , i+1 , j , count , 1 );

        }
        else if(dir == 1){
            helper(grid , m , n , i , j+1 , count , 0);
        }
    }
    else{
        
        helper(grid , m , n , i , j+1 , count , 0);
        helper(grid , m , n , i+1 , j , count , 1);

    }

    
   
    

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
    helper(grid , m , n , 0 , 0 , count , dir);
    cout<<count;

}