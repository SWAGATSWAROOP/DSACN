
/*
Print Subsets of Array
Send Feedback
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
1 <= n <= 15
Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 
*/
void PrintAllSubsets(int arr[], int i, int n,int subset[], int j){    
    if(i==n){
        int idx = 0;
        while(idx<j){
            cout<<subset[idx]<<" ";
            ++idx;
        }
        cout<<endl;
        return;
    }
    PrintAllSubsets(arr,i+1,n,subset,j);
    subset[j] = arr[i];
    PrintAllSubsets(arr,i+1,n,subset,j+1);       
}

void printSubsetsOfArray(int input[], int size) {
    int output[size];
	PrintAllSubsets(input,0,size,output,0);
}