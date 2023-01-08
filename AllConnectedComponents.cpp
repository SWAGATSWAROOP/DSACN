// Code : All connected components
// Send Feedback
// Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
// Note:
// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 2. E is the number of edges present in graph G.
// 3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
// Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
// Input Format :
// The first line of input contains two integers, that denote the value of V and E.
// Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.
// Output Format :
// Print different components in new line. And each component should be printed in increasing order of vertices (separated by space). Order of different components doesn't matter.
// Constraints :
// 0 <= V <= 1000
// 0 <= E <= (V * (V - 1)) / 2
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// Sample Input 1:
// 4 2
// 0 1
// 2 3
// Sample Output 1:
// 0 1 
// 2 3 
// Sample Input 2:
// 4 3
// 0 1
// 1 3 
// 0 3
// Sample Output 2:
// 0 1 3 
// 2

#include <iostream>
#include <queue>
using namespace std;

void BFS(int **edges, bool *visited, int vertex, int n) {
  queue<int> helper;
  helper.push(vertex);
  visited[vertex] = true;
  priority_queue<int,vector<int>,greater<int>> map;
  map.push(vertex);
  while (!helper.empty()) {
    int i = helper.front();
    helper.pop();
    for (int j = 0; j < n; j++) {
      if (edges[i][j]!=0 && !visited[j]) {
        visited[j] = true;
        helper.push(j);
        map.push(j);
      }
    }
  }
  while(!map.empty()){
    cout<<map.top()<<" ";
    map.pop();
  }
}

int main() {
  int n, e;
  cin >> n >> e;
  if (n == 0) {
    return 0;
  }
  bool *visited = new bool[n];
  int **edges = new int *[n];
  for (int i = 0; i < n; i++) {
    visited[i] = false;
    edges[i] = new int[n];
    for (int j = 0; j < n; j++) {
      edges[i][j] = 0;
    }
  }

  for (int i = 0; i < e; i++) {
    int v, l;
    cin >> v >> l;
    edges[v][l] = 1;
    edges[l][v] = 1;
  }

  for (int i = 0; i < n; i++) {
    if (!visited[i]){
      BFS(edges, visited, i, n);
      cout<<endl;
    }
  }
  delete[] visited;
  for(int i=0;i<n;i++){
    delete [] edges[i];
  }

  return 0;
}