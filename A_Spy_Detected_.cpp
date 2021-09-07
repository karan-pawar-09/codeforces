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
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        vector<pair<int,int>> freq(101,{0,0});
        for(int i=0;i<n;i++) {
            freq[arr[i]].first++;
            freq[arr[i]].second=i+1;
        }
        int ans=1;
        for(int i=0;i<101;i++) {
            if(freq[i].first==1) {
                ans=freq[i].second;
                break;
            }
        }
        cout<<ans<<endl;
    }
}