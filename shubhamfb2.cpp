#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    cin>>a;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<string> stringg;
    stringg.push_back(a.substr(0,arr[0]));
    int sum=arr[0];
    for(int i=1;i<n;i++){
        stringg.push_back(a.substr((sum),arr[i]));
        sum+=arr[i];
    }
    for(int i=0;i<n/2;i++) {
        cout<<stringg[i*2+1]<<stringg[i*2];
    }
    if(n%2==1) {
        cout<<stringg[stringg.size()-1];
    }
}


