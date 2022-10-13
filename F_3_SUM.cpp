/*
    author:Karan
    created:14.06.2022 21:48:04
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
    int M[10];
    for(int i=0;i<10;i++) {
        M[i]=0;
    }
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        arr[i]%=10;
        M[arr[i]]++;
    }

    bool ans=false;

    for(int i=0;i<10;i++) {
        if(M[i]>0) {
            M[i]--;
            for(int j=0;j<10;j++) {
                if(M[j]>0) {
                    M[j]--;
                    for(int k=0;k<10;k++) {
                        if(M[k]>0) {
                            if((i+j+k)%10 ==3) {
                                ans=true;
                            }
                        }
                    }
                    M[j]++;
                }
            }
            M[i]++;
        }
    }
    if(ans) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
    
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

//1 1 1
//1 2 0
//3 0 0
//1 9 3
//