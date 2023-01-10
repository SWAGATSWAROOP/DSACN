// Dijkstra's Algorithm
// Code : Dijkstra's Algorithm
// Send Feedback
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
// Output Format :
// For each vertex, print its vertex number and its distance from source, in a separate line. The vertex number and its distance needs to be separated by a single space.
// Note : Order of vertices in output doesn't matter.
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
// 0 0
// 1 3
// 2 4
// 3 5


//Done On My Own
#include <iostream>
#include<climits>
using namespace std;

int minVer(int* distance,bool* visited,int n){
    int minver = -1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (minver == -1 || distance[i] < distance[minver])){
            minver = i;
        }
    }
    return minver;
}

void Dijkstra(int** edge,int n){
    int* distance = new int[n];
    bool* visited = new bool[n];

    for(int i=0;i<n;i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[0] = 0;
    
    for(int i=0;i<n-1;i++){
        int minver = minVer(distance,visited,n);
        visited[minver] = true;
        for(int j=0;j<n;j++){
            if(edge[minver][j] && !visited[j] && distance[j] > edge[minver][j]+distance[minver]){
                distance[j] = edge[minver][j]+distance[minver];
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
    delete [] visited;
	delete [] distance;
    return;
}

int main() {
    // Write your code here
    int n,e;
    int** edge = new int*[n];
    for(int i=0;i<n;i++){
        edge[i] = new int[n];
        for(int j=0;j<n;j++){
            edge[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++){
        int l,m,r;
        cin>>l>>m>>r;
        edge[l][m] = r;
        edge[m][l] = r;
    }

    Dijkstra(edge,n);
    for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}
	delete [] edges;
    return 0;
}

//Done By Teacher
#include<iostream>
#include<climits>
using namespace std;


int findMinVertex(int* distance, bool* visited, int n){

	int minVertex = -1;
	for(int i = 0; i < n; i++){
		if(!visited[i] && (minVertex == -1 ||  distance[i] < distance[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}

void dijkstra(int** edges, int n){
	int* distance = new int[n];
	bool* visited = new bool[n];

	for(int i = 0; i < n; i++){
		distance[i] = INT_MAX;
		visited[i] = false;
	}

	distance[0] = 0;

	for(int i = 0; i < n - 1; i++){
		int minVertex = findMinVertex(distance, visited, n);
		visited[minVertex] = true;
		for(int j = 0; j < n; j++){	
			if(edges[minVertex][j] != 0 && !visited[j]){
				int dist = distance[minVertex] + edges[minVertex][j];
				if(dist < distance[j]){
					distance[j] = dist;
				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		cout << i << " " << distance[i] << endl;
	}
	delete [] visited;
	delete [] distance;
	
}

int main() {
	int n;
	int e;
	cin >> n >> e;
	int** edges = new int*[n];
	for (int i = 0; i < n; i++) {
		edges[i] = new int[n];
		for (int j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}

	for (int i = 0; i < e; i++) {
		int f, s, weight;
		cin >> f >> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}
	cout << endl;
	dijkstra(edges, n);

	for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}
	delete [] edges;
}