#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        ll a,b;
        cin>>a>>b;
        ll even1=a/2;
        ll even2=b/2;
        ll odd1=(a+1)/2;
        ll odd2=(b+1)/2;
        cout<<(even1*even2)+(odd1*odd2)<<endl;
    }
}