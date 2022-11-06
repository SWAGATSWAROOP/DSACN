/*
Level wise linkedlist
Send Feedback
Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format :
Each level linked list is printed in new line (elements are separated by space).
Constraints:
Time Limit: 1 second
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
5 
6 10 
2 3 
9
*/

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
  vector<Node<int> *> h;
  if (root == 0) {
    Node<int> *oot = 0;
    h.push_back(oot);
	return h;
   }
   queue<BinaryTreeNode<int>*> hg;
   hg.push(root);
   while(!hg.empty()){
   int l = hg.size();
   Node<int> *oot = 0;
   Node<int> *ho = 0;
   for (int i = 0; i <l;i++) {
    BinaryTreeNode<int> *hh = hg.front();
	hg.pop();
    if (!oot) {
		oot = new Node<int>(hh->data);
		ho = oot;
	}
	else{
         ho->next = new Node<int>(hh->data);
		 ho = ho->next;
    }
	if(hh->left){
		hg.push(hh->left);
	}
	if(hh->right){
		hg.push(hh->right);
	}
    }
	h.push_back(oot);
   }
   return h;
}