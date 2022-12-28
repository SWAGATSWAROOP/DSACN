// Code : No. of balanced BTs
// Send Feedback
// Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
// This number can be huge, so, return output modulus 10^9 + 7.
// Write a simple recursive solution.
// Input Format :
// The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
// Output Format :
// The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
// Constraints :
// 1 <= h <= 24
// Time Limit: 1 sec
// Sample Input 1:
// 3
// Sample Output 1:
// 15
// Sample Input 2:
// 4
// Sample Output 2:
// 315

//Brute Force
# define mod 1000000007
int balancedBTs(int n) {
    if(n<=1){
        return 1;
    }

    int t1 = balancedBTs(n-1);
    int t2 = balancedBTs(n-2);

    int temp1 = (int)(((long)(t1)*t1)%mod);
    int temp2 = (int)((2*(long)(t1)*t2)%mod);

    int ans = (temp1+temp2)%mod;
    return ans;
}

//Memotization
# define mod 1000000007
#include <vector>
int b(int n,vector<int> a){
  if (n <= 1) {
    return 1;
  }

    int t1,t2;
    if (a[n - 1] == 0) {
      t1 = b(n - 1,a);
    }
    else{
        t1 = a[n-1];
    }
    if(a[n-2]==0){
       t2 = b(n - 2,a);
    }
    else{
        t2 = a[n-2];
    }
  int temp1 = (int)(((long)(t1)*t1) % mod);
  int temp2 = (int)((2 * (long)(t1)*t2) % mod);

  a[n] = (temp1 + temp2) % mod;
  return a[n];
}

int balancedBTs(int n) {
    vector<int> a(n+1,0);
    return b(n,a);
}

//Dynamic Programming
#define mod 1000000007
int balancedBTs(int n) {
    if(n<=1){
        return 1;
    }
    int arr[n+1];
    arr[0] = arr[1] = 1;
    for(int i=2;i<=n;i++){
        arr[i] = ((int)(((long)(arr[i-1])*arr[i-1])%mod)+(int)((2*(long)(arr[i-1])*arr[i-2])%mod))%mod;
    }
    return arr[n];
}