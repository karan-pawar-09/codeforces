/*
    author:Karan
    created:19.03.2022 20:08:31
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
   int n;
   cin>>n;
   vector<int> arr(n);
   vector<int> odd;
   vector<int> even;
   for(int i=0;i<n;i++) {
       cin>>arr[i];
       if(arr[i]%2==0) {
           even.push_back(arr[i]);
       } else {
           odd.push_back(arr[i]);
       }
   } 
   int oddpair=odd.size()-1;
   if(oddpair>0) {
       if(oddpair%2) {
            for(auto x:odd) {
                cout<<x<<" ";
            } 
            for(auto x:even) {
                cout<<x<<" ";
            }
            cout<<endl;
       } else {
           if(even.size()) {
               for(int i=0;i<odd.size()-1;i++) {
                   cout<<odd[i]<<" ";
               }
               cout<<even[0]<<" ";
               cout<<odd[odd.size()-1]<<" ";
               for(int i=1;i<even.size();i++) {
                   cout<<even[i]<<" ";
               }
               cout<<endl;
           } else {
               cout<<-1<<endl;
           }
       }
   } else {
       cout<<-1<<endl;
   }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}

/*


*/