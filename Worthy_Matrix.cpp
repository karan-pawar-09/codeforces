#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'


void prefixSum2D(vector<vector<ll>> &a,vector<vector<ll>> &psa,int R, int C) {
    psa[0][0] = a[0][0];
    for (int i = 1; i < C; i++)
        psa[0][i] = psa[0][i - 1] + a[0][i];
    for (int i = 1; i < R; i++)
        psa[i][0] = psa[i - 1][0] + a[i][0];
    for (int i = 1; i < R; i++) {
        for (int j = 1; j < C; j++)
            psa[i][j] = psa[i - 1][j] + psa[i][j - 1]
                        - psa[i - 1][j - 1] + a[i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n,m,k;
        cin>>n>>m>>k;
        vector<vector<ll>> psa;
        vector<vector<ll>> arr(n+1,vector<ll> (m+1,0));
        psa=arr;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>arr[i][j];
            }
        }
        prefixSum2D(arr,psa,n,m);
         ll cnt=0;
       
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++){
                bool flag = false;
                ll length;
                length=min(i,j)+1;             
        
                ll l=1;
                ll r=length+1;
                if(arr[i][j]>=k) {
                    while(r>l+1) {
                        ll mid=l+(r-l)/2;         
                        
                            if((i-mid)<0&&(j-mid)<0) {
                                ll aabc=(psa[i][j]/((mid)*(mid)));
                                if(aabc>=k) {                                    
                                    l=mid;
                                }
                                else {
                                    r=mid;
                                }
                            }             
                            else if((i-mid)<0) {
                                ll aabc=((psa[i][j]-psa[i][j-mid])/(mid*mid));
                                if(aabc>=k)  {                                   
                                    l=mid;
                                }
                                else {
                                    r=mid;
                                }
                            }  
                            else if((j-mid)<0) {
                                ll aabc=((psa[i][j]-psa[i-mid][j])/((mid)*(mid)));
                                if(aabc>=k) {                                   
                                    l=mid;
                                }
                                else {
                                    r=mid;
                                }
                            }
                            else {
                                if((psa[i][j]+psa[i-mid][j-mid]-psa[i][j-mid]-psa[i-mid][j])/((mid)*(mid))>=k) {
                                    l=mid;
                                }
                                else {
                                    r=mid;
                                }  
                            }                                        
                                    
                    }
                    cnt+=l;
                }                 
            }
	    }
        cout<<cnt<<endl;
    }
}