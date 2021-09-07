/*
author:Karan
created:03.09.2021 20:29:01
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    // int n;
    // cin>>n;
    // vector<string> arr(n);
    // for(int i=0;i<n;i++) {
    //     cin>>arr[i];
    // }
    // vector<int> freq(26,0);
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<arr[i].size();j++) {
    //         freq[arr[i][j]-'a']++;
    //     }
    // }
    // bool ans=true;
    // for(int i=0;i<26;i++) {
    //     if(freq[i]%n) {
    //         ans=false;
    //     }
    // }
    // ans?cout<<"YES"<<endl:cout<<"NO"<<endl;

        int n;
        cin>>n;
        vector<string> s(n);
        for(int i = 0; i < n; i++){
            cin>>s[i];
        }
        // for(int i = 0; i < n; i++){
        //     cout<<s[i]<<" ";
        // }
        // cout<<endl;


        vector<int> a(26,0);
        int k = 0;
        while(n--){
            cout<<n<<endl;
            cout.flush();
            for(int i = 0; i < s[i].length(); i++){
                a[s[k][i]-'a']++;
            }
            k++;
        }
        // for(int i = 0; i < 26; i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
        bool b = true;
        for(int i = 0; i < 26; i++){
            if(a[i]%n != 0){
                b = false;
                break;
            }
        }
        string res;
        if(b){
            res = "YES";
        }
        else{
            res = "NO";
        }

        cout<<res<<endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}