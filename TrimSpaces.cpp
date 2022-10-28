/*
Trim Spaces
Send Feedback
Given an input string S that contains multiple words, you need to remove all the spaces present in the input string.
There can be multiple spaces present after any word.
Input Format :
 String S
Output Format :
Updated string
Constraints :
1 <= Length of string S <= 10^6
Sample Input :
abc def g hi
Sample Output :
abcdefghi
*/
void trimSpaces(char input[]){
    
    /*for(int i=0;i<strlen(input)-1;i++){
        if(input[i]==' '){
            for(int j=i+1;j<strlen(input);j++){
                input[j]=input[j+1];
            }
        }
    }*/
    int i = 0, j = 0;
    while (input[i])
    {
        if (input[i] != ' ')
           input[j++] = input[i];
        i++;
    }
    input[j] = '\0';
}

