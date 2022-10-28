/*
Check Palindrome (recursive)
Send Feedback
Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S
Output Format :
'true' or 'false'
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
racecar
Sample Output 1:
true
Sample Input 2 :
ninja
Sample Output 2:
false
*/

void CompressString(char input[],int i){
    input[i-1]='\0';
}

bool checkPalindrome(char input[]) {
    if(input[0]=='\0'){
        return true;
    }
    int i =0;
	while(input[i]!='\0'){
        i++;
    }
    if(input[0]!=input[i-1]){
        return false;
    }
    CompressString(input,i);
    checkPalindrome(input+1);
}