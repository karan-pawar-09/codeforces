/*
    author:Karan
    created:20.05.2023 17:48:41
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

string makeString(int _i, int _j, vector<string> &arr) {
    string s;
    for(int i = 0; i < 5; i++) {
        s.push_back(arr[i+_i][_j+i]);
    }
    return s;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-4;j++) {
            string temp = arr[i].substr(j, 5);
            if(temp == "snuke") {
                for(int k=0;k<5;k++) {
                    cout<<i+1<<" "<<j+1+k<<endl;
                }
                return;
            }
            reverse(all(temp));
            if(temp == "snuke") {
                for(int k=0;k<5;k++) {
                    cout<<i+1<<" "<<j+1+k<<endl;
                }
                return;
            }
        }
    }
    for(int j=0;j<n;j++) {
        for(int i=0;i<n-4;i++) {
            string temp = "";
            for(int k = i; k<(5+i);k++) {
                temp.push_back(arr[k][j]);
            }
            if(temp == "snuke") {
                for(int k=0;k<5;k++) {
                    cout<<i+1+k<<" "<<j+1<<endl;
                }
                return;
            }
            reverse(all(temp));
            vector<pair<int, int>> ans;
            if(temp == "snuke") {
                for(int k=0;k<5;k++) {
                    ans.push_back({i+1+k, j+1});
                    
                }
                reverse(all(ans));
                for(auto x: ans) {
                    cout<<x.first<<" "<<x.second<<endl;
                }
                return;
            }
        }
    }
    for(int i=0;i<n-4;i++) {
        for(int j=0;j<n-4;j++) {
            string temp = makeString(i, j, arr);

            if(temp == "snuke") {
                for(int k=0;k<5;k++) {
                    cout<<i+1+k<<" "<<j+1+k<<endl;
                }
                return;
            }
            reverse(all(temp));
          
            if(temp == "snuke") {
                vector<pair<int, int>> ans;
                for(int k=0;k<5;k++) {
                    ans.push_back({i+1+k, j+1+k});
                    //cout<<i+1+k<<" "<<j+1+k<<endl;
                }
                reverse(all(ans));
                for(auto x: ans) {
                    cout<<x.first<<" "<<x.second<<endl;
                }
                return;
            }
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}