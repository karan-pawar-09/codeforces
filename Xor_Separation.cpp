/*
author:Karan
created:31.07.2021 20:38:12
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        vector<int> sum(n+1,0);
        sum[1]=arr[0];
        for(int i=2;i<=n;i++) {
            sum[i]=sum[i-1]+arr[i-1];
        }
        int no=1<<21;
        int ans=0;
        for(int i=0;i<=no;i+=2) {
            vector<int> nos;
            nos.push_back(1);
            for(int j=1;j<=21;i++) {
                if(i&(1<<j)) {
                    nos.push_back(j);
                }
            }
            nos.push_back(n);
            for(int j=1;j<nos.size();j++) {
                int su=sum[nos[j]]-sum[nos[j-1]-1];
                if(su%(1<<j)==0) {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}