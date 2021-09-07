/*
authot:Karan
created:16.05.2021 17:11:27
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr(3);
    for(int i=0;i<3;i++) {
        cin>>arr[i];
    }
    sort(all(arr));
    if(arr[1]-arr[0]==arr[2]-arr[1]) {
        cout<<"Yes"<<endl;
    }
    else  {
        cout<<"No"<<endl;
    }
}