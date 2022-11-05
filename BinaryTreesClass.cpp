#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BinaryTreesNodes{
    public:
    int data;
    BinaryTreesNodes* left;
    BinaryTreesNodes* right;

    BinaryTreesNodes(T data){
        this->data = data;
    }

    ~BinaryTreesNodes(){
        delete left;
        delete right; 
    }
};

template<typename T>
void print(BinaryTreesNodes<T>* root){
    if(!root){
        return;
    }
    cout<<root->data<<" : ";
    if(root->left){
        cout<<"L "<<root->left->data<<" ";
    }
    if(root->right){
        cout<<"R "<<root->right->data;
    }
    cout<<endl;
    print(root->left);
    print(root->right);
}

BinaryTreesNodes<int>* input(){
    int data;
    cout<<"Enter root data :";
    cin>>data;
    if(data == -1){
        return 0;
    }
    BinaryTreesNodes<int>* root = new BinaryTreesNodes<int>(data);
    root->left = input();
    root->right = input();
    return root;
}

BinaryTreesNodes<int>* inputlevelvise(){
    cout<<"Enter root data : ";
    int rootdata;
    cin>>rootdata;
    if(rootdata == -1){
        return 0;
    }
    BinaryTreesNodes<int>* root = new BinaryTreesNodes<int>(rootdata);
    queue<BinaryTreesNodes<int>*> Nodes;
    Nodes.push(root);
    while(!Nodes.empty()){
        BinaryTreesNodes<int>* front = Nodes.front();
        Nodes.pop();
        
        cout<<"Enter left rootdata of "<<front->data<<" :";
        int leftrootdata;
        cin>>leftrootdata;
        if(!(leftrootdata == -1)){
            front->left = new BinaryTreesNodes<int>(leftrootdata);
            Nodes.push(front->left);
        }

        cout<<"Enter right rootdata of "<<front->data<<" :";
        int rightrootdata;
        cin>>rightrootdata;
        if(!(rightrootdata == -1)){
            front->right = new BinaryTreesNodes<int>(rightrootdata);
            Nodes.push(front->right);
        }
    }
    return root;
}

template<typename T>
void printlevelvise(BinaryTreesNodes<T>* root){
    if(!root){
        return;
    }
    queue<BinaryTreesNodes<int>*> Nodes;
    Nodes.push(root);
    while(!Nodes.empty()){
        BinaryTreesNodes<int>* front = Nodes.front();
        Nodes.pop();
        cout<<front->data<<" : ";
        if(front->left){
            cout<<"L "<<front->left->data<<" , ";
            Nodes.push(front->left);
        }
        if(front->right){
            cout<<"R "<<front->right->data;
            Nodes.push(front->right);
        }
        cout<<endl;
    }
}

template<typename T>
int numNodes(BinaryTreesNodes<T>* root){
    if(!root){
        return 0;
    }
    return 1 + numNodes(root->left) + numNodes(root->right);
}

void Inorderprint(BinaryTreesNodes<int>* root){
    if(!root){
        return;
    }
    Inorderprint(root->left);
    cout<<root->data<<" ";
    Inorderprint(root->right);
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

int main(){
    BinaryTreesNodes<int>* root = inputlevelvise();
    Inorderprint(root);
    cout<<endl<<endl;
    cout<<"The number of nodes are : "<<numNodes(root)<<endl;
    delete root;
    return 0;
}