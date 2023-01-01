// Code : Edit Distance
// Send Feedback
// Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
// Edit Distance
// Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
// 1. Delete a character
// 2. Replace a character with another one
// 3. Insert a character
// Note
// Strings don't contain spaces
// You need to find the edit distance from input string1 to input string2.
// Input Format :
// The first line of input contains a string, that denotes the value of s. The following line contains a string, that denotes the value of t.
// Output Format :
// The first and only line of output contains the edit distance value between the given strings.
// Constraints :
// 1<= m,n <= 10
// Time Limit: 1 second
// Sample Input 1 :
// abc
// dc
// Sample Output 1 :
// 2

//Brute Force:
int editDistance(string s1, string s2) {
	// Write your code here
	int m = s1.size();
	int n = s2.size();

	if(m == 0 || n == 0){
		return max(m,n);
	}

	if(s1[0]==s2[0]){
		return editDistance(s1.substr(1),s2.substr(1));
	}
	else{
		int a = editDistance(s1.substr(1),s2);
		int b = editDistance(s1,s2.substr(1));
		int c = editDistance(s1.substr(1),s2.substr(1));

		return 1+min(a,min(b,c));
	}
}

//Memotization
int edistance(string s1,string s2,int ** output){
	int m = s1.size();
	int n = s2.size();
	
	if(output[m][n]!= -1){
		return output[m][n]; 
	}

	int ans;
	if(s1[0] == s2[0]){
		ans =  edistance(s1.substr(1),s2.substr(1),output);
	}
	else{
		int a = edistance(s1.substr(1),s2,output);
		int b = edistance(s1,s2.substr(1),output);
		int c = edistance(s1.substr(1),s2.substr(1),output);
		ans =  1+ min(a,min(b,c));
	}
	output[m][n] = ans;
	return ans;
}

int editDistance(string s1, string s2)
{
	int m = s1.size()+1;
	int n = s2.size()+1;
	int* output[m];
	for(int i=0;i<m;i++){
		output[i] = new int[n];
		for(int j=0;j<n;j++){
			if(i == 0){
				output[i][j] = j;
			}
			else if(j == 0){
				output[i][j] = i;
			}
			else{
				output[i][j] = -1;
			}
		}
	}

	return edistance(s1,s2,output);
}

//Dynamic Programming
int editDistance(string s1, string s2)
{
	int m = s1.size();
	int n = s2.size();

	int* output[m+1];
	for(int i=0;i<=m;i++){
		output[i] = new int[n+1];
        for (int j = 0; j <= n; j++) {
			if(i==0){
				output[i][j] = j;
			}
			else if(j==0){
				output[i][j] = i;
			}
			else{
		        output[i][j] = -1;
            }
        }
    }

	for(int i = 1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s1[m-i]==s2[n-j]){
				output[i][j] = output[i-1][j-1];
			}
			else{
				output[i][j] = 1+min(output[i-1][j-1],min(output[i][j-1],output[i-1][j]));
			}
		}
	}
	return output[m][n];
}