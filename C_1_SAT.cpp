#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    set<string> s;
    vector<string> arr(n);
    string ans="satisfiable";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        if(arr[i][0]=='!') {
            s.insert(arr[i]);
        }
    }
    for(int i=0;i<n;i++) {
        if(arr[i][0]!='!') {
            if(s.find('!'+arr[i])!=s.end()) {
                ans=arr[i];
                break;
            }
        }
    }
    cout<<ans<<endl;
}