#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        vector<int> b(n);
        for(int i=0;i<n;i++) {
            cin>>b[i];
        }
        sort(b.begin(),b.end());
        sort(a.begin(),a.end());
        for(int i=0;i<k;i++) {
            if(a[0]>=b[n-1]) {
                break;
            }
            else{
                int temp=a[0]; 
                a[0]=b[n-1];
                b[n-1]=temp;
                sort(a.begin(),a.end());
                sort(b.begin(),b.end());
            }
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            ans+=a[i];
        }
        cout<<ans<<endl;
    }
}