/*
author:Karan
created:14.06.2021 12:43:06
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
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }   
    sort(all(arr));
    bool ans=true;
    for(int i=0;i<n;i++) {
        if(arr[i]!=i+1) {
            ans=false;
            break;
        }
    }
    ans?cout<<"Yes"<<endl:cout<<"No"<<endl;
}