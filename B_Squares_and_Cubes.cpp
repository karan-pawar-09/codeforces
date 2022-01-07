/*
    author:Karan
    created:20.12.2021 20:57:38
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

bool checkperfectsquare(int n) {
    if (ceil((double)sqrt(n)) == floor((double)sqrt(n))) {
        return true;
    }
    else {
        return false;
    }
}
void solve() {
    int n;
    cin>>n;
    int a=0;
    int b=0;
    int c=0;
    for(int i=1;i<=n;i++) {
        if(i*i > n) {
            break;
        } else {
            a++;
        }
    }
    for(int i=1;i*i*i<=n;i++) {
        b++;
    }
    for(int i=1;i*i*i <=n ;i++) {
        if(checkperfectsquare(i*i*i)) {
            c++;
        }
    }
    cout<<a+b-c<<endl;
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