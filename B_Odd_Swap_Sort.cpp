// /*
//     author:Karan
//     created:14.02.2022 21:00:25
// */
// #if true
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define all(ar) ar.begin(),ar.end()
// #define endl '\n'
// #define mset(a,x) memset(a,x,sizeof(a))
// #endif

// void solve() {
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++) {
//         cin>>arr[i];
//     }
//     vector<pair<int,int>> ar(n);
//     for(int i=0;i<n;i++) {
//         ar[i]={arr[i],i};
//     }
//     sort(all(ar));
//     map<int,int> M;
//     for(int i=0;i<n;i++) {
//         M[ar[i].second]=i;
//     }
//     vector<int> odd(n,0),even(n,0);
//     vector<int> oddd(n,0),evenn(n,0);
//     if(arr[n-1]%2) oddd[n-1]=1;
//     else evenn[n-1]=1;
//     if(arr[0]%2) odd[0]=1;
//     else even[0]=1;
//     for(int i=1;i<n;i++) {
//         if(arr[i]%2) {
//             odd[i]=odd[i-1]+1;
//             even[i]=even[i-1];
//         } else {
//             even[i]=even[i-1]+1;
//             odd[i]=odd[i-1];
//         }
//     }
//     for(int i=n-2;i>=0;i--) {
//         if(arr[i]%2) {
//             oddd[i]=oddd[i+1]+1;
//             evenn[i]=evenn[i+1];
//         } else {
//             evenn[i]=evenn[i+1]+1;
//             oddd[i]=oddd[i+1];
//         }
//     }
//     for(int i=1;i<n;i++) {
//         int p=M[i];
//         int q=M[i-1];
//         int od=0;
//         int ev=0;
//         if(arr[i]<arr[i-1]) {
//             if(arr[i]%2 != arr[i-1]%2)) {

//             } else {
//                 cout<<"No"<<endl;
//                 return;
//             }
//         }
//     }
//     cout<<"Yes"<<endl;
// }

// int32_t main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     // freopen("input.txt","r",stdin);
//     // freopen("output.txt","w",stdout);
//     int t=1;
//     cin>>t;
//     while(t--) {
//         solve();
//     }
// }



#include<bits//stdc++.h>
using namespace std;

void permut(string s,int index,string temp) {
    if(index==s.size())
    {
         cout<<temp<<endl;
         return;
    }
    for(int i=0;i<s.size();i++)
    {
        permut(s,index+1,temp+s[i]);
    }
    return;
}
int main()
{    
    
     string s;
     cin>>s;
     string temp;
     permut(s,0,temp);
    return 0;
}
