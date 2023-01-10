//Prims Algorithm
// Code : Prim's Algorithm
// Send Feedback
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
// For printing MST follow the steps -
// 1. In one line, print an edge which is part of MST in the format - 
// v1 v2 w
// where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
// 2. Print V-1 edges in above format in different lines.
// Note : Order of different edges doesn't matter.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
// Output Format :
// Print the MST, as described in the task.
// Constraints :
// 2 <= V, E <= 10^5
// 1 <= Wi <= 10^5
// Time Limit: 1 sec
// Sample Input 1 :
// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8
// Sample Output 1 :
// 0 1 3
// 1 2 1
// 0 3 5


#include <iostream>
#include <climits>
using namespace std;

int m(bool* visited,int* weight,int n){
    int minVertex = -1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (minVertex == -1 || weight[minVertex] > weight[i])){
            minVertex = i;
        }
    }
    return minVertex;
}

void prim(int** edge,int n){
    int* parent = new int[n];
    bool *visited = new bool[n];
    int* weight = new int[n];

    for(int i=0;i<n;i++){
        weight[i] = INT_MAX;
        visited[i] = false;
    }

    for(int i=0;i<n;i++){
        int minVertex = m(visited,weight,n);
        visited[minVertex] = true;
        for(int j=0;j<n;j++){
            if(!visited[j] && edge[minVertex][j] && edge[minVertex][j] < weight[j]){
                parent[j] = minVertex;
                weight[j] = edge[minVertex][j];
            }
        }
    }

    for(int i=1;i<n;i++){
        if(parent[i] > i){
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
        else{
          cout << parent[i] << " " <<i<< " " << weight[i] << endl;
        }
    }
    return;
}

int main() {
    // Write your code here
    int n,e;
    cin>>n>>e;
    int** edge = new int*[n];
    for(int i=0;i<n;i++){
        edge[i] = new int[n];
        for(int j=0;j<n;j++){
            edge[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++){
        int s,m,v;
        cin>>s>>m>>v;
        edge[s][m] = v;
        edge[m][s] = v;
    }

    prim(edge,n);
    return 0;
}