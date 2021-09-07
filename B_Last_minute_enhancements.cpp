#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int ans = 0;
        int prv = 0; 
        int ok = 0;	
        for(int i = 0;i<n;i++) {
            int a;
            cin>>a;           
            ans += (a != prv);
            ok |= (a == prv);
            
            if(prv + 1 < a)
                ans += ok, ok = 0;
            prv = a;
        }
        
        ans += ok;
        cout<<ans<<endl;
    }
}