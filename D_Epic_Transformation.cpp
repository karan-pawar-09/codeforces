// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define all(ar) ar.begin(),ar.end()
// #define endl '\n'

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin>>t;
//     while(t--) {
//         int n;
//         cin>>n;
//         vector<ll> arr(n);
//         map<ll,ll> mp;
//         for(int i=0;i<n;i++) {
//             cin>>arr[i];
//             mp[arr[i]]++;
//         }
//         vector<int> v;
//         for(auto i=mp.begin();i!=mp.end();i++) {
//             v.push_back(i->second);
//         }  
//         sort(v.begin(), v.end());
//         int tt=n%2;
//         int ans=max(tt,n-(n-v[v.size()-1])*2);
//         cout<<ans<<endl;
//         }
// }




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
        map<ll,ll> mp;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            mp[arr[i]]++;
        }
        ll sum=0;
        for(auto i:mp) {
            sum+=i.second;
        }
        ll maxi=0;
        for(auto i:mp) {
            if(i.second>maxi) {
                maxi=i.second;
            }
        }
        cout<<max((ll)(n%2),((2*maxi)-sum))<<endl;        
    }
}