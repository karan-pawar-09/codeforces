/*
author:Karan
created:26.07.2021 21:08:16
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll n,m,k;
        cin>>n>>m>>k;
        if(n%2) {
            int left=k;
            if(left>=m/2&&(k-(m/2))%2==0) {
                cout<<"YES"<<endl;
                vector<vector<char>> arr(n,vector<char>(m,'*'));
                int cnt=0;
                for(int j=0;j<m;j+=2) {
                    if(cnt%2) {
                        arr[0][j]='a';
                        arr[0][j+1]='a';
                    }
                    else {
                        arr[0][j]='b';
                        arr[0][j+1]='b';
                    }
                    cnt++;
                }

                left-=m/2;
                
                for(int j=0;j<m;j+=2) {
                    int i=1;
                    while(left>0&&i<n) {
                        if(i%2) {
                            arr[i][j]='c';
                            arr[i][j+1]='c';
                            left--;
                        }
                        else {
                            arr[i][j]='d';
                            arr[i][j+1]='d';
                            left--;
                        }
                        i++;
                    }
                }
                int si,sj;
                bool found=false;

                for(int j=0;j<m;j++) {
                    for(int i=0;i<n;i++) {
                        if(arr[i][j]=='*') {
                            si=i;
                            sj=j;
                            found=true;
                            break;
                        }
                    }
                    if(found) break;
                }

                bool first=true;
                for(int j=sj;j<m;j++) {
                    int k=1;
                    for(int i=1;i<n;i+=2) {
                        if(first) {
                            i=si;
                            if(j%2==0)
                                first=false;
                        }
                        k++;
                        if(j%2) {
                            if(k%2) {
                                arr[i][j]='e';
                                arr[i+1][j]='e';
                            }
                            else {
                                arr[i][j]='f';
                                arr[i+1][j]='f';
                            }
                        }
                        else {
                            if(k%2) {
                                arr[i][j]='g';
                                arr[i+1][j]='g';
                            }
                            else {
                                arr[i][j]='h';
                                arr[i+1][j]='h';
                            }
                        }
                    }
                }
                for(int i=0;i<n;i++) {
                    for(int j=0;j<m;j++) {
                        cout<<arr[i][j];
                    }
                    cout<<endl;
                }
            }

            else cout<<"NO"<<endl;
        }
        else if(m%2) {
            int left=n*m/2-k;
            if(left>=n/2&&(left-n/2)%2==0) {

                vector<vector<char>> arr(n,vector<char>(m,'*'));
                cout<<"YES"<<endl;
                int cnt=0;
                for(int i=0;i<n;i+=2) {
                    if(cnt%2) {
                        arr[i][0]='a';
                        arr[i+1][0]='a';
                    }
                    else {
                        arr[i][0]='b';
                        arr[i+1][0]='b';
                    }
                    cnt++;
                }

                left-=n/2;

                for(int i=0;i<m;i+=2) {
                    int j=1;
                    while(left>0&&j<m) {
                        if(j%2) {
                            arr[i][j]='c';
                            arr[i+1][j]='c';
                            left--;
                        }
                        else {
                            arr[i][j]='d';
                            arr[i+1][j]='d';
                            left--;
                        }
                        j++;
                    }
                }


                int si,sj;
                bool found=false;

                for(int i=0;i<n;i++) {
                    for(int j=0;j<m;j++) {
                        if(arr[i][j]=='*') {
                            si=i;
                            sj=j;
                            found=true;
                            break;
                        }
                    }
                    if(found) break;
                }
                bool first=true;
                for(int i=si;i<n;i++) {
                    for(int j=1;j<m;j+=2) {
                        if(first) {
                            j=sj;
                            if(i%2)
                                first=false;
                        }
                        k++;
                        if(i%2) {
                            if(k%2) {
                                arr[i][j+1]='e';
                                arr[i][j]='e';
                            }
                            else {
                                arr[i][j+1]='f';
                                arr[i][j]='f';
                            }
                        }
                        else {
                            if(k%2) {
                                arr[i][j]='g';
                                arr[i][j+1]='g';
                            }
                            else {
                                arr[i][j]='h';
                                arr[i][j+1]='h';
                            }
                        }
                    }
                }
                for(int i=0;i<n;i++) {
                    for(int j=0;j<m;j++) {
                        cout<<arr[i][j];
                    }
                    cout<<endl;
                }


            }
            else cout<<"NO"<<endl;
        }
        else {
            if(k%2) cout<<"NO"<<endl;
            else {
                cout<<"YES"<<endl;
                int left=k;
                vector<vector<char>> arr(n,vector<char> (m,'*'));
                for(int j=0;j<m;j+=2) {
                    int i=0;
                    while(left>0&&i<n) {
                        if(i%2==0) {
                            arr[i][j]='c';
                            arr[i][j+1]='c';
                            left--;
                        }
                        else {
                            arr[i][j]='d';
                            arr[i][j+1]='d';
                            left--;
                        }
                        i++;
                    }
                }
                int si,sj;
                bool found=false;

                for(int j=0;j<m;j++) {
                    for(int i=0;i<n;i++) {
                        if(arr[i][j]=='*') {
                            si=i;
                            sj=j;
                            found=true;
                            break;
                        }
                    }
                    if(found) break;
                }

                bool first=true;
                for(int j=sj;j<m;j++) {
                    int k=1;
                    for(int i=0;i<n;i+=2) {
                        if(first) {
                            i=si;
                            if(j%2)
                                first=false;
                        }
                        k++;
                        if(j%2) {
                            if(k%2) {
                                arr[i][j]='e';
                                arr[i+1][j]='e';
                            }
                            else {
                                arr[i][j]='f';
                                arr[i+1][j]='f';
                            }
                        }
                        else {
                            if(k%2) {
                                arr[i][j]='g';
                                arr[i+1][j]='g';
                            }
                            else {
                                arr[i][j]='h';
                                arr[i+1][j]='h';
                            }
                        }
                    }
                }
                for(int i=0;i<n;i++) {
                    for(int j=0;j<m;j++) {
                        cout<<arr[i][j];
                    }
                    cout<<endl;
                }

            }
        }
    }
}