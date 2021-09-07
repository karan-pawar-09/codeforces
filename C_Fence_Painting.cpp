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
        ll n,m;
        cin>>n>>m;

        vector<ll> a(n),b(n),c(m),req(n),available(n),maxreq(n);

        vector<vector<ll>>ids(n+1);

        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        for(int i=0;i<n;i++) {
            cin>>b[i];
            if(b[i]!=a[i]) {
                req[b[i]]++;
                ids[b[i]].push_back(i);
            }
            maxreq[b[i]]++;
        }
        for(int i=0;i<m;i++) {
            cin>>c[i];
            available[c[i]]++;
        }
        
        bool ans=true;

        for(int i=0;i<n;i++) {
            if(available[i]<req[i]) {
                ans=false;
            }
        }

        if(maxreq[c[m-1]]==0) {
            ans=false;
        }

        if(ans) {
            cout<<"YES"<<endl;

        }
        else {
            cout<<"NO"<<endl;
        }
        
    }
} 