#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<bool> arr(n);
    for(int i=0;i<n;i++) {
        int n;
        cin>>n;
        bool temp;
        n==1?temp=true:temp=false;
        arr[i]=temp;
    }
    vector<bool>ans(n+1);
    ans[0]=!arr[0];
    for(int i=1;i<=n;i++) {
        ans[i]=arr[i-1];
    }
    vector<int>a;
    int cont=0;
    for(int i=1;i<n+1;i++) {
        if(ans[i]!=ans[i-1]) {
            a.push_back(cont);
            cont=1;
        }
        else{
            cont++;
        }
    }
    a.push_back(cont);
    vector<int> aa;
    for(int i=1;i<a.size();i++) {
        aa.push_back(min(a[i],a[i-1]));
    }
    cout<<(*(max_element(aa.begin(),aa.end()))*2)<<endl;
}