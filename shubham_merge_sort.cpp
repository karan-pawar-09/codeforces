/*
author:Karan
created:28.05.2021 13:01:48
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll cnt;
void merge(ll arr[], ll l, ll m, ll r) {
    ll n1 = m - l + 1;
    ll n2 = r - m;
    ll L[n1], R[n2]; 
    for (ll i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (ll j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    ll i = 0;
    ll j = 0;
    ll k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            cnt+=n1-i;
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(ll arr[],ll l,ll r) {
    if(l>=r){
        return;
    }
    ll m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

int main() {
    cnt=0;
    ll n=100000;
    ll a[n];
    for(ll i=0;i<n;i++)    cin>>a[i];
    mergeSort(a,0,n-1);
    cout<<cnt;
    return 0;
}