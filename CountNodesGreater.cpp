/*
Send Feedback
Given a tree and an integer x, find and return the number of nodes which contains data greater than x.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
The following line contains an integer, that denotes the value of x. 
Output Format :
The first and only line of output prints the count of nodes greater than x.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
35 
Sample Output 1 :
3
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0
10 
Sample Output 2:
5
*/

int getLargeNodeCount(TreeNode<int>* root, int x) {
    if(root->children.empty()){
        return root->data > x;
    }
    else{
        int sum = root->data > x ? 1:0;
        for(int i=0;i<root->children.size();i++){
        	sum += getLargeNodeCount(root->children[i],x);         
        }
        return sum;
    }
}