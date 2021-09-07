#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        vector<ll> bob;
        vector<ll> alice;
        for(int i=0;i<n;i++) {
            if(arr[i]%2) {
                bob.push_back(arr[i]);
            }
            else {
                alice.push_back(arr[i]);
            }
        }
        sort(bob.begin(),bob.end(),greater<ll>());
        sort(alice.begin(),alice.end(),greater<ll>());
        ll aliceval=0;
        ll bobval=0;
        int aliceno=0;
        int bobno=0; 
        bool first=true;
        while(bobno<bob.size()||aliceno<alice.size()) {
            if(first) {
                if(aliceno<alice.size()) {
                    if(bobno<bob.size()) {
                        if(alice[aliceno]>=bob[bobno]) {
                            aliceval+=alice[aliceno];
                            aliceno++;
                        }
                        else {
                            bobno++;
                        }
                    }
                    else {
                        aliceval+=alice[aliceno];
                        aliceno++;
                    }                  
                }
                else {
                    bobno++;
                }
                first=!first;
            }
            else {
                if(bobno<bob.size()) {
                    if(aliceno<alice.size()) {
                        if(bob[bobno]>=alice[aliceno]) {
                            bobval+=bob[bobno];
                            bobno++;
                        }
                        else {
                            aliceno++;
                        }
                    }
                    else {
                        bobval+=bob[bobno];
                        bobno++;
                    }
                }
                else {
                    aliceno++;
                }
                first=!first;
            }
        }
        if(aliceval>bobval) {
            cout<<"Alice"<<endl;
        }
        else if(bobval>aliceval) {
            cout<<"Bob"<<endl;
        }
        else {
            cout<<"Tie"<<endl;
        }
    }
}