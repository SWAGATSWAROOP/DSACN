// Code : Pair Sum to 0
// Send Feedback
// Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
// Note: Array A can contain duplicate elements as well.
// Input format:
// The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
// The following line contains N space separated integers, that denote the value of the elements of the array.
// Output format :
// The first and only line of output contains the count of pair of elements in the array which sum up to 0. 
// Constraints :
// 0 <= N <= 10^4
// Time Limit: 1 sec
// Sample Input 1:
// 5
// 2 1 -2 2 3
// Sample Output 1:
// 2

#include <unordered_map>
int pairSum(int *arr, int n) {
	int count = 0;
	unordered_map<int,int> map;
	for(int i=0;i<n;i++){
	if(map.count(-arr[i])>0){
		count += map[-arr[i]];	
	}
	map[arr[i]]++;
	}
	return count;
}