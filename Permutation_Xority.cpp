/*
    author:Karan
    created:02.03.2022 20:11:24
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
    int xorr=0;
    if(n%2) {
        for(int i=1;i<=n;i++) {
            if(i>1) {
                xorr^=(1);
            }
            cout<<i<<" ";
        } cout<<endl;
        assert(xorr==0);
    } else {
        if(n==2) {
            cout<<-1<<endl;
            return;
        }
        vector<int> ans;
        for(int i=1;i<=n-3;i++) {
            ans.push_back(i);
        }
        ans.push_back(n);
        ans.push_back(n-2);
        ans.push_back(n-1);
        for(int i=1;i<n;i++) {
            xorr^=abs(ans[i]-ans[i-1]);
        }
        for(auto x:ans) {
            cout<<x<<" ";
        }
        cout<<endl;
        assert(xorr==0);
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



// 1423
// 2314
// 3241
// 4132






// 123645
// 124365
// 124563
// 124635
// 125643
// 142563
// 146325
// 154263
// 152643
// 162453
// 162435
// 162345
// 213654
// 214356
// 231456
// 234516
// 235164
// 243516
// 241356
// 254136
// 251634
// 256314
// 263154
// 261354
// 321465
// 324615
// 326415
// 316245
// 341625
// 346251
// 346521
// 354261
// 364125
// 365421
// 365241
// 362451
// 423516
// 431256
// 431526
// 436152
// 413652
// 412356
// 412536
// 415326
// 453162
// 451362
// 456312
// 461532
// 523641
// 521463
// 526143
// 534261
// 536421
// 543261
// 542613
// 546321
// 514623
// 516423
// 563421
// 564123
// 623514
// 625134
// 635214
// 631452
// 653412
// 653214
// 653142
// 654132
// 652134
// 615432
// 615342
// 615324