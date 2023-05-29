#include "/Users/swagatswaroopparida/stdc.h"
using namespace std;

pair<int,vector<int> > largestArea(int arr[],int n){
    stack<int> s;
    vector<int> a;
    for(int i=0;i<n;i++){
        while(!s.empty() && arr[s.top()]>=arr[i])s.pop();
        int l = s.empty() ? (i+1)*arr[i] : arr[i]*(i-s.top());
        s.push(i);
        a.push_back(l);
    }
    int mx = 0;
    while(!s.empty())s.pop();
    for(int i = n-1;i>=0;i--){
        while(!s.empty() && arr[s.top()]>=arr[i])s.pop();
        int l = s.empty() ? a[i] - arr[i] + (n-i)*arr[i] : a[i] - arr[i] + arr[i]*(s.top()-i);
        mx = max(mx,l);
        s.push(i);
        a[i] = l;
    }
    pair<int,vector<int> > p(mx,a);
    return p;
}

int main(){

    int n;
    cout<<"Enter the number of elements in array:- ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    pair<int,vector<int> > p = largestArea(arr,n);
    cout<<"Largerst Area of Rectangle: "<<p.first<<endl;
    return 0;
}