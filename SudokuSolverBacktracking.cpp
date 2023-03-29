// Sudoku Solver
// Send Feedback
// Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
// You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.
// Input Format:
// There are nine lines in input. Each of the nine lines contain nine space separated integers. These nine lines represent the sudoku board.
// Output Format:
// The first and only line of output contains boolean value, either true or false, as described in problem statement.
// Constraints:
// The cell values lie in the range: [0, 9]
// Time Limit: 1 second 
// Note:
// Input are given in a way that backtracking solution will work in the provided time limit.
// Sample Input 1:
// 9 0 0 0 2 0 7 5 0 
// 6 0 0 0 5 0 0 4 0 
// 0 2 0 4 0 0 0 1 0 
// 2 0 8 0 0 0 0 0 0 
// 0 7 0 5 0 9 0 6 0 
// 0 0 0 0 0 0 4 0 1 
// 0 1 0 0 0 5 0 8 0 
// 0 9 0 0 7 0 0 0 4 
// 0 8 2 0 4 0 0 0 6
// Sample Output 1:
// true
//Sample Input 2
//3 0 5 4 2 0 8 1 0 
// 4 8 7 9 0 1 5 0 6 
// 0 2 9 0 5 6 3 7 4 
// 8 5 0 7 9 3 0 4 1 
// 6 1 3 2 0 8 9 5 7 
// 6 1 3 2 0 8 9 5 7 
// 0 7 4 0 6 5 2 8 0 
// 2 4 1 3 0 9 0 6 5 
// 5 0 8 6 7 0 1 9 2
// Sample Output 2:
// false

#include<iostream>
#include<utility>
using namespace std;

int sudoku[9][9];

pair<int,int> boxdim(int num){
    pair<int,int> p;
    if(num%3==0){
        p.first = num;
        p.second = num+2;
    }
    else if((num+1)%3==0){
        p.first = num-2;
        p.second = num;
    }
    else{
        p.first = num - 1;
        p.second = num + 1;
    }
    return p;
}

bool check(int row,int col,int num){
    //row
    for(int i=0;i<9;i++){
        if(sudoku[row][i]==num){
            return false;
        }
    }

    //column
    for(int i=0;i<9;i++){
        if(sudoku[i][col]==num){
            return false;
        }
    }

    //box
    pair<int,int> r = boxdim(row);
    pair<int,int> c = boxdim(col);
    for(int i=r.first;i<=r.second;i++){
        for(int j=c.first;j<=c.second;j++){
            if(num == sudoku[i][j]){
                return false;
            }
        }
    }
    return true;  
}

bool sudokusolver(int row=0,int col=0){
    if(col == 9){
        col = 0;
        row += 1; 
    }

    if(row == 9){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<sudoku[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    if(sudoku[row][col] == 0){
        for(int i=1;i<=9;i++){
            if(check(row,col,i)){
                sudoku[row][col] = i;
                if(sudokusolver(row,col+1)){
                    return true;
                }
                sudoku[row][col] = 0;
            }
        }
        return false;
    }
    return sudokusolver(row,col+1);
}


int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>sudoku[i][j];
        }
    }
    cout<<endl<<endl;
    if(sudokusolver()){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}