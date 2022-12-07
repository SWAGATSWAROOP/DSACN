/*
Code: BST Class
Send Feedback
Implement the BST class which includes following functions -
1. insert -
Given an element, insert that element in the BST at the correct position. If element is equal to the data of the node, insert it in the left subtree.
2. search
Given an element, find if that is present in BST or not. Return true or false.
3. delete -
Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.
4. printTree (recursive) -
Print the BST in in the following format -
For printing a node with data N, you need to follow the exact format -
N:L:x,R:y
where, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.
There is no space in between.
You need to print all nodes in the recursive format in different lines.
*/

class BST {
    BinaryTreeNode<int>* node;

    BinaryTreeNode<int>* largest(BinaryTreeNode<int>* root){
        if(!root->left){
            return root;
        }
        largest(root->left);
    }

    BinaryTreeNode<int> *del(int data,BinaryTreeNode<int> *root) {
      if (root == 0) {
        return 0;
      } else if (root->data == data) {
        if (root->right == 0 && root->left == 0) {
          delete root;
          return 0;
        } else if (root->left != 0 && root->right != 0) {
          root->data = largest(root->right)->data;
          root->right = del(root->data,root->right);
          return root;
        } else if (root->left) {
          BinaryTreeNode<int> *oot = root->left;
          root->left = 0;
          delete root;
          return oot;
        } else {
          BinaryTreeNode<int> *oot = root->right;
          root->right = 0;
          delete root;
          return oot;
        }
      } else {
        if (root->data > data) {
          root->left = del(data,root->left);
        } else {
          root->right = del(data,root->right);
        }
      }
      return root;
    }
    //  BinaryTreeNode<int> *findMin(BinaryTreeNode<int> *node) //TA
    // {
    //     if (node->left == NULL)
    //         return node;
    //     return findMin(node->left);
    // }
   /* BinaryTreeNode<int> *del(int key, BinaryTreeNode<int> *node)
    {

        if (node == NULL)
            return NULL;

        if (key > node->data)
            node->right = del(key, node->right);
        else if (key < node->data)
            node->left = del(key, node->left);
        else
        {
            // If node is leaf
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL)
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minnode = findMin(node->right);

                node->data = minnode->data;
                node->right = del(minnode->data, node->right);
                return node;
            }
        }

        return node;
    }*/
    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* root,int data){
        if(root == 0){
          BinaryTreeNode<int>* oot = new BinaryTreeNode<int>(data);
          return oot;
        }
        else if(root->data >= data){
            root->left = insert(root->left,data);
        }
        else{
            root->right = insert(root->right,data);
        }
        return root;
    }

    void pri(BinaryTreeNode<int>* root){
        if(root == 0){
            return;
        }
        cout<<root->data<<":";
        if(root->left){
            cout<<"L:"<<root->left->data<<",";
        }
        if(root->right){
          cout <<"R:"<< root->right->data;
        }
        cout<<endl;
        pri(root->left);
        pri(root->right);
    }
    bool ser(int data,BinaryTreeNode<int>* root){
       bool ans;
        if(root == 0){
            return false;
        }
        else if(root->data == data){
            return true;
        }
        else if(root->data > data){
           ans = ser(data,root->left);
        }
        else{
           ans = ser(data,root->right);
        }
        return ans;
    }
   public:
    BST() { 
        node = 0;
    }
    void remove(int data) { 
        this->node = del(data,this->node);
    }
    void print() { 
        pri(this->node);
    }
    void insert(int data) { 
        this->node = insert(this->node,data);
    }
    bool search(int data) {
		return ser(data,this->node);
    }
};