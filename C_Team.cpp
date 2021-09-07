/*
author:Karan
created:21.06.2021 12:20:11
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll zeros,ones;
    cin>>zeros>>ones;
    if((zeros>ones+1)||(zeros<((ones+1)/2)-1)) {
        cout<<"-1"<<endl;;
    }
    else {
        if(zeros>ones) {
            ll length=0;
            while(length+2<zeros+ones) {
                cout<<0<<1;
                length+=2;
            }
            cout<<0<<endl;
        }
        else {
            ll length=0;
            ll n=zeros+ones;
            string s;
            while(ones||zeros) {
                if(ones>zeros) {
                    vector<ll> ar={1,1,0};
                    for(ll i=0;n-length>0&&i<3;i++) {
                        length++;
                        s+=to_string(ar[i]);
                        if(i<2) ones--;
                        else zeros--;
                        if(zeros==ones) {
                            break;
                        }
                    }
                }
                else {
                    vector<ll> ar={0,1};
                    while(n-length>0) {
                        length++;
                        if(s.back()=='1') {
                            s.push_back('0');
                            zeros--;
                        }
                        else {
                            s.push_back('1');
                            ones--;
                        }
                    }
                }
            }
            cout<<s<<endl;
        }
    }
}