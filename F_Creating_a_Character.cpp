#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        ll str,inte,exp;
        cin>>str>>inte>>exp;
        ll add=((exp+inte-str+2)/2);
        add=max(0LL,add);
        ll t=exp-add+1;
        if(t>0) {
            cout<<t<<endl;
        }
        else{
            cout<<"0"<<endl;
        }
    }
}