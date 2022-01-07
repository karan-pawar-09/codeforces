 /*
     author:Karan
     created:18.12.2021 21:06:03
 */
 #if true
 #pragma GCC target ("avx2")
 #pragma GCC optimization ("O3")
 #pragma GCC optimization ("unroll-loops")
 #include<bits/stdc++.h>
 using namespace std;
 #define ll long long
 #define all(ar) ar.begin(),ar.end()
 #define endl '\n'
 #define mset(a,x) memset(a,x,sizeof(a))
 #endif
 
 void solve() {
     string s;
     cin>>s;
     ll n=s.size();
     vector<ll> arr(n);
     ll temp=1e18+7;
     ll k=1000;
     while(k--) {
        for(ll i=0;i<n;i++) {
            if(s[i]=='E') {
                if(arr[(i+1)%n]==arr[i]) {

                }
                else {
                    arr[(i+1)%n]=arr[i];
                }
            } else {
                if(arr[(i+1)%n]==arr[i]) {
                    arr[(i+1)%n]=temp;
                    temp--;
                }
            }
        }
     }
     bool ans=true;
     for(ll i=0;i<n;i++) {
         if(s[i]=='E') {
             if(arr[(i+1)%n]!=arr[i]) {
                 ans=false;
                 break;
             }
         }
         else {
             if(arr[(i+1)%n]==arr[i]) {
                 ans=false;
                 break;
             }
         }
     }
     if(ans) cout<<"YES"<<endl;
     else cout<<"NO"<<endl;
 }
 
 int32_t main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     // freopen("input.txt","r",stdin);
     // freopen("output.txt","w",stdout);
     ll t=1;
     cin>>t;
     while(t--) {
         solve();
     }
 }