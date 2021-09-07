#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t;
    cin>>n>>t;
    int k;
    cin>>k;
    ll l=-1;
    ll r=n;
    ll sum;
    while(l+1<r) {
        ll m=l+(r-l)/2;        
        cout<<"? "<<"1 "<<m+1<<endl;
        cout.flush();
        cin>>sum;
        ll zeros=m-sum+1;
        if(zeros>=k) {
            
            r=m;
        }
        else {
            l=m;
        }
    }
    if(r==n) {
        cout<<"-1"<<endl;
        return 0;
    }
    else {
        cout<<"! "<<r+1<<endl;
        return 0;
    }
}