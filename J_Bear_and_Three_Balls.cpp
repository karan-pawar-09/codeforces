#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    set<int> arr;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        arr.insert(k);
    }
    bool ans=false;
    vector<int> ar;
    for(auto itr=arr.begin();itr!=arr.end();itr++) {
        ar.push_back(*itr);
    }
    for(int i=1;i<ar.size()-1;i++) {
        if((ar[i]==(ar[i-1]+1))&&((ar[i]+1)==ar[i+1])) {
            ans=true;
            break;
        }
    }
    if(ans) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
}