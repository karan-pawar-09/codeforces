#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()

int calcLength(int a) {
    int len = 0;
    while(a) {
        len++;
        a/=2;
    }
    return len;
}

string toBinary(int a, int n) {
    string s;
    for(int i=0;i<n;i++) {
        if(a & (1<<i)) {
            s.push_back('1');
        } else {
            s.push_back('0');
        }
    }
    reverse(all(s));
    return s;
}

void leftrotate(string &s, int d) {
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.end());
    reverse(s.begin(), s.end());
}
 
void rightrotate(string &s, int d) {
   leftrotate(s, s.length()-d);
}

int calcXOR(string &s1, string &s2) {
    int n = s1.size();
    int ans = 0;
    for(int i=0;i<n;i++) {
        int temp;
        if(s1[i] == s2[i]) {
            temp = 0;
        } else {
            temp = 1;
        }
        temp *= (1<<(n-1-i));
        ans += temp;
    }
    return ans;
}

void solve() {
    int a, b;
    cin>>a>>b;
    int n = max(calcLength(a), calcLength(b));
    string s1 = toBinary(a, n);
    string s2 = toBinary(b, n);
    int maxi = calcXOR(s1, s2);
    int ans = 0;
    for(int i=1;i<=n;i++) {
        rightrotate(s2,1);
        int temp = calcXOR(s1, s2);
        if(temp > maxi) {
            maxi = temp;
            ans = i;
        }
    }
    cout<<ans<<" "<<maxi<<endl;
}

int32_t main() {
    int t=1;
    while(t--) {
        solve();
    }
}