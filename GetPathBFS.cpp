// Code : Has Path
// Send Feedback
// Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.
// Note:
// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 2. E is the number of edges present in graph G.
// Input Format :
// The first line of input contains two integers, that denote the value of V and E.
// Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
// The following line contain two integers, that denote the value of v1 and v2.
// Output Format :
// The first and only line of output contains true, if there is a path between v1 and v2 and false otherwise.
// Constraints :
// 0 <= V <= 1000
// 0 <= E <= 1000
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// 0 <= v1 <= V - 1
// 0 <= v2 <= V - 1
// Time Limit: 1 second
// Sample Input 1 :
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// 1 3
// Sample Output 1 :
// true
// Sample Input 2 :
// 6 3
// 5 3
// 0 1
// 3 4
// 0 3
// Sample Output 2 :
// false

#include <iostream>
#include<queue>
using namespace std;

void BFS(int** edge,bool* visited,int sv,int ev,int n){
    queue<int> pendingnodes;
    pendingnodes.push(sv);
    visited[sv] = true;
    while(!pendingnodes.empty()){
        int j = pendingnodes.front();
        pendingnodes.pop();
        for(int i = 0;i<n;i++){
          if(edge[j][i] && !visited[i]) {
            visited[i] = true;
            if(i == ev){
                break;
            }
            pendingnodes.push(i);
          }
        }
    }
    if(visited[ev]){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
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

    int sv,ev;
    cin>>sv>>ev;
    BFS(edge,visited,sv,ev,n);
}