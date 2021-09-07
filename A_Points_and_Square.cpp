#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<ll>length(n);
    vector<ll>breadth(n);
    for(int i=0;i<n;i++) {
        cin>>length[i]>>breadth[i];
    }  
    ll xmin=*min_element(breadth.begin(),breadth.end());
    ll xmax=*max_element(breadth.begin(),breadth.end());
    ll ymin=*min_element(length.begin(),length.end());
    ll ymax=*max_element(length.begin(),length.end());
    ll l=abs(xmax-xmin);
    ll b=abs(ymax-ymin);
    cout<<max(l,b)<<endl;
}
