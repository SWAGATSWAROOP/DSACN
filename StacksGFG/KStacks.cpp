#include<iostream>
using namespace std;

class St{
    int* arr;
    int* top;
    int* next;
    int freetop;

    public:
    St(int n,int k){
        arr = new int[n]; //Stack
        next = new int[n]; // Store index of previous element or next element;
        top = new int[k]; //Store index of top element
        freetop = 0; //For Current freespace
        for(int i=0;i<k;i++)top[i] = -1;
        for(int i=0;i<n-1;i++)next[i] = i+1;
        next[n-1] = -1;
    }

    void push(int element,int stackno){
        if(freetop == -1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        int index = next[freetop];
        next[freetop] = top[stackno];
        arr[freetop] = element;
        top[stackno] = freetop;
        freetop = index;
    }

    void pop(int stackno){
        if(top[stackno] == -1){
            cout<<"Stack Underflow\n";
            return;
        }
        cout<<arr[top[stackno]]<<endl;
        int index = next[top[stackno]];
        next[top[stackno]] = freetop;
        freetop = top[stackno];
        top[stackno] = index;
    }

    void menu(){
        cout<<"Enter the options:-\n 1.Push\n 2.Pop\n 3.top\n 4.exit"<<endl;
        int l,k;
        cout<<"Choose option and Stackno: ";
        cin>>l>>k;
        switch(l){
            case 1:
            int m;
            cout<<"Enter element: ";
            cin>>m;
            push(m,k);
            break;

            case 2:
            pop(k);
            break;

            case 3:
            cout<<top[k]<<endl;
            break;

            case 4:
            return;
            break;

            default:
            cout<<"Invalid Choice\n";
            break;
        }
        menu();
    }

    ~St(){
        delete[] arr;
        delete[] next;
        delete[] top; 
    }
};

int main(){

    int n,m;
    cout<<"Enter the number of elements in array: ";
    cin>>n;
    cout<<"Enter the number of stacks: ";
    cin>>m;
    if(n<m){
        cout<<"Not Possible\n";
        return 0;
    }
    St A(n,m);
    A.menu();
    return 0;
}