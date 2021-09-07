#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
multiset<ll> ar;
multiset<ll> primeFactors(ll n)  
{  
    multiset<ll> s;  
    while (n % 2 == 0)  
    {  
        s.insert(2);
        n = n/2;  
    }  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        while (n % i == 0)  
        {  
            s.insert(i);
            n = n/i;  
        }  
    }   
    if (n > 2)  
        s.insert(n); 

    return s;
}  
void primeFactorsofNo(ll n)  
{  
     
    while (n % 2 == 0)  
    {  
        ar.insert(2); 
        n = n/2;  
    }  
  

    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
      
        while (n % i == 0)  
        {  
            ar.insert(i);  
            n = n/i;  
        }  
    }  
  
    
    if (n > 2)  
        ar.insert(n);  
}  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        ar.clear();
        int n;
        ll k;
        cin>>n>>k;
        vector<ll>arr(n);
        
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        multiset<ll> kk=primeFactors(k);
        for(int i=0;i<n;i++) {
            primeFactorsofNo(arr[i]);
        }
        bool ans=true;
        for(auto a:kk) {
            // if(kk.count(a)>ar.count(a)) {
            //     ans=false;
            // }
            cout<<a<<" ";
        }
        cout<<endl;
        for(auto b:ar) {
            cout<<b<<" ";
        }
        cout<<endl;
        if(ans) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
}