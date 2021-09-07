#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin>>q;
    while(q--) {
        string s,t;
        cin>>s;
        cin>>t;
        string k=s;
        string p=t;
        int ss=s.size();
        int tt=t.size();
        for(int i=0;i<ss/__gcd(ss,tt)-1;i++) {
            t+=p; 
        }
        for(int i=0;i<tt/__gcd(ss,tt)-1;i++) {
            s+=k;
        }
        if(s==t) {
            cout<<s<<endl;
        }
        else {
            cout<<"-1"<<endl;
        }
    }
}