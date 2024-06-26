/*
tree
Send Feedback
Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output Format:
The binary tree is printed level wise, as described in the task. Each level is printed in new line.
Constraints
Time Limit: 1 second
Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5
10 6
2 3
9
*/

int height(BinaryTreeNode<int>* root){
	if(root == 0){
		return 0;
	}
	return 1+max(height(root->left),height(root->right));
}

void print(BinaryTreeNode<int>* root,int k,int l){
	if(k==0){
		cout<<root->data<<" ";
		return;
	}
	if(l==0){
		if(root->left){
			print(root->left,k-1,l);
		}
		if(root->right){
			print(root->right,k-1,l);
		}
	}
	else{
		if(root->right){
			print(root->right,k-1,l);
		}
		if(root->left){
			print(root->left,k-1,l);
		}
	}
}

void zigZagOrder(BinaryTreeNode<int> *root) {
	int l = height(root);
	for(int i = 0;i<l;i++){
		print(root,i,i%2);
		cout<<endl;
	}
}