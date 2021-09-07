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
        string a,b;
        cin>>a;
        cin>>b;
        int n=a.size();
        int m=b.size();
        int maxi=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int temp=0;
                for(int k=j,p=i;k<m&&p<n;k++,p++) {
                    if(a[p]==b[k]) {
                        temp++;
                    }
                    else {
                        break;
                    }
                }
                maxi=max(temp,maxi);
            }
        }
        cout<<m+n-(2*maxi)<<endl;
    }
}