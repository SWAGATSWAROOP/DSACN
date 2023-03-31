#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<climits>
using namespace std;

class com{
    public:
    bool operator()(pair<int,int> s,pair<int,int> k){
        return s.second>k.second;
    }
};

void DijAlgo(vector<pair<int,int> >v[],int s,int d){
    vector<bool> ll(d,false);
    pair<int,int> q(s,0);
    priority_queue<pair<int,int>,vector<pair<int,int> >,com> pq;
    pq.push(q);
    while(!pq.empty()){
        int m = pq.top().first;
        int k = pq.top().second;
        pq.pop();
        if(ll[m])continue;
        ll[m] = true;
        cout<<m<<"-"<<k<<"  ";
        for(auto x:v[m]){
            if(!ll[x.first]){
                int o = k+x.second;
                pair<int,int> p(x.first,o);
                pq.push(p);
            }
        }
    }
    cout<<"\n";
    return; 
}

void addedge(vector<pair<int,int> > v[],int s,int d,int f){ // Directed
    pair<int,int> k(d,f);
    pair<int,int> o(s,f);
    v[s].push_back(k);
    v[d].push_back(o);
}

int main(){
    int n,e,l;
    cout<<"Enter the number edges of graph:-";
    cin>>n;
    vector<pair<int,int> > v[n];
    cout<<"Enter the number of edges:- ";
    cin>>e;
    while(e--){
        int s,d,f;
        cout<<"Enter the vertex between whose edges are present:-";
        cin>>s>>d;
        cout<<"Enter the weight :- ";
        cin>>f;
        addedge(v,s,d,f);
    }
    cout<<"Enter the starting index:- ";
    cin>>l;
    DijAlgo(v,l,n);
    return 0;
}