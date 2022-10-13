/*
    author:Karan
    created:12.08.2022 20:34:17
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

int getMaximumGeyness(vector<string> pixels) {
    int n = pixels.size();
    int m = pixels[0].size();
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++) {
        int sum =0;
        for(int j=0;j<m;j++) {
            sum+=(pixels[i][j]=='1');
        }
        a[i]=sum;
    }
    for(int i=0;i<m;i++) {
        int sum=0;
        for(int j=0;j<n;j++) {
            sum+=(pixels[j][i]=='1');
        }
        b[i]=sum;
    }
    int ans =0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            ans = max(ans, 2*(a[i]+b[j]) - (n+m) );
        }
    }
    return ans;
}
void solve() {
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<getMaximumGeyness(arr)<<endl;
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