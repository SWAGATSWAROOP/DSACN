/*

Column Wise Sum
Send Feedback
Given a 2D integer array of size M*N, find and print the sum of ith column elements separated by space.
Input Format :
First and only line of input contains M and N, followed by M * N space separated integers representing the elements in the 2D array.
Output Format :
Sum of every ith column elements (separated by space)
Constraints :
1 <= M, N <= 10^3
Sample Input :
4 2 1 2 3 4 5 6 7 8
Sample Output :
16 20


*/
#include<iostream>
#include<vector>
using namespace std;


int main(){
	int m,n;
    cin>>m>>n;
    int arr[m][n];
    vector<int> v(n,0);
    //int arr1[n] = {0};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //arr1[i]+= arr[j][i];
            v[i] += arr[j][i]; 
        }
    }
    for(int i=0;i<n;i++){
       // cout<<arr1[i]<<" ";
        cout<<v[i]<<" ";
    }
    cout<<endl;
}



