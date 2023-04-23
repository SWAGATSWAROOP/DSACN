#include<iostream>
using namespace std;

class Stack{
    private:
    int* arr;
    int n;
    int top1;
    int top2;

    public:
    Stack(){
        cout<<"Enter the size of the stack:- ";
        cin>>n;
        this->top1 = -1;
        this->top2 = n;
        arr = new int[n];
    }

    void push1(int e){
        if(top1+1 == top2)cout<<"OverFlow\n";
        else{
            arr[++top1] = e;
        }
    }

    void push2(int e){
    if(top2-1 == top1)cout<<"OverFlow\n";
        else{
            arr[--top2] = e;
        }
    }

    void pop1(){
        if(top1 == -1)cout<<"UnderFlow\n";
        else{
            cout<<arr[top1]<<" popped element\n";
            top1--;
        }
    }

    void pop2(){
        if(top2 == n)cout<<"UnderFlow\n";
        else{
            cout<<arr[top2]<<" popped element\n";
            top1++;
        }
    }

    void peek1(){
        if(top1 == -1)cout<<"UnderFlow\n";
        else cout<<arr[top1]<<endl;
    }

    void peek2(){
        if(top2 == n)cout<<"UnderFlow\n";
        else cout<<arr[top2]<<endl;
    }

    void Menu(){
        Swag:
        cout<<"Choice\n";
        cout<<"1.Push1\n2.Push2\n3.Pop1\n4.Pop2\n5.Peek1\n6.Peek2\n7.Break\n";
        int l;
        cin>>l;
        switch(l){
            case 1:
            int m;
            cin>>m;
            push1(m);
            break;

            case 2:
            int k;
            cin>>k;
            push2(k);
            break;

            case 3:
            pop1();
            break;

            case 4:
            pop2();
            break;

            case 5:
            peek1();
            break;

            case 6:
            peek2();
            break;

            default:
            return;
            break;
        }
        goto Swag;
    }
};

int main(){
    Stack a;
    a.Menu();
    return 0;
}