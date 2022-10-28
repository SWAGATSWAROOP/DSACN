/*
Send Feedback
Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).
Note: You don't need to print the elements, just update the elements and return the head of updated LL.
Input Constraints:
1 <= Length of Linked List <=10^6.
Input format :
Line 1 : Linked list elements (separated by space and terminated by -1)
Output Format :
Line 1: Updated linked list elements 
Sample Input 1 :
3 9 2 5 -1
Sample Output 1 :
3 9 2 6
Sample Input 2 :
9 9 9 -1
Sample Output 1 :
1 0 0 0 
*/

/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*/

Node* NextLargeNumber(Node *head) {
	if(head == 0){
        return head;
    }
    Node* curr = head;
    while(curr->next!=0){
        curr = curr->next;
    }
    if(curr->data == 9){
        if(head->data == 9){
            curr = head;
            while(curr!=0){
                curr->data = 0;
                curr = curr->next;
            }
            Node* m = new Node(1);
            m->next = head;
            return m;
        }
        else{
            head->data += 1;
            return head;
        }
    }
    curr->data += 1; 
    return head;
}


