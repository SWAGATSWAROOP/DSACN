// Islands
// Send Feedback
// An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 0 to V-1) and E connections or edges between islands. Can you count the number of connected groups of islands.
// Input Format :
// The first line of input contains two integers, that denote the value of V and E.
// Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b. 
// Output Format :
// Print the count the number of connected groups of islands
// Constraints :
// 0 <= V <= 1000
// 0 <= E <= (V * (V-1)) / 2
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// Time Limit: 1 second
// Sample Input 1:
// 5 8
// 0 1
// 0 4
// 1 2
// 2 0
// 2 4
// 3 0
// 3 2
// 4 3
// Sample Output 1:
// 1 

#include <iostream>
using namespace std;

void DFS(int** edge,bool*m,int sv,int n){
    m[sv] = true;
    for(int i=0;i<n;i++){
        if(edge[sv][i] && !m[i]){
            DFS(edge,m,i,n);
        }
    }
    return;
}

int main() {
    // Write your code here
    int n,e;
    cin>>n>>e;
    if(n == 0 || e == 0){
        cout<<n<<endl;
        return 0;
    }

    bool * m = new bool[n];
    int**edge = new int*[n];
    for(int i=0;i<n;i++){
        edge[i] = new int[n];
        m[i] = false;
        for(int j=0;j<n;j++){
            edge[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++){
        int l,r;
        cin>>l>>r;
        edge[l][r] = 1;
        edge[r][l] = 1;
    }

    int count = 0;
    for(int i=0;i<n;i++){
        if(!m[i]){
            DFS(edge,m,i,n);
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}