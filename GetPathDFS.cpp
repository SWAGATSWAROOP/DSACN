// Code : Get Path - DFS
// Send Feedback
// Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
// Find the path using DFS and print the first path that you encountered.
// Note:
// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 2. E is the number of edges present in graph G.
// 3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
// 4. Save the input graph in Adjacency Matrix.
// Input Format :
// The first line of input contains two integers, that denote the value of V and E.
// Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
// The following line contain two integers, that denote the value of v1 and v2.
// Output Format :
// Print the path from v1 to v2 in reverse order.
// Constraints :
// 2 <= V <= 1000
// 1 <= E <= (V * (V - 1)) / 2
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// 0 <= v1 <= 2^31 - 1
// 0 <= v2 <= 2^31 - 1
// Time Limit: 1 second
// Sample Input 1 :
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// 1 3
// Sample Output 1 :
// 3 0 1
// Sample Input 2 :
// 6 3
// 5 3
// 0 1
// 3 4
// 0 3
// Sample Output 2 :

#include <iostream>
using namespace std;

bool DFS(int**edge,bool* visited,int v1,int v2,int n){
    if(v1 == v2){
        cout<<v1<<" ";
        visited[v1] = true;
        return true;
    }
    visited[v1] = true;
    for(int i=0;i<n;i++){
        if(edge[v1][i] && !visited[i]){
            visited[i] = true;
            if(DFS(edge,visited,i,v2,n)){
                cout<<v1<<" ";
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n,e;
    cin>>n>>e;

    int** edge = new int*[n];
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        edge[i] = new int[n];
        visited[i] = false;
        for(int j=0;j<n;j++){
             edge[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++){
        int l,k;
        cin>>l>>k;
        edge[l][k] = 1;
        edge[k][l] = 1;
    }

    int v1,v2;
    cin>>v1>>v2;
    DFS(edge,visited,v1,v2,n);
    return 0;
}