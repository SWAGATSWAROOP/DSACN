// Largest Piece
// Send Feedback
// It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?
// Input Format :
// The first line of input contains an integer, that denotes the value of N. 
// Each of the following N lines contain N space separated integers.
// Output Format :
// Print the count of '1's in the biggest piece of '1's, according to the description in the task.
// Constraints :
// 1 <= N <= 1000
// Time Limit: 1 sec
// Sample Input 1:
// 2
// 1 1
// 0 1
// Sample Output 1:
// 3

int DFS(vector<vector<int>> &cake, int n,int i,int j,bool** visited){
    if(i < 0 || j < 0 || i == n || j == n || !cake[i][j] ||visited[i][j]){
        return 0;
    }
    visited[i][j] = true;
    int l = DFS(cake,n,i+1,j,visited);
    int k = DFS(cake,n,i,j+1,visited);
    int m = DFS(cake,n,i-1,j,visited);
    int o = DFS(cake,n,i,j-1,visited);
    return 1+l+k+m+o;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
  int count = 0;
  bool **visited = new bool*[n];
  for (int i = 0; i < n; i++) {
    visited[i] = new bool[n];
    for(int j=0;j<n;j++){
      visited[i][j] = false;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (cake[i][j] && !visited[i][j]) {
        count = max(count,DFS(cake, n, i, j, visited));
      }
    }
  }
  return count;
}