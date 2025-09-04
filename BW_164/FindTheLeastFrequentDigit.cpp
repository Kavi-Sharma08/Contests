#include<bits/stdc++.h>
using namespace std;

int solve(int n ){
    unordered_map<int,int> freq;
    int num = n;
    while(num != 0){
        int remainder = num%10;
        freq[remainder]++;
        num = num/10;

    }
    int minimumFreq = INT_MAX;
    int leastFreqDigit = -1;
    for(auto itr : freq){
        if(itr.second < minimumFreq){
            minimumFreq = itr.second;
            leastFreqDigit = itr.first;
        }
        if(itr.second == minimumFreq){
            if(itr.first < leastFreqDigit){
                leastFreqDigit = itr.first;
            }

        }
        

    }
    return leastFreqDigit;
}
int main(){
    int n ;
    cout<<"Enter the Number ";
    cin>>n;
    cout<<"Least Frequent Digit is "<<solve(n);

    

}