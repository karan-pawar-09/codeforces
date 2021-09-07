#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> arr(26,0);
    for(int i=0;i<n;i++) {
        arr[s[i]-'a']++;
    }
    int odd=0;
    for(int i=0;i<26;i++) {
        if(arr[i]%2) {
            odd++;
        }
    }
    cout<<odd-1<<endl;
}       