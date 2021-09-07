/*
author:Karan
created:02.06.2021 16:03:52
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin>>x;
    ll arr[101];
    arr[0]=0;
    for(int i=1;i<101;i++) {
        if(i%2) {
            arr[i]=arr[i-1]+i;
        }
        else {
            arr[i]=arr[i-1]+i-1;
        }
    }
    if(x==3) {
        cout<<5<<endl;
    }
    else {
        for(int i=0;i<101;i++) {
            if(arr[i]>=x&&i%2) {
                cout<<i<<endl;
                break;
            }
        }
    }
    
}