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
    while(t--){
        int n;
        cin>>n;
        ll sum=0;
        n=n+2;
        vector<ll> b(n);
        for(int i=0;i<n;i++) {
            cin>>b[i];
            sum+=b[i];
        }
        sort(all(b));
        bool ans=false;
        for(int i=0;i<n&&!ans;i++) {
            ll k=b[i];
            ll sumtemp=sum-k;
            b[i]=0;
            if(i!=n-1) {
                if(sumtemp==b[n-1]*2) {
                    for(int j=0;j<n-1;j++) {
                        if(b[j]!=0) {
                            cout<<b[j]<<" ";
                        }                       
                        
                    }
                    ans=true;
                }
            }
            else {
                if(sumtemp==b[n-2]*2) {
                    for(int j=0;j<n-2;j++) {
                        if(b[j]!=0) {
                            cout<<b[j]<<" ";
                        }
                        
                    }
                    ans=true;
                }
            }
            b[i]=k;
        }
        if(!ans) {
            cout<<"-1";
        }
        cout<<endl;
    }
}