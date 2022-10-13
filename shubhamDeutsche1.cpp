#include<bits//stdc++.h>
using namespace std;
#define mod 998244353
int main()
{    
    int t;

    
    cin>>t;
    while(t--)
    {
         int n;
         cin>>n;
         int a[n];
         for(int i=0;i<n;i++)
             cin>>a[i];
         int suffix[n];
         int prefix[n];
         int maxi=0;
         long long prefix_sum[n+1];
         long long suffix_sum[n+1];
         prefix_sum[0]=0;
         suffix_sum[n]=0;
         for(int i=1;i<=n;i++)
            prefix_sum[i]=prefix_sum[i-1]+a[i-1];
        for(int i=n-1;i>=0;i--)
            suffix_sum[i]=suffix_sum[i+1]+a[i];
        
         for(int i=n-1;i>=0;i--)
         { 
            maxi=max(maxi,a[i]);
            suffix[i]=maxi;
         }
         maxi=0;
         for(int i=0;i<n;i++)
         {
            maxi=max(maxi,a[i]);
            prefix[i]=maxi;
         }
         long long ans[n];
         for(int i=0;i<n;i++)
         { 
            int m;
            if(i==0)
                m=0;
            else
                m=prefix[i-1];
            int l=i+1;
            int r=n-1;
            int ans1=n-1;
            while(r>=l)
            {
                int mid=(l+r)/2;
                if(suffix[mid]<m)
                {
                    ans1=mid;
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            ans[i]=prefix[i]*(n-1-ans1);
            ans[i]+=(prefix_sum[ans1+1]-prefix_sum[i+1]);
            ans[i]+=m;
            ans[i]=ans[i]%mod;
         }
         long long final_ans[n+1];
         final_ans[n]=0;
         for(int i=n-1;i>=0;i--)
         {
            final_ans[i]=(final_ans[i+1]+ans[i])%mod;
         }
         int q;
         cin>>q;
         while(q--)
         {
            int x;
            cin>>x;
            x--;
            cout<<final_ans[x]<<" ";
         }
         cout<<endl;
    }
    return 0;
}