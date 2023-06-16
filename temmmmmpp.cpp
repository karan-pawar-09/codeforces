/*
    author:Karan
    created:04.06.2023 21:57:55
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    int temp = 1;
    set<int> rem;
    for(int i=1;i<=n*m;i++) {
        rem.insert(i);
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            arr[i][j] = temp;
            rem.erase(temp);
            temp+=2;
            if(temp > n*m) {
                break;
            }
        }
        if(temp > n*m) {
            break;
        }
    }
 
    
    for(int j=0;j<m;j++) {
        arr[n/2][j] = arr[(n/2)-1][j]+1;
        if(rem.count(arr[(n/2)-1][j]+1))
            rem.erase(arr[(n/2)-1][j]+1);
    }
    for(int i=(n/2)+1;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(rem.size())
                arr[i][j] = *rem.begin();
            if(rem.size())
            rem.erase(rem.begin());
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}