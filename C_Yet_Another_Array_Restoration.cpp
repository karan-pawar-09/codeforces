#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n,x,y;
        cin>>n>>x>>y;
        ll p=n-1;
        ll d;
        for(p;p>=1;p--) {
            if((x-y)%p==0) {
                break;
            }
        }
        d=(y-x)/p;
        
        ll start = y-d*(n-1);
        while(start<=0) {
            start+=d;
        }
        for(int i=0;i<n;i++) {
            cout<<start+i*d<<" ";
        }
        cout<<endl;
    }
}