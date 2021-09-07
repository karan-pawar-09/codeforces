#include<bits/stdc++.h>
using namespace std;
#define ll long long  

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p,q,r,s;
    ll t;
    cin>>p>>q>>r>>s>>t;
    ll ans=0;
    vector<ll>A(p);
    vector<ll>B(q);
    vector<ll>C(r);
    vector<ll>D(s);
    for(int i=0;i<p;i++) {
        cin>>A[i];
    }
    for(int i=0;i<q;i++) {
        cin>>B[i];
    }
    for(int i=0;i<r;i++) {
        cin>>C[i];
    }
    for(int i=0;i<s;i++) {
        cin>>D[i];
    }    
    vector<ll>sum(r*s);
    int okk=0;
    for(int i=0;i<r;i++) {
        for(int j=0;j<s;j++) {
            sum[okk++]=C[i]+D[j];
        }
    }
    sort(sum.begin(),sum.end());
    for(int i=0;i<p;i++) {
        for(int j=0;j<q;j++) {
            ll kk=A[i]+B[j];
            ll remainder= t-kk;
            if(remainder>=0) {
                ans+=((upper_bound(sum.begin(),sum.end(),remainder)-sum.begin()));
            }
        }
    }
    cout<<ans<<endl;
}
 