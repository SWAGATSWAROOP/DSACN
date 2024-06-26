// Krushkals Algorithm
// Code : Kruskal's Algorithm
// Send Feedback
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
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
// Time Limit: 1 sec
// Sample Input 1 :
// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8
// Sample Output 1 :
// 1 2 1
// 0 1 3
// 0 3 5

#include <iostream>
#include <algorithm>
using namespace std;

class edge{
    public:
    int source;
    int destination;
    int weight;
};

int isparent(int i,int* parent){
    if(parent[i] == i){
        return i;
    }
    return isparent(parent[i],parent);
}

bool compare(edge e1,edge e2){
    return e1.weight < e2.weight; //Ascending Order
}

void Krushkal(edge* input,int e,int n){
    //Sort in Ascending Order
    sort(input,input+e,compare);

    int * parent = new int[n];
    for(int i = 0;i<n;i++){
        parent[i] = i;
    }

    edge* output = new edge[n-1];

    int count = 0;
    int i = 0;
    while(count != n-1){
        edge curr = input[i];
        int source = isparent(curr.source, parent);
        int destination = isparent(curr.destination,parent);
        if (source != destination) {
            output[count] = curr;
            count++;
            parent[source] = destination; //Failed to realise this
        }
        i++;
    }

    for(int j=0;j<n-1;j++){
        if(output[j].source > output[j].destination){
          cout << output[j].destination << " " << output[j].source<<" "<<output[j].weight<<endl;
        }
        else{
          cout << output[j].source<< " " << output[j].destination<<" "<< output[j].weight << endl;
        }
    }
    return;
}

int main() {
    int n,e;
    cin>>n>>e;
    edge * input = new edge[e];
    for(int i=0;i<e;i++){
        cin>>input[i].source>>input[i].destination>>input[i].weight;
    }

    Krushkal(input,e,n);
    return 0;
}