/*
    author:Karan
    created:15.01.2023 19:02:08
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

const int inf = 1e9+10;
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> v;
    vector<pair<int, char>> freq(26);
    for(int i=0;i<26;i++) {
        freq[i] = {0, 'a'+i};
    }
    for(auto x: s) {
        freq[(int)(x-'a')].first++;
    }
    sort(all(freq), greater<pair<int, char>>());
    for(int i=1;i<=n;i++) {
        if(n%i == 0) {
            v.push_back(i);
        }
    }
    int mini = inf;
    int length = -1;
    for(auto x: v) {
        int len = n/x;
        int temp = 0;
        if(len <= 26) {
            for(int i=0;i<len;i++) {
                if(freq[i].first >= x) {

                } else {
                    temp += x- freq[i].first;
                }
            }
            if(temp < mini) {
                length = len;
                mini = temp;
            }
        }
    }
    cout<<mini<<endl;
    vector<pair<char, pair<int, int>>> us(length);
    for(int i=0;i<length;i++) {
        int val = min(freq[i].first, n/length);
        us[i] = {freq[i].second, {val, (n/length)-val}};
    }
    // for(int i=0;i<length;i++) {
    //     cout<<us[i].first<<" "<<us[i].second.first<<" "<<us[i].second.second<<endl;
    // }
    string ans;
    for(auto x: s) {
        bool kx = true;
        char c = us[length-1].first;
        int indexx = 0;
        for(int i=0;i<length;i++) {
            indexx = i;
            if(us[i].second.first > 0) {
                if(us[i].first == x) {
                    kx = false;
                    c = us[i].first;
                    break;
                }  
            }
        }
        if(kx) {
            for(int i=0;i<length;i++) {
                indexx = i;
                if(us[i].second.second > 0) {
                    c = us[i].first;
                    break;
                }
            }
        }
        if(kx) {
            us[indexx].second.second--;
        } else {
            us[indexx].second.first--;
        }
        ans.push_back(c);
    }
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}