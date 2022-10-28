/*
Print Keypad Combinations Code
Send Feedback
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include <iostream>
#include <string>
using namespace std;

void print(int num,string output){
    if(num==0){
        cout<<output<<endl;
        return;
    }
    string input;
    int s = num%10;
    num /= 10;
    switch(s){
        case 2:
            input = "abc";
            break;
        
        case 3:
            input = "def";
            break;
            
        case 4:
            input ="ghi";
            break;
            
        case 5:
            input = "jkl";
            break;
            
        case 6:
            input = "mno";
            break;
            
        case 7:
            input = "pqrs";
            break;
            
        case 8:
            input = "tuv";
            break;
            
        case 9:
            input = "wxyz";
            break;
    }
    print(num,input[0]+output);
    print(num,input[1]+output);
    print(num,input[2]+output);
    if(s== 7 || s== 9){
        print(num,input[3]+output);
    }
}

void printKeypad(int num){
    string output="";
    print(num,output);
}