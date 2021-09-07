#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    ll arr[n];
    ll questions[m];
    vector<ll>ans(n+1,0);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    for(int i=0;i<m;i++) {
        cin>>questions[i];
    }
    ans[1]=arr[0];
    for(int i=2;i<=n;i++) {
        ans[i]=ans[i-1]+arr[i-1];
    }
    for(int i=0;i<m;i++) {
        int answer = lower_bound(ans.begin(),ans.end(),questions[i])-ans.begin();
        cout<<answer<<" "<<questions[i]-ans[answer-1]<<endl;
    }
}   