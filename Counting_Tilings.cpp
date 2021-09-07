/*
author:Karan
created:07.08.2021 14:04:23
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;   cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)  cin>>arr[i];
    int k;   cin>>k;
    for(int i=0;i<n;i++)   cout<<arr[i]<<" ";
    cout<<endl;
    // RotateArrayClockwise(arr,n,k);

    vector<int> v(n);
    int pos = (n-k%n)%n;
    int i = pos;
    int x=0;
    cout<<pos<<endl;
    do {
        v[x++] = arr[i%n];
        i = (i+1)%n;
    }
    while(i!=pos);

    for(int i=0;i<n;i++)   cout<<v[i]<<" ";
}