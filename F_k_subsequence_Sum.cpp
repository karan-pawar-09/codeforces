#include<bits/stdc++.h>
using namespace std;
#define ll long long

int minS(vector<ll> arr, int n, int k) 
{ 
    int res = 0; 
    for (int i=0; i<k; i++) 
       res += arr[i]; 
    int curr_sum = res; 
    for (int i=k; i<n; i++) 
    { 
       curr_sum += arr[i] - arr[i-k]; 
       res = min(res, curr_sum); 
    } 
     for (int i=0; i<k; i++)  { 
       curr_sum += arr[i] - arr[n-k+i]; 
       res = min(res, curr_sum); 
    }   
    return res; 
} 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    
    for(int i=0;i<q;i++) {
        int a;
        cin>>a;
        if(a==1) {
            int b;
            int c;
            cin>>b;
            cin>>c;
            arr[b-1]=c;
        }
        else{
            int k;
            cin>>k;
            cout<<minS(arr,n,k)<<endl;
        }
    }

}