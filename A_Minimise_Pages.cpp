#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int N;
    cin>>N;
    ll sum=0;
    vector<ll> arr(N);
    for(int i=0;i<N;i++) {
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum%(n*m)==0) {
        cout<<sum/(n*m)<<endl;
    }else {
        cout<<(sum/(n*m))+1<<endl;
    }
}