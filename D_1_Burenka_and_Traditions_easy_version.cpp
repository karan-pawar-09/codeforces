/*
    author:Karan
    created:16.08.2022 21:00:23
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
    int n;
    cin>>n;
    vector<int> arr(n);
    int zeros = 0;
    vector<bool> a(n,false);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        if(arr[i]==0) {
            a[i] = true;
        }
    }
    vector<int> xorr(n);
    
    xorr[0]=arr[0];
    for(int i=1;i<n;i++) {
        xorr[i]=arr[i]^xorr[i-1];
    }
   
    int answer = n;
    int starting = 0;
    for(int j=0;j<n;j++) {
        if(arr[j]==0) {
            starting = j+1;
            answer--;
        }
        for(int i=starting;i<j;i++) {
                int xornow = xorr[j];
                if(i>0) {
                    xornow = xornow^xorr[i-1];
                }
                if(xornow == 0) {
                    starting = j+1;
                    answer --;
                }
            
        }
    }
    cout<<answer<<endl;
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