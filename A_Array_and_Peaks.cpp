#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void swap(int &a,int &b) {
    int x=a;
    a=b;
    b=x;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        if(2*k>(n-1)) {
            cout<<"-1"<<endl;
        }
        else {
            vector<ll> ans(n);
            for(int i=0;i<n;i++) {
                ans[i]=i+1;
            }
            int s=0;
            for(int i=0;i<n;i++) {
                if(s<k) {
                    if((i-1)%2==1&&i!=1) {
                        swap(ans[i],ans[i-1]);
                        s++;
                    }                    
                }
                else{
                    break;
                }
            }
            for(int i=0;i<n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }
}