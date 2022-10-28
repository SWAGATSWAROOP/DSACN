/*
Remove Consecutive Duplicates
Send Feedback
For a given string(str), remove all the consecutive duplicate characters.
Example:
Input String: "aaaa"
Expected Output: "a"

Input String: "aabbbcc"
Expected Output: "abc"
 Input Format:
The first and only line of input contains a string without any leading and trailing spaces. All the characters in the string would be in lower case.
Output Format:
The only line of output prints the updated string.
Note:
You are not required to print anything. It has already been taken care of.
Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second
Sample Input 1:
aabccbaa
Sample Output 1:
abcba
Sample Input 2:
xxyyzxx
Sample Output 2:
xyzx
*/

void removeConsecutiveDuplicates(char input[]) {
    int i=0;
    char* s = new char[strlen(input)];
    while(input[i]!='\0'){
        if(input[i]!=input[i+1]){
            s[i] = input[i];
            i++;
            continue;
        }
        for(int k = i;input[k]!='\0';k++){
            input[k] = input[k+1];
        }
    }
    s[i] = '\0';
    for(int k = 0;k<=i;k++){
        input[k] = s[k]; 
    }
    delete []s;
    s = NULL;
}