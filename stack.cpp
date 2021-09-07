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
 	int n;
 	cin>>n;
 	vector<int> arr(n);
 	for(int i=0;i<n;i++) {
 		cin>>arr[i];
 	}  
 	sort(all(arr));
 	for(auto x:arr) {
 		cout<<x<<endl;
 	}
}
