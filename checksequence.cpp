/*
Does s contain t ?
Send Feedback
Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).
Return true or false.
Do it recursively.
E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
true or false
Sample Input 1 :
abchjsgsuohhdhyrikkknddg
coding
Sample Output 1 :
true
Sample Input 2 :
abcde
aeb
Sample Output 2 :
false
*/

bool checksequenece(char large[] , char*small) {
	int i=0,j=0;
    while(large[i]!='\0'){
        if(small[j]=='\0'){
        	return true;
    	}
        else if(small[j]==large[i]){
            j++;
        }
        i++;
    }
    return false;
}