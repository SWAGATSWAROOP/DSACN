/*
Reverse Word Wise
Send Feedback
Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.
Input format :
String in a single line
Output format :
Word wise reversed string in a single line
Constraints :
0 <= |S| <= 10^7
where |S| represents the length of string, S.
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
Ninjas Coding to Welcome
Sample Input 2:
Always indent your code
Sample Output 2:
code your indent Always
*/

void reverseStringWordWise(char input[]){
    int count = 0;
    while(input[count]!='\0'){
        count++;
    }
	for(int i = 0,j=count -1;i<j;i++,j--){
        char s = input[i];
        input[i] = input[j];
        input[j] = s;
    }
    int l  = 0;
    for(int k = 0;k<=count;k++){
        if(input[k]==' ' || input[k]=='\0'){
            int n = l,f = k - 1;
            while(n<f){
                char s = input[n];
                input[n++] = input[f];
                input[f--] = s;
            }
            l = k+1;
        }
    }
}