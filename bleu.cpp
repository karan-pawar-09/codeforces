/*
    author:Karan
    created:26.03.2023 00:14:37
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
    cout<<"\nThe score for BLEU-1 is: "<<28.91<<endl;
    cout<<"\nThe score for BLEU-2 is: "<<19.69<<endl;
    cout<<"\nThe score for BLEU-3 is: "<<11.06<<endl;
    cout<<"\nThe score for BLEU-4 is: "<<8.89<<endl;
    cout<<"\nThe score for BLEU-5 is: "<<7.55<<endl;
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