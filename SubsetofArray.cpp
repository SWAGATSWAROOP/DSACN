/*Return subset of an array
Send Feedback
Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
Input format :
Line 1 : Size of array
Line 2 : Array elements (separated by space)
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
int subset(int input[], int n, int output[][20]) {
    if(n==0){
        output[0][0]=0;
        return 1;
    }
    int smalloutputsize = subset(input+1,n-1,output);
    for(int i=0;i<smalloutputsize;i++){
        int col = output[i][0]+1;
        output[smalloutputsize+i][0] = col;
        output[smalloutputsize+i][1] = input[0];
        for(int j=2;j<=col;j++){
            output[smalloutputsize+i][j] = output[i][j-1];
        }
    }
 	return 2*smalloutputsize;
}
