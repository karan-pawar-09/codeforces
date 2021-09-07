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
        int one=0;
        int two=0;
        int three=0;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            if(arr[i]==1) {
                
                one++;
            }
            else if(arr[i]==2) {
          
                two++;
            }
            else {
                arr[i]=2;
                three++;
               
            }
        }
    
        cout<<one+three<<endl;
    }
}   