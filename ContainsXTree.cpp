/*
Contains x
Send Feedback
Given a generic tree and an integer x, check if x is present in the given tree or not. Return true if x is present, return false otherwise.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
The following line contains an integer, that denotes the value of x.
Output format :
The first and only line of output contains true, if x is present and false, otherwise.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
40 
Sample Output 1 :
true
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0
4 
Sample Output 2:
false
*/

bool isPresent(TreeNode<int>* root, int x) {
    if(root->data == x){
        return true;
    }
	queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        for(int i=0;i<front->children.size();i++){
            if(front->children[i]->data == x){
                return true;
            }
        	pendingNodes.push(front->children[i]);
        }
    }
    return false;
}