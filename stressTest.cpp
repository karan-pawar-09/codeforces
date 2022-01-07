/*
author:Karan
created:23.08.2021 22:20:42
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'



//------------------------------------------------------------------------------------------------------------//
struct testcase{
    ll n,m,k;
    vector<ll> arr;
};

ll randomNumber(ll a,ll b) {    
    return a + (rand() % b);
}

string randomString(const ll len) {   
 
    string tmp_s;
    static const char alphanum[] =
        // "0123456789"
        // "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    
    // srand( (unsigned) time(NULL) * getpid());
    tmp_s.reserve(len);
    for (ll i = 0; i < len; ++i) 
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];    
    
    return tmp_s;    
}

vector<vector<ll>> randomMatrix(const ll n) {
    srand( time(0));
    vector<vector<ll>> ans(n);   
    for(ll i=0;i<n;i++) {
        ll p=randomNumber(1,9);
        ans[i].push_back(p);
        for(ll j=0;j<p;j++) {
            ll q=randomNumber(1,10);
            ans[i].push_back(q);           
        }       
    }

    return ans;
}
vector<ll> randomArray(const ll n, int x) {
    vector<ll> ans(n);
    for(ll i=0;i<n;i++) {
        ll p=randomNumber(1,x-1);
        ans[i]=p;
    }
    return ans;
}
testcase generateTestCase() {
    testcase randomTest;
    randomTest.n = randomNumber(1,10);
    randomTest.m = randomNumber(1,10);
    randomTest.k = randomNumber(1,1000);
    randomTest.arr = randomArray(randomTest.n,randomTest.k);
    return randomTest;
}


ll bruteForce(testcase T) {
   ll n,m,k;
    n=T.n;
    m=T.m;
    k=T.k;
    vector<ll> arr = T.arr;
    ll sum=0;
    vector<bool> dir(n,false);
    vector<pair<ll,ll>> check;
    for(ll i=0;i<n;i++) {
        if(k-arr[i]<arr[i]) {
            dir[i]=true;
        }
        if(((k-arr[i])%2 != (arr[i]%2)))
            check.push_back({abs(k-arr[i]-arr[i]),i});
        sum+=arr[i];
    }
    return m;
}

ll optimizedSolution(testcase T) {
    ll n,m,k;
    n=T.n;
    m=T.m;
    k=T.k;
    vector<ll> arr = T.arr;
    ll sum=0;
    vector<bool> dir(n,false);
    vector<pair<ll,ll>> check;
    for(ll i=0;i<n;i++) {
        if(k-arr[i]<arr[i]) {
            dir[i]=true;
        }
        if(((k-arr[i])%2 != (arr[i]%2)))
            check.push_back({abs(k-arr[i]-arr[i]),i});
        sum+=arr[i];
    }
    vector<pair<ll,ll>> v;
    for(ll i=0;i<n;i++) {
        v.push_back({k-(2*arr[i]),i});
    }
    sort(all(v));
    ll x=m;
    ll req=0;
    vector<bool> used(n,false);    
    map<ll,pair<ll,ll>> M;
    for(ll i=0;i<n;i++) M[i]={0,0};
    for(ll i=0;i<n;i++) {
        ll kk=min(arr[v[i].second],k-arr[v[i].second]);
        req+=kk;
    }    
    if(req>=x) {
        for(ll i=0;i<n;i++) {
            ll kk=min(arr[v[i].second],k-arr[v[i].second]);
            if(m>=kk) {
                m-=kk;
                sum-=arr[v[i].second];
                used[v[i].second]=true;
                if(!dir[v[i].second]) {
                    M[v[i].second].first=kk;
                    M[v[i].second].second=0;
                }
                else {
                    M[v[i].second].second=kk;
                    M[v[i].second].first=0;
                }
            }
        }
        ll kkkk=max(sum-m,0LL);
        for(ll i=0;i<n;i++) {
            if(!used[i]) {
                if(m<=0) break;
                else {
                    ll xx=min(m,arr[i]);
                    m-=xx;
                    M[i].first=xx;
                    M[i].second=0;
                }
            }
        }
        ll check=0;
        for(int i=0;i<n;i++) check+=M[i].first+M[i].second;
        return check;
    } else {
        sort(all(check));
        if((x-req)%2==0) {
            map<ll,pair<ll,ll>> MM;
            for(ll i=0;i<n;i++) MM[i]={0,0};
            for(ll i=0;i<n;i++) {
                {
                    if(dir[i]) {
                        MM[i]={0,k-arr[i]};
                    } else {
                        MM[i]={arr[i],0};
                    }
                } 
            }
            MM[0].first+=(x-req)/2;
            MM[0].second+=(x-req)/2;
            ll check=0;
            for(int i=0;i<n;i++) check+=MM[i].first+MM[i].second;
            return check;
        } else {
            if(check.size()>0 and check[0].first<=(x-req)) {
                if(dir[check[0].second]) {
                    dir[check[0].second]=false;
                } else {
                    dir[check[0].second]=true;
                }
                map<ll,pair<ll,ll>> MM;
                for(ll i=0;i<n;i++) MM[i]={0,0};
                m=x;
                for(ll i=0;i<n;i++) {
                    if(i!=check[0].second) {
                        if(dir[i]) {
                            MM[i]={0,k-arr[i]};
                            m-=k-arr[i];
                        } else {
                            MM[i]={arr[i],0};
                            m-=arr[i];
                        }
                    } else {
                        if(dir[i]) {
                            MM[i]={0,k-arr[i]};
                            m-=k-arr[i];
                        } else {
                            MM[i]={arr[i],0};
                            m-=arr[i];
                        }
                    }
                }
                MM[0].first+=m/2;
                MM[0].second+=m/2;
                ll check=0;
                for(int i=0;i<n;i++) check+=MM[i].first+MM[i].second;
                return check;
            } else {
                cout<<1<<endl;
                map<ll,pair<ll,ll>> MM;
                for(ll i=0;i<n;i++) MM[i]={0,0};
                m=x;
                for(ll i=0;i<n;i++) {
                    {
                        if(dir[i]) {
                            MM[i]={0,k-arr[i]};
                            m-=k-arr[i];
                        } else {
                            MM[i]={arr[i],0};
                            m-=arr[i];
                        }
                    } 
                }
                MM[0].first+=m/2;
                MM[0].second+=m/2;
                MM[0].second++;
                ll check=0;
                for(int i=0;i<n;i++) check+=MM[i].first+MM[i].second;
                return check;
            }
        }
    }
}

bool debugger(ll &t){
    testcase random = generateTestCase();
    // cout<<random.s<<" ";
    ll ans1 = bruteForce(random);
    ll ans2 = optimizedSolution(random);
    if(ans1 != ans2) {
        cout<<"WA on testcase "<<t<<endl;
        // cout<<random.s<<endl;
        cout<<random.n<<" "<<random.m<<" "<<random.k<<endl;
        for(int i=0;i<random.arr.size();i++) {
            cout<<random.arr[i]<<" ";
        }
        cout<<endl;
        cout<<ans1<<" "<<ans2<<endl;
        // cout<<random.n<<" "<<random.m<<" "<<random.a<<" "<<random.b<<" "<<random.y<<" "<<random.z<<endl;
        // cout<<ans1<<" "<<ans2<<endl;
        return false;
    }
    else {
        cout<<"AC on testcase "<<t<<endl;
        return true;
    }
}


bool solve(ll &t){
    if(!debugger(t)) {
        return false;
    }
    else {
        return true;
    }
}

int32_t main() {
    ll t;
    cin>>t;
    for(ll i=1;i<=t;i++) {
        if(!solve(i)) break;
    }
    return 0;
}