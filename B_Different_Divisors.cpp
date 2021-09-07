#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool countDivisors(ll n,ll d) { 
    ll cnt = 0; 
    vector<ll> arr;
    bool ans=true;
    for (ll i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) {          
            if (n / i == i) {
                cnt++; 
                arr.push_back(i);
            }
  
            else { 
                cnt = cnt + 2; 
                if(abs(n/i-i)>=d) {
                    arr.push_back(i);
                    arr.push_back(n/i);
                }
                else {
                    ans=false;
                }
            }
        } 
    } 
    // sort(all(arr));
    // for(ll i=1;i<arr.size();i++) {
    //     if(arr[i]-arr[i-1]<d) {
    //         ans=false;
    //         break;
    //     }
    }
    if(cnt<4) {
        ans=false;
    }
    return ans; 
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll d;
        cin>>d;
        ll l=4*d;
        
        while(!countDivisors(l,d)) {
            l++;
        }
        cout<<l<<endl;
    }
}
