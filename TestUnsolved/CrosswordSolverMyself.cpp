#include<iostream>
#include<string>
using namespace std;

char crossword[10][10];

bool horizontalisvalid(string input,int row,int col,int l){
	if(l > 10 - col){
		return false;
	}

	for(int i=0,j=col;i<l;i++,j++){
		if(crossword[row][j] != '-' && crossword[row][j] != input[i]){
			return false;
		}
	}
	return true;
}

bool verticalisvalid(string input,int row,int col,int l){

	if(l > 10 - row){
		return false;
	}

	for(int i=0,j=row;i<l;i++,j++){
		if(crossword[j][col] != '-' && crossword[j][col] != input[i]){
			return false;
		}
	}
	return true;
}

void setvertical(string input,bool state[],int row,int col,int l){
	for(int i=0,j=row;i<l;i++,j++){
		if(crossword[j][col]!='+'){
			if(crossword[j][col] == '-'){
				state[i] = true;
			}
			else{
				state[i] = false;
			}
			crossword[j][col] = input[i];
	}
}
return;
}

void sethorizontal(string input,bool state[],int row,int col,int l){
	for(int i=0,j=col;i<l;i++,j++){
		if(crossword[row][j]!='+'){
			if(crossword[row][j] == '-'){
				state[i] = true;
			}
			else{
				state[i] = false;
			}
			crossword[row][j] = input[i];
		}
}
return;
}

void resetvertical(bool state[],int row,int col,int l){
	for(int i=0,j=row;i<l;i++,j++){
		if(state[i]){
			crossword[j][col] = '-';
		}
}
return;
}

void resethorizontal(bool state[],int row,int col,int l){
	for(int i=0,j=col;i<l;i++,j++){
		if(state[i]){
			crossword[row][j] = '-';
		}
}
return;
}

void set_value(bool helper[],int len){
  for (int i = 0; i < len; i++) {
    helper[i] = false;
  }
}

bool CrossWordHelper(string input[],int length,int index){
if(index == length){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cout<<crossword[i][j];
		}
	cout<<endl;
	}
	return true;
}



for(int i=0;i<10;i++){
	for(int j=0;j<10;j++){
		if(crossword[i][j] == '-' || input[index][0] == crossword[i][j]){
			int l = input[index].size();
			bool state[l];
        	set_value(state,l);
			if(horizontalisvalid(input[index],i,j,l)){
				sethorizontal(input[index],state,i,j,l);
				if(CrossWordHelper(input,length,index+1)){
					return true;
				}
				resethorizontal(state,i,j,l);
			}

			if(verticalisvalid(input[index],i,j,l)){
				setvertical(input[index],state,i,j,l);
				if(CrossWordHelper(input,length,index+1)){
					return true;
				}
				resetvertical(state,i,j,l);
			}
		}
	}
}
return false;
}

void CrosswordSolver(string input[],int length){
bool s =CrossWordHelper(input,length,0);
return;
}

int main(){

for(int i=0;i<10;i++){
string z;
cin>>z;
for(int j=0;j<10;j++){
crossword[i][j] = z[j];
}
}


string k;
cin>>k;

string words="";
string input[10];
int a = 0;

for(int i=0;i<k.length();i++){
	if(k[i] == ';'){
		input[a++] = words;
		words = "";
	}
	else{
		words += k[i];
	}
}
input[a++] = words;
CrosswordSolver(input,a);
return 0;
}
