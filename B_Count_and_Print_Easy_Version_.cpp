#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p,q,r,s,t;
    cin>>p>>q>>r>>s>>t;
    int k=min({p,q,r,s});
    int z=1007;
    vector<int> A(z,0);
    vector<int> B(z,0);
    vector<int> C(z,0);
    vector<int> D(z,0);
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
    int ans=0;
    for(int i=0;i<k;i++) {
        if(A[i]+B[i]+C[i]+D[i]<=t) {
            ans++;
        }
    }
    cout<<ans<<endl;
}