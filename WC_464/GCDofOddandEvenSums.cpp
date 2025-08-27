#include<bits/stdc++.h>
using namespace std;

// Sum of first n natural numbers formula  = n/2*(2a + (n-1)*d)

// For OddSums put a = 1 , d = 2 -> n^2; // it is always smaller than the Even numbers

// For EvenSum put a = 2 , d = 2 -> n*(n+1)  

// Constraints (1 <= n <= 10​​​​​​​00)

int gcd(int n , int a , int b){
    while(b !=0){
        int remainder = a%b;
        a = b;
        b = remainder;
    }
    return a;
    
}

int gcd(int n){
    return n;    
}


// Greatest common between n*n and n*(n+1) is n
//   if we took the value n = 7  =>   7*7 and 7*(7+1) => 7*gcd(7 , 8 ) => 7*1 => 7


// ** Consecutive numbers are always co primes they have 1 as GCD

int main(){
    cout<<"Enter value of n = ";
    int n;
    cin>>n;

    int sumOfEvenNumbers = n*(n+1);
    int sumOfOddNumbers = n*n;

    cout<<gcd(n , sumOfEvenNumbers , sumOfOddNumbers);
    

}