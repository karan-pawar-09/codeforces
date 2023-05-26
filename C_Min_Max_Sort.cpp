/*
    author:Karan
    created:24.01.2023 20:30:56
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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> pos(n+1);
    vector<bool> changed(n+1, false);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        pos[arr[i]] = i;
    }
    int count = n/2;
	if(n%2 == 0){
		int l = n/2,r = n/2 + 1;
		int p1 = -1,p2 = -1;
		while(l>=1 && r<= n && pos[l] < pos[r] && (p1 == -1 || pos[l]<p1 && pos[r]>p2)) {
            count--;
            p1 = pos[l];
            p2 = pos[r];
            l--;
            r++;
        }
	}
	else{
		int l = n/2 ,r = n/2 + 2;
		int p1 = pos[l+1],p2 = pos[l+1];
		while(l>=1 && r<= n && pos[l] < pos[r] && (p1 == -1 || pos[l]<p1 && pos[r]>p2))  {
            count--;
            p1 = pos[l];
            p2 = pos[r];
            l--;
            r++;
        }
	}
    cout<<count<<endl;
   
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}