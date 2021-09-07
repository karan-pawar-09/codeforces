#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    vector<bool> is_prime(200, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= 200; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 200; j += i)
                is_prime[j] = false;
        }
    }
    while(t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++) {
            if(!is_prime[(int)s[i]]||(((int)s[i]<65||((int)s[i]>90)&&((int)s[i]<97)||(int)s[i]>122))) {
                int k=(int)s[i];
                int p=(int)s[i];
                bool ans=false;
                while(!ans) {
                    if((int)s[i]<=90) {
                        if(--k>=65) {
                            if(is_prime[k]&&k>=65&&k<=90) {
                                s[i]=(char)k;
                                ans=true;
                                break;                            
                            }
                        }
                        if(++p<=90) {
                            if(is_prime[p]&&p>=65&&p<=90) {
                                s[i]=(char)p;
                                ans=true;
                                break;
                            }
                        }
                    }
                    else if((int)s[i]>90&&(int)s[i]<97) {
                        if(abs(89-(int)s[i])<=abs(97-(int)s[i])) {
                            s[i]='Y';
                        }
                        else {
                            s[i]='a';
                        }
                    }
                    else {
                        if(--k>=97) {
                            if(is_prime[k]&&k>=97&&k<=122) {
                                s[i]=(char)k;
                                ans=true;
                                break;                            
                            }
                        }
                        if(++p<=122) {
                            if(is_prime[p]&&p>=97&&p<=122) {
                                s[i]=(char)p;
                                ans=true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        cout<<s<<endl;
    }
}   