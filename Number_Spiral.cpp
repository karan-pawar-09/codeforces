#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        ll y,x;
        cin>>x>>y;
        if(x>=y) {
            if(x%2) {
                ll x0=((x-1)*(x-1))+1;
                cout<<x0+y-1<<endl;
            }
            else {
                cout<<(x*x)-y+1<<endl;
            }
            
        }
        else {
            if(y%2) {
                cout<<(y*y)-x+1<<endl;
            }
            else {
                ll y0=((y-1)*(y-1))+1;
                cout<<y0+x-1<<endl;
            }
        }
    }
}