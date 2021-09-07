/*
author:Karan
created:11.06.2021 22:37:03
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll count_haha(string s) {
    ll count=0;
    if(s.size()>=4)
        for(ll i=0;i<s.size()-3;i++) {
            count+=s.substr(i,4)=="haha";
        }
    return count;
}
struct variable {
    ll len;
    ll haha;
    string first, last; 
    variable(string str="") {
        len=(ll) str.size();
        haha=count_haha(str);
        first=last=str;
        trim();
    }
    void trim() {
        if(first.size()>3) first=first.substr(0,3);
        if(last.size()>3) last=last.substr(last.size()-3);
    }
};

variable concat(variable &x, variable &y) {
    variable z;
    z.len=x.len+y.len;
    z.haha=x.haha+y.haha;
    z.haha+=count_haha((x.last+y.first));
    z.first=x.first+y.first;
    z.last=x.last+y.last;
    z.trim();
    return z;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        map<string,variable> vars;
        variable last;
        while(n--) {
            string var;
            string assignment;
            string val1,plus;
            string val2;
            cin>>var>>assignment;
            if(assignment==":=") {
                cin>>val1;
                vars[var]=variable(val1);
            }
            else {
                cin>>val1>>plus>>val2;
                vars[var]=concat(vars[val1],vars[val2]);
            }
            last=vars[var];
        }
        cout<<last.haha<<endl;        
    }   
}