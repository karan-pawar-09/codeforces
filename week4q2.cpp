/*
author:Karan
created:12.06.2021 17:35:44
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }  
    sort(all(arr));
    bool ans=false;
    for(int i=0;i<n;i++) {
        int count=1;
        while(i+1<n&&arr[i+1]==arr[i]) {
            count++;
            i++;
        }
        if(count>(n/2)) {
            ans=true;
            break;
        }
    }
    cout<<ans<<endl;
}