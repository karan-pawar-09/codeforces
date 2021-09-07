#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int x;
        cin>>x;
        int k=x;
        int floor=x%10;
        int ans=10*(floor-1);
        string a=to_string(x);
        int extra=(a.size()*(a.size()+1))/2;
        cout<<ans+extra<<endl;
    }
}