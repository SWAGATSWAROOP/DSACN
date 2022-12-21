//N Queen Code
#include<iostream>
#include<vector>
using namespace std;

bool possible(vector< vector<int> > vect,int row,int col){
    for(int i=row-1;i>=0;i--){
        if(vect[i][col]==1){
            return false;
        }
    }

    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(vect[i][j]==1){
                return false;
            }
    }

    for(int i=row-1,j=col+1;i>=0 && j<vect.size();i--,j++){
            if(vect[i][j]==1){
                return false;
            }
    }
    return true;
}


void nqueen(vector< vector<int> > vect,int row){
    if(row == vect.size()){
        for(int i=0;i<row;i++){
            for(int j=0;j<row;j++){
                cout<<vect[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl<<endl;
        return;
    }

   for(int j=0;j<vect.size();j++){
        if(possible(vect,row,j)){
            vect[row][j] = 1;
            nqueen(vect,row+1);
            vect[row][j] = 0;
        }
   }
   return;
}

int main(){
    cout<<"Enter the size of the chess board: "<<endl;
    int n;
    cin>>n;
    vector< vector<int> > vect(n,vector<int>(n,0));
    nqueen(vect,0);
    return 0;
}