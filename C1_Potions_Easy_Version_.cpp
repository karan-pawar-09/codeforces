/*
author:Karan
created:28.05.2021 21:01:53
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
	cin>>n;
	multiset<ll> r;
	ll sum=0;
	for(ll i=0; i<n; i++){
		ll x;
		cin >> x;
		if(x+sum >= 0){
			r.insert(x);
			sum += x;
		} else if(!r.empty() && x>=(*r.begin())){
			sum -= (*r.begin());
			r.erase(r.begin());
			sum += x;
			r.insert(x);
		}
	}
	cout<<r.size()<<endl;
}