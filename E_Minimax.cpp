/*
author:Karan
created:17.07.2021 22:21:28
*/

//cvkcup -> cck
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    string s;
    cin>>s;
    int n=s.size();
    vector<int> freq(26,0);
    for(int i=0;i<n;i++) {
        freq[s[i]-'a']++;
    }
    map<char,int> M;
    for(int i=0;i<n;i++) {
        M[s[i]]++;
    }
    int first=0;
    int second=27;
    for(int i=0;i<26;i++) {        
        if(freq[i]>0) {
            first=i;
            break;
        }
    }
    for(int i=first+1;i<26;i++) {
        if(freq[i]>0) {
            second=i;
            break;
        }
    }
    vector<int> ans;
    if(freq[first]>1) {
        ans.push_back(first);
        freq[first]--;
    }
    while(first<26&&second<26) {
        if(freq[first]>0) {
            ans.push_back(first);
            freq[first]--;
            if(freq[second]>0) {
                ans.push_back(second);
                freq[second]--;
            }
            else {
                second=27;
                for(int i=first+1;i<26;i++) {
                    if(freq[i]>0) {
                        second=i;
                        break;
                    }
                }
            }
        }
        else {
            first=27;
            second=27;
            for(int i=first;i<26;i++) {
                if(freq[i]>0) {
                    first=i;
                    ans.push_back(first);
                    freq[first]--;
                    break;
                }
            }
            for(int i=first+1;i<26;i++) {
                if(freq[i]>0) {
                    second=i;
                    break;
                }
            }
        }
    } 
    for(int i=0;i<26;i++) {
        while(freq[i]>0) {
            ans.push_back(i);
            freq[i]--;
        }
    }
    for(int i=0;i<ans.size();i++) {
        cout<<(char)('a'+ans[i]);
    }
    cout<<endl;
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