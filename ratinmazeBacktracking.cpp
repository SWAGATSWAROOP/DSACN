// Rat In A Maze Problem
// Send Feedback
// You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents a maze and a rat starts from the top left cell and has to reach to the bottom right cell of the maze. The rat can move in all the four directions: up, down, left and right.
// In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used to move from source to destination cell.
// You have to print all the paths, following which rat can move from the top left cell to the bottom right cell of the given binary matrix.
// Input Format
// The first line of input contains an integer, that denotes the value of N.
// Each of the following N lines denote rows of the binary matrix and contains either 0 or 1. Each row of the binary matrix contains N elements. 
// Output Format :
// Every possible solution has to be printed on a separate line. Each of the possible solution will have N*N elements, printed row wise and separated by space. The cells that are part of the path should be 1 and remaining all cells should be 0. Please refer to sample test cases for more clarity.   
// Constraints
// 1 <= N <= 18
// 0 <= Number of cells with value 1 <= 15
// Time Limit: 1 second
// Sample Input 1 :
// 3
// 1 0 1
// 1 0 1
// 1 1 1
// Sample Output 1 :
// 1 0 0 1 0 0 1 1 1 
// Explanation :
// Only 1 path is possible. The path is shown in the image below.
// Alt Text
// Sample Input 2 :
// 3
// 1 0 1
// 1 1 1
// 1 1 1
// Sample Output 2 :
// 1 0 0 1 1 1 1 1 1 
// 1 0 0 1 0 0 1 1 1 
// 1 0 0 1 1 0 0 1 1 
// 1 0 0 1 1 1 0 0 1 
// Explanation:
//  As described in the Sample Output 2, four paths are possible.

#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int> > v2){
	    int l = v2.size();
		for(int i=0;i<l;i++){
			for(int j=0;j<l;j++){
				cout<<v2[i][j]<<" ";
			}
		}
	return;
}

void ratinmaze(vector<vector<int> > v,vector<vector<int> > v2,int m=0,int n=0){
	int l = v.size();
	if(m==l-1 && n== l-1){
		v2[m][n] = 1;
		print(v2);
		v2[m][n] = 0;
		cout<<endl;
		return;
	}
	if(m<0 || m >= l || n<0 || n >= l || v2[m][n]==1 || v[m][n]==0){
		return;
	}
	v2[m][n] = 1;
	ratinmaze(v,v2,m-1,n);
	ratinmaze(v,v2,m,n+1);
	ratinmaze(v,v2,m+1,n);
	ratinmaze(v,v2,m,n-1);
	v2[m][n] = 0;
	return;
}

int main() {
	int n;
	cin>>n;
	vector<vector<int> > v(n,vector<int>(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>v[i][j];
		}
	}
	vector<vector<int> > v2(n,vector<int>(n,0));
	ratinmaze(v,v2);
	return 0;
}