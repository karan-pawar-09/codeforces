
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()


void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int>> arr(27);
    for(int i=0;i<n;i++) {
        arr[s[i]-'a'].push_back(i);
    }

    int ans = 1;
    int start;
    for(auto x: arr) {
        vector<int> ar = x;
 
        int count = 1;
        if(ar.size()) {
            start = ar[0];
            for(int i=1;i<ar.size();i++) {
                if(ar[i]-ar[i-1] <= 2) {
                    count++;
                } else {
                    count = 1;
                    start = ar[i];
                }

                ans = max(ans, count*2 - (ar[i]-start+1));
            }
        }
     
    }
    cout<<ans<<endl;
}

int32_t main() {
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}