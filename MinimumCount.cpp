//Not able to think about the case addition of square of 2 numbers

// Code : Minimum Count
// Send Feedback
// Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
// That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
// Input format :
// The first and the only line of input contains an integer value, 'N'.
//  Output format :
// Print the minimum count of numbers required.
// Constraints :
// 0 <= n <= 10 ^ 4

// Time Limit: 1 sec
// Sample Input 1 :
// 12
// Sample Output 1 :
// 3
// Explanation of Sample Output 1 :
// 12 can be represented as : 
// A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

// B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

// C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

// D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

// As we can see, the output should be 3.
// Sample Input 2 :
// 9
// Sample Output 2 :
// 1

#include <cmath>
int minCount(int n) {
  int *arr = new int[n + 1];
  if (n <= 3)
    return n;
  arr[0] = 0;
  arr[1] = 1;
  arr[2] = 2;
  arr[3] = 3;


  for (int i = 4; i <= n; i++) {
    int ans = i;
    int num = pow(i,0.5);
    for (int j = 1; j <=num; j++) {
      int k = i - (j * j);
      ans = min(ans, arr[k] + 1);
    }
    arr[i] = ans;
  }
  return arr[n];
}