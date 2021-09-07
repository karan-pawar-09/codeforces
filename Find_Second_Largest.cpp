/*
author:Karan
created:02.09.2021 17:13:27
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
	ll a, b, c;
	cin>>a>>b>>c;
	set<ll,greater<ll>> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);    
    s.erase(s.begin());
    cout<<*s.begin()<<endl;
	return 0;
}