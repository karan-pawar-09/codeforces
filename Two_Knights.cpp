/*
	author:Karan
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
 	ll n;
 	cin>>n;
 	for(ll i=1;i<=n;i++) {
 		cout<<((i*i)*((i*i)-1)-8-24-(16*(i-4))-16-((i-4)*24)-((i-4)*(i-4)*8))/2<<endl;
 	}
}
