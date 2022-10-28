/*
Code: Merge Sort
Send Feedback
 Given a singly linked list of integers, sort it using 'Merge Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Output 2 :
2
-1
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90 
*/

#include <iostream>
using namespace std;



class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *mergeSort(Node *head)
{
	if(head == 0 || head->next == 0){
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=0 && fast->next != 0){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* head4 = mergeSort(slow->next);
    slow->next = 0;
    Node* head3 = mergeSort(head);
    Node* head2 = 0;
    Node* tmp =0;
    while(head3!=0 && head4!=0){
        if(head3->data > head4->data){
            if(head2 == 0){
                head2 = head4;
                tmp = head4;
            }
            else{
                head2->next = head4;
                head2 = head2->next;
            }
            head4 = head4->next;
        }
        else{
            if(head2 == 0){
                head2 = head3;
                tmp = head3;
            }
            else{
                head2->next = head3;
                head2 = head2->next;
            }
            head3 = head3->next;
        }
    }
    if(head3!=0){
        if(tmp==0){
            return head3;
        }
        head2->next = head3;
    }
    else if(head4!=0){
        if(tmp==0){
            return head4;
        }
        head2->next = head4;
    }
    return tmp;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}