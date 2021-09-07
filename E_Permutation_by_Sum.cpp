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
    while(t--) {
        int n,l,r,s;
        cin>>n>>l>>r>>s;
        int k=(r-l)+1;
        if(s<((k*(k+1))/2)||s>((k*(2*n+1-k))/2)) {
            cout<<"-1"<<endl;
        }
        else {
            int mx=n;
            int sum=0;
            vector<int> a(k);
            for(int i=0;i<k;i++) {
                a[i]=i+1;
                sum+=a[i];
            }
            int i=k-1;
            while(sum<s) {
                if(a[i]==mx) {
                    i--;
                    mx--;
                }
                else {
                    a[i]++;
                    sum++;
                }
            }
            vector<bool> used(n+1,false);
            used[0]=true;
            for(int i=0;i<k;i++) {
                used[a[i]]=true;
            }
            vector<int> b;
            for(int i=1;i<=n;i++) {
                if(!used[i]) {
                    b.push_back(i);
                }
            }
            bool showd=false;
            for(int i=0;i<b.size();i++) {
                if(i==(l-1)) {
                    showd=true;
                    for(int j=0;j<k;j++) {
                        cout<<a[j]<<" ";
                    }
                }
                cout<<b[i]<<" ";
            }
            if(!showd) {
                for(int j=0;j<k;j++) {
                    cout<<a[j]<<" ";
                }
            }
            cout<<endl;
        }
    }
}   