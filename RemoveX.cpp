/*
Remove X
Send Feedback
Given a string, compute recursively a new string where all 'x' chars have been removed.
Input format :
String S
Output format :
Modified String
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S. 
Sample Input 1 :
xaxb
Sample Output 1:
ab
Sample Input 2 :
abc
Sample Output 2:
abc
Sample Input 3 :
xx
Sample Output 3:

*/

void removeX(char input[]) {
    if(input[0]=='\0'){
        return;
    }
    removeX(input+1);
    if(input[0]=='x'){
        int i=0;
        while(input[i]!='\0'){
            input[i]=input[i+1];
            i++;
        }
        return;
    }
}