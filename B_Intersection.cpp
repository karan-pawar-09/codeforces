#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<ll> arr(n),b(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }
    ll l=*max_element(all(arr));
    ll r=*min_element(all(b));
    if(l>r) {
        cout<<"0"<<endl;
    }
    else{
        if(l==r) {
            cout<<"1"<<endl;
        }
        else {
            cout<<(r-l)+1<<endl;
        }
    }
}