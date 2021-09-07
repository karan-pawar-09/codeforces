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
    vector<bool> arr(n);
    ll minus=0;;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s;
        if(s=="AND") {
            arr[i]=true;
            minus+=(ll)(1<<(i+1));
        }
        else {
            arr[i]=false;
        }
    }
    int last=n;
    for(int i=n-1;i>=0;i--) {
        if(arr[i]) {
            last=i;
            break;
        }
    }
    
    if(last!=n) {
       int ans=(ll)1<<n+1;
       cout<<ans-1-minus;
    }
    else {
        ll ans=(ll)1<<n+1;
        cout<<ans-1<<endl;
    }
}