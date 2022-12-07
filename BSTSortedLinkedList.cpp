/*
Code: BST to Sorted LL
Send Feedback
Given a BST, convert it into a sorted linked list. You have to return the head of LL.
Input format:
The first and only line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
Output Format:
The first and only line of output prints the elements of sorted linked list.
Constraints:
Time Limit: 1 second
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1:
2 5 6 7 8 10
*/

#include<utility>
pair<Node<int> *, Node<int> *> construct(BinaryTreeNode<int> *root){
	if(root == 0){
        pair<Node<int> *, Node<int> *> t = {0,0};
		return t;
    }
	Node<int>* K = new Node<int>(root->data);
    pair<Node<int> *, Node<int> *> L;
    pair<Node<int> *, Node<int> *> R; 
	if (root->left) {
      L = construct(root->left);
      L.second->next = K;
    }
    else{
		L.first = K;
	}
    if (root->right) {
        R = construct(root->right);
        K->next = R.first;
    }
	else{
		R.second = K;
	}
    pair<Node<int> *, Node<int> *> Result = {L.first, R.second};
    return Result;
}
Node<int> *constructLinkedList(BinaryTreeNode<int> *root) {
  pair<Node<int> *, Node<int> *> M = construct(root);
  return M.first;
}