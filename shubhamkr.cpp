#include<bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<string> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        for(int j=0;j<arr[i].size();j++) {
            if(arr[i][j]<'a') {
                arr[i][j]=arr[i][j]+32;
            }
        }
    }
    string s = arr[0];
    int len = s.length(); 
    string res = "";    
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j <= len; j++) {
            string stem = s.substr(i, j);
            int k = 1;
            for (k = 1; k < n; k++) {
                if (arr[k].find(stem) == std::string::npos)
                    break;
            }
            if (k == n && res.length() < stem.length())
                res = stem;
        }
    } 
    cout<<res<<endl;
}