#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,t,c;
    cin>>n>>m>>t>>c;    
    vector<int> v[n+1];
    for(int i=0; i<m; i++) {
        int x,y; cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }    
    vector<int> time(n+1,1e9);
    set<pair<int,int>> s;
    time[1]=0;
    s.insert({0,1});
    while(!s.empty()) {
        pair<int,int> p=*s.begin();
        s.erase(p);    
        int tim=p.first;
        if((max(tim-1,0)/t)%2) {
            tim+=(((max(tim-1,0)/t)+1)*t-tim);
        }   
        int t1 = tim+c;        
        for(auto i: v[p.second]) {
            if(t1<time[i]) {
                s.insert({t1,i});
                time[i]=t1;
            }
        }
    }
    cout<<time[n]<<endl;
}