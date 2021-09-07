#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    // if(k==0) {
    //     cout<<"0"<<endl;
    //     return 0;
    // }
    if(k%n==0) {
        cout<<k/n<<endl;
    }
    else {
        cout<<ceil((double)(k+1e-9)/n)<<endl;
    }
}