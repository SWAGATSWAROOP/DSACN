/*
Even after Odd LinkedList
Send Feedback
For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. The relative order of the odd and even terms should remain unchanged.
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format:
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space. 
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format:
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
1 4 5 2 -1
Sample Output 1 :
1 5 4 2 
Sample Input 2 :
2
1 11 3 6 8 0 9 -1
10 20 30 40 -1
Sample Output 2 :
1 11 3 9 6 8 0
10 20 30 40
*/

Node *evenAfterOdd(Node *head)
{
    if(head == 0 || head->next == 0){
        return head;
    }
	Node* O = 0;
    Node* E = 0;
    Node* L = 0;
    Node* M = 0;
    while(head){
        if(head->data%2!=0){
            if(M == 0){
                O = head;
                M = head;
            }
            else{
                O->next = head;
                O = head; 
            }
        }
        else{
            if(L == 0){
                E = head;
                L = head;
            }
            else{
                E->next = head;
                E = head;
            }
        }
        head = head->next;
    }
    if(L == 0){
        return M;
    }
    if(M == 0){
        return L;
    }
    E->next = 0;
    O->next = L;
    return M;
}