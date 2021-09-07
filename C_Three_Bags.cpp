#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    vector<ll> a1(n1);
    vector<ll> a2(n2);
    vector<ll> a3(n3);
    vector<ll> combined;
    ll sum=0;
    ll sc1,sc2,sc3,sc4,sc5,sc6;
    sc4=sc5=sc6=0;
    for(int i=0;i<n1;i++) {
        cin>>a1[i];
        combined.push_back(a1[i]);
        sum+=a1[i];
        sc4+=a1[i];
    }
    for(int i=0;i<n2;i++) {
        cin>>a2[i];
        combined.push_back(a2[i]);
        sum+=a2[i];
        sc5+=a2[i];
    }
    for(int i=0;i<n3;i++) {
        cin>>a3[i];
        combined.push_back(a3[i]);
        sum+=a3[i];
        sc6+=a3[i];
    }    
    sc1=*min_element(a1.begin(),a1.end());
    sc2=*min_element(a2.begin(),a2.end());
    sc3=*min_element(a3.begin(),a3.end());
    int maxi=max({sc1,sc2,sc3});
    int final=min({(sc1+sc2+sc3-maxi),sc4,sc5,sc6});
    cout<<sum-2*final;
}