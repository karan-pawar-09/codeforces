#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool is_distinct(string s) {
    int n=s.size();
    bool ans=true;
    sort(s.begin(),s.end());
    for(int i=1;i<n;i++) {
        if(s[i]==s[i-1]) {
            ans=false;
            break;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int y;
    cin>>y;
    y++;
    bool ans=false;
    while(!ans) {
        string a;
        a=to_string(y);
        if(is_distinct(a)) {
            cout<<a<<endl;
            ans=true;
            break;
        }
        y++;
    }
}