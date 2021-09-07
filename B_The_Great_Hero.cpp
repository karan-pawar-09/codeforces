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
        ll A,B,n;
        cin>>A>>B>>n;
        vector<pair<ll,ll>> a(n);
        // vector<ll> b(n);
        for(int i=0;i<n;i++) {
            cin>>a[i].first;
        }
        ll monstersum=0;
        for(int j=0;j<n;j++) {
            cin>>a[j].second;
            monstersum+=a[j].second;
        }
        sort(all(a));
        bool ans=true;
        for(int i=0;i<n;i++) {
              if(B<=0) {
                ans=false;
                break;
            }
            ll k=(ll)ceil((double)a[i].second/A);
            ll p=(ll)ceil((double)B/a[i].first);
            if(p<k) {
                ans=false;
            }  
            B-=k*a[i].first;
            monstersum-=k*A;        
        }
        if(ans&&monstersum<=0) {
            cout<<"YES"<<endl;
        } 
        else {
            cout<<"NO"<<endl;
        }
    }
}