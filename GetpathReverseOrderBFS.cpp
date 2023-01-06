// Code : Get Path - BFS
// Send Feedback
// Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
// Find the path using BFS and print the shortest path available.
// Note:
// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 2. E is the number of edges present in graph G.
// 3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
// 4. Save the input graph in Adjacency Matrix.
// Input Format :
// The first line of input contains two integers, that denote the value of V and E.
// Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
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
#include<queue>
#include<unordered_map>
using namespace std;

void print(unordered_map<int,int> map,int sv,int ev){
    int i = ev;
    cout<<ev<<" ";
    while(map[i] != sv){
        cout<<map[i]<<" ";
        i = map[i];
    }
    cout<<sv<<endl;
    return;
}

void BFS(int** edge,bool* visited,int sv,int ev,int n){
    queue<int> pendingnodes;
    pendingnodes.push(sv);
    visited[sv] = true;
    unordered_map<int,int> map; //Using to map to store from which node come from where
    while(!pendingnodes.empty()){
        int j = pendingnodes.front();
        if(j == ev){
            print(map,sv,ev);
        }
        pendingnodes.pop();
        for(int i=0;i<n;i++){
          if (edge[j][i] && !visited[i]) {
            map[i] = j;
            visited[i] = true;
            pendingnodes.push(i);
          }
        }
    }
    return;
}

int main() {
    // Write your code here
    int n,e;
    cin>>n>>e;

    int** edge = new int*[n];
    bool* visited = new bool[n];

    for(int i=0;i<n;i++){
        visited[i] = false;
        edge[i] = new int[n];
        for(int j=0;j<n;j++){
            edge[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++){
        int l,v;
        cin>>l>>v;
        edge[l][v] = 1;
        edge[v][l] = 1;
    }

    int sv,ev;
    cin>>sv>>ev;
    BFS(edge,visited,sv,ev,n);
}