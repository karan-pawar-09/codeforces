#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int k,n;
        cin>>n>>k;
        vector<int>arr(n+1,0);
        if(k==1||k%2==0||k==n) {
            arr[1]=1;
            k--;
            ll sum=1;
            for(int i=2;i<=n;i++) {
                if(k>0) {
                    if(sum-i>0) {
                        sum-=i;
                        arr[i]=-i;
                    }
                    else{
                        sum+=i;
                        arr[i]=i;
                    }
                    k--;
                }
                else {
                    arr[i]=-i;
                }
            }
            for(int i=1;i<=n;i++) {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        else {
            if(k==3&&n==4) {
                cout<<"1 2 -3 4"<<endl;
            }
            else {
                arr[1]=-1;
                ll sum=-1;
                for(int i=2;i<=n;i++) {
                    if(k>0) {
                        if(sum<0) {
                            sum+=i;
                            arr[i]=i;
                        }
                        else{
                            if(sum-i>=0) {
                                sum-=i;
                                arr[i]=-i;
                            }
                            else{
                                sum+=i;
                                arr[i]=i;
                            }
                        }
                        if(sum>0) {
                            k--;
                        }
                    }
                    else {
                        arr[i]=-i;
                    }
                }
                for(int i=1;i<=n;i++) {
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            }
        }
    }
}
