#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool isGood(ll a,ll d) {
   int ans=d;
   int k=1;
   if(a>=10*d) {
       return true;
   }
   while(k*d<=a) {
       ans=d*k;
       if(ans%10==a%10){
           break;
       }
       k++;
   }
   if(ans<=a&&ans%10==a%10) {
       return true;
   }
   else {
       return false;
   }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int q,d;
        cin>>q>>d;
        for(int i=0;i<q;i++) {
            int element;
            cin>>element;
            if(isGood(element,d)) {
                cout<<"YES"<<endl;
            }
            else {
                cout<<"NO"<<endl;
            }
        }
        
    }
}