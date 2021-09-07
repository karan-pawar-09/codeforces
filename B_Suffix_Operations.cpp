#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
      for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++) {
        sum+=arr[i];
    }
    int avg=sum/n;
    int ansmax=0;
    int maxi=0;
    for(int i=0;i<n;i++) {
        if(abs(arr[i]-avg)>=maxi) {
            maxi=abs(arr[i]-avg);
            ansmax=i;
        }
    }
    if(ansmax!=0) {
        arr[ansmax]=arr[0];
    }
    else {
        arr[ansmax]=arr[1];
    }
    set<int>s;    
    for(int i=0;i<n;i++) {
        s.insert(arr[i]);
    }
    sum=0;
    for(auto i:s) {
        sum+=i;
    }
    avg=sum/s.size();
    int mini=(int)1e9+7;
    int ansmin=*(s.begin());
    for(auto i:s) {
        if(abs(i-avg)<=mini) {
            mini=abs(i-avg);
            ansmin=i;
        }        
    }
    int aa=0;
    int bb=0;
    for(auto i:s) {
        aa+=abs(ansmin-i);
    }
    for(auto i:s) {
        bb+=abs(i-avg);
    }
    cout<<min(aa,bb)<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}   