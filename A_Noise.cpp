/*
authot:Karan
created:17.05.2021 10:29:15
*/
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
    vector<int> freq(26,0);
    for(int i=0;i<n;i++) {
        freq[s[i]-'a']++;
    }
    int ans=0;
    for(int i=0;i<26;i++) {
        if(freq[i]>1) {
            ans+=freq[i];
        }
    }
    cout<<ans<<endl;
}