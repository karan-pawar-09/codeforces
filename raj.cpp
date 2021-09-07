#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool check(string a) {
    vector<bool> arr(10);
    for(int i=0;i<a.size();i++){
        arr[a[i]-'0']=true;
    }
    bool ans=true;
    for(int i=0;i<10;i++) {
        if(!arr[i]) {
            ans=false;
            break;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool loop=true;
    ll n=1;
    ll ans=0;
    while(loop) {
        int sq=n*n;
        int cu=sq*n;
        string k=to_string(sq)+to_string(cu);
        if(check(k)) {
            loop=false;
            ans=n;
            break;
        }
        n++;
    }
    cout<<ans<<endl;
}