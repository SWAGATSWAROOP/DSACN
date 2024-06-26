// Coding Ninjas
// Send Feedback
// Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
// There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
// Input Format :
// The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix. 
// Each of the following N lines contain M characters. Please note that characters are not space separated.
// Output Format :
// Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.
// Constraints :
// 1 <= N <= 1000
// 1 <= M <= 1000
// Time Limit: 1 second
// Sample Input 1:
// 2 11
// CXDXNXNXNXA
// XOXIXGXIXJX
// Sample Output 1:
// 1

#include<string>
bool DFS(vector<vector<char>> &board, int n, int m,int i,int j,bool** visited,int k,string &str){
    if(i < 0 || j < 0 || i == n || j == m || board[i][j]!=str[k] ||visited[i][j]){
        return false;
    }
    if(k == 10){
      return board[i][j] == str[k];
    }
    visited[i][j] = true;
    bool a = DFS(board,n,m,i-1,j,visited,k+1,str);
    bool b = DFS(board,n,m,i+1,j,visited,k+1,str);
    bool c = DFS(board,n,m,i,j-1,visited,k+1,str);
    bool d = DFS(board,n,m,i+1,j+1,visited,k+1,str);
    bool e = DFS(board,n,m,i-1,j-1,visited,k+1,str);
    bool f = DFS(board,n,m,i-1,j+1,visited,k+1,str);
    bool g = DFS(board,n,m,i+1,j-1,visited,k+1,str);
    bool h = DFS(board,n,m,i,j+1,visited,k+1,str);

    if(a || b || c || d || e || f || g || h){
        return true;
    }
    visited[i][j] = false;
    return false;

}
bool hasPath(vector<vector<char>> &board, int n, int m) {
    string str = "CODINGNINJA";
    bool** visited = new bool*[n];
    for(int i=0;i<n;i++){
        visited[i] = new bool[n];
        for(int j=0;j<n;j++){
            visited[i][j] = false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='C'){
              if(DFS(board,n,m,i,j,visited,0,str)){
                  return true;
              }
            }
        }
    }
    return false;
}