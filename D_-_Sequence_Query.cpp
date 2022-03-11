// /*
//     author:Karan
//     created:26.02.2022 18:46:45
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
//     ll q;
//     cin>>q;
//     multiset<ll> s;
//     while(q--) {
//         ll type;
//         cin>>type;
//         if(type==1) {
//             ll a;
//             cin>>a;
//             s.insert(a);
//         } else if(type==2) {
//             ll x,k;
//             cin>>x>>k;
//             bool cant=false;
//             auto it=upper_bound(all(s),x);
//             for(int i=0;i<k;i++) {
//                 it--;
//                 if(it==s.begin() and i!=(k-1)) {
//                     cant=true;
//                     break;
//                 }
//             }
//             if(cant) cout<<-1<<endl;
//             else cout<<*it<<endl;
//         } else {
//             ll x,k;
//             cin>>x>>k;
//             bool cant=false;
//             auto it=lower_bound(all(s),x);
//             for(int i=0;i<k-1;i++) {
//                 it++;
//                 if(it==s.end() and i!=(k-2)) {
//                     cant=true;
//                     break;
//                 } 
//             }
//             if(cant) cout<<-1<<endl;
//             else cout<<*it<<endl;
//         }
//     }
// }

// int32_t main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     // freopen("input.txt","r",stdin);
//     // freopen("output.txt","w",stdout);
//     ll t=1;
//     // cin>>t;
//     while(t--) {
//         solve();
//     }
// }





/*
    author:Karan
    created:26.02.2022 18:46:45
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

void solve() {
    ll q;
    cin>>q;
    multiset<ll> s;
    multiset<ll> t;
    while(q--) {
        ll type;
        cin>>type;
        if(type==1) {
            ll a;
            cin>>a;
            s.insert(a);
            t.insert(-a);
        } else if(type==2) {
            ll x,k;
            cin>>x>>k;
            bool cant=false;
            auto it=s.upper_bound(x);
            for(ll i=0;i<k;i++) {
                if(it==s.begin()) {
                    cant=true;
                } else {
                    it--;
                }
            }
            if(cant) cout<<-1<<endl;
            else cout<<*it<<endl;
        } else {
            ll x,k;
            cin>>x>>k;
            bool cant=false;
            auto it=t.upper_bound(-x);
            for(int i=0;i<k;i++) {
                if(it==t.begin()) {
                    cant=true;
                } else {
                    it--;
                }
            }
            if(cant) cout<<-1<<endl;
            else cout<<-(*it)<<endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}

