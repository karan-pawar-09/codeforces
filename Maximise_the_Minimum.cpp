/*
    author:Karan
    created:26.01.2022 22:07:29
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

int a[41],b[41];
int apost[42],bpost[42];
int n,k;
int res;
void traverse(int i, int asum, int bsum, int used) {
    if(used==k) {
        res=max(res,min(asum,bsum));
        return;
    }
    if(used>k) {
        return;
    }
    if(i>=n) return;
    if((used+(n-i)) <= k) {
        if((used+n-i) <k) {
            return;
        } else {
            asum+=apost[i];
            bsum+=bpost[i];
            res=max(res,min(asum,bsum));
            return;
        }
    }
    traverse(i+1,asum,bsum,used);
    traverse(i+1,asum+a[i],bsum+b[i],used+1);
}

void solve() {   
    res=0; 
    cin>>n>>k;
    for(int i=41;i>=n;i--) {
        apost[i]=0;
        bpost[i]=0;
    }
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }
    apost[n-1]=a[n-1];
    bpost[n-1]=b[n-1];
    for(int i=n-2;i>=0;i--) {
        apost[i]=a[i]+apost[i+1];
        bpost[i]=b[i]+bpost[i+1];
    }
    traverse(0,0,0,0);
    cout<<res<<endl;
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