/*
author:Karan
created:19.06.2021 11:22:16
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void radix_sort(vector<pair<pair<int,int>,int>> &a) {
    int n=a.size();
    {
        vector<int> cnt(n);
        for(int i=0;i<n;i++) {
            cnt[a[i].first.second]++;
        }
        vector<pair<pair<int,int>,int>> a_new(n);
        vector<int>pos(n);
        pos[0]=0;
        for(int i=1;i<n;i++) {
            pos[i]=pos[i-1]+cnt[i-1];
        }
        for(int i=0;i<n;i++) {
            a_new[pos[a[i].first.second]]=a[i];
            pos[a[i].first.second]++;
        }
        a=a_new;
    }
    {
        vector<int> cnt(n);
        for(int i=0;i<n;i++) {
            cnt[a[i].first.first]++;
        }
        vector<pair<pair<int,int>,int>> a_new(n);
        vector<int>pos(n);
        pos[0]=0;
        for(int i=1;i<n;i++) {
            pos[i]=pos[i-1]+cnt[i-1];
        }
        for(int i=0;i<n;i++) {
            a_new[pos[a[i].first.first]]=a[i];
            pos[a[i].first.first]++;
        }
        a=a_new;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,karan;
    cin>>n>>karan;
    string s;
    cin>>s;
    s+=s;
    s+="$";
    n=s.size();
    vector<int> p(n),c(n);
    {
        vector<pair<char,int>> a(n);
        for(int i=0;i<n;i++) {
            a[i]={s[i],i};
        }
        sort(all(a));
        for(int i=0;i<n;i++) {
            p[i]=a[i].second;
        }
        c[p[0]]=0;
        for(int i=1;i<n;i++) {
            if(a[i].first==a[i-1].first) {
                c[p[i]]=c[p[i-1]];
            }
            else {
                c[p[i]]=c[p[i-1]]+1;
            }
        }
    }
    int k=0;
    while((1<<k)<n) {
        vector<pair<pair<int,int>,int>> a(n);
        for(int i=0;i<n;i++) {
            a[i]={{c[i],c[(i+(1<<k))%n]},i};
        }
        radix_sort(a);
        for(int i=0;i<n;i++) {
            p[i]=a[i].second;
        }
        c[p[0]]=0;
        for(int i=1;i<n;i++) {
            if(a[i].first==a[i-1].first) {
                c[p[i]]=c[p[i-1]];
            }
            else {
                c[p[i]]=c[p[i-1]]+1;
            }
        }
        k++;
    }
    int ind=0;
    for(int i=0;i<n;i++) {
        if(p[i]==0) {
            ind=i;
            break;
        }
    }
    if(ind==n-1) {
        s.pop_back();
    }
    else {
        int mini=*min_element(p.begin()+ind+1,p.begin()+n);
        s.erase(mini);
    }
    while(s.size()<karan) {
        s+=s;
    }
    cout<<s.erase(karan)<<endl;
}
