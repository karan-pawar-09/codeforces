/*
author:Karan
created:08.07.2021 12:54:06
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

string RemoveLetters(string s, vector<char> letters) {
    vector<bool> freq(128,true);
    int n=letters.size();
    for(int i=0;i<n;i++) {
        freq[letters[i]]=false;
    }
    string ans;
    for(int i=0;i<s.size();i++) {
        if(freq[s[i]]) {
            ans.push_back(s[i]);
        }
    }
    return ans;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    string s;
    getline(cin,s);
    int n;
    cin>>n;
    vector<char> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    string ans=RemoveLetters(s,arr);
    cout<<ans<<endl;
}