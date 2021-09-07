#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,p;
    cin>>n>>p;
    string a;
    cin>>a;
    int cost=0;
    vector<int>ss;
    int ps=p-1;
    for(int i=0;i<n/2;i++) {
        if(a[i]!=a[n-1-i]) {
            cost+=min(abs(a[i]-a[n-1-i]),26-abs(a[i]-a[n-1-i]));
            
            if(p<=n/2) {
                ss.push_back(i);
            }
            else{
                ss.push_back(n-1-i);
            }
        }        
    }

    if(ss.empty()){
        cout<<cost;
    }
    else{
        int aps=*min_element(ss.begin(),ss.end());
        int apa=*max_element(ss.begin(),ss.end());
        if(aps>ps){
            aps=ps;
        }
        if(apa<ps) {
            apa=ps;
        }

        cost+=min(abs(ps-aps+apa-aps),abs(apa-ps+apa-aps));

        cout<<cost;
    }
}