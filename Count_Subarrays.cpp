#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        ll ans=0;
        ll total=0;
        for(int i=1;i<n;i++) {
            if(arr[i]>=arr[i-1]) {
                ans++;
            }
            if(arr[i]<arr[i-1]||i==(n-1)){
                total+=((ans)*(ans+1))/2;
                ans=0;
            }

        }
        cout<<total+n<<endl;
    }
}