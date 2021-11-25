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
    ll n;
    string s;
};

ll randomNumber(ll a,ll b){    
    return a + (rand() % b);
}

string randomString(const ll len) {    
    string tmp_s;
    static const char alphanum[] =
        // "0123456789"
        // "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    
    srand( (unsigned) time(NULL) * getpid());
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
vector<ll> randomArray(const ll n) {
    srand(time(0));
    vector<ll> ans(n);
    for(ll i=0;i<n;i++) {
        ll p=randomNumber(1,10);
        ans[i]=p;
    }
    return ans;
}
testcase generateTestCase(){
    srand( time(0));
    testcase randomTest;
    randomTest.n = randomNumber(1,10);
    randomTest.s = randomString(randomTest.n);
    return randomTest;
}


ll bruteForce(testcase T){
    int n=T.n;
    string s=T.s;
    bool ans=false;
    int mini=1e9;
    for(int i=0;i<n;i++) {
        vector<ll> freq(3,0);
        freq[s[i]-'a']++;
        for(int j=i+1;j<n;j++) {
            freq[s[j]-'a']++;
            if(freq[0]>(freq[1]+freq[2]) or ((freq[0]==(freq[1]+freq[2]) and (freq[1]==freq[2])))) {
                mini=min(mini,j-i+1);
                ans=true;
            }
        }
    }
    if(ans) {
        return mini;
    }
    else {
        return -1;
    }
}

ll optimizedSolution(testcase T){
    int n=T.n;
    string s=T.s;
    bool ans=false;
    for(ll i=1;i<n;i++) {
        if(s[i]==s[i-1] and s[i]=='a') {
            ans=true;
            break;
        }
    }
    if(ans) {
        return 2;
    }
    else {
        vector<ll> freq(3,0);
        freq[s[0]-'a']++;
        freq[s[1]-'a']++;
        for(ll i=2;i<n;i++) {
            freq[s[i]-'a']++;
            if(freq[0]>=2) {
                ans=true;
                break;
            }
            freq[s[i-2]-'a']--;
        }
        if(ans) {
            return 3;
        }
        else {
            
            if(n<4)
                return -1;
            else {
                vector<ll> freq(3,0);
                freq[s[0]-'a']++;
                freq[s[1]-'a']++;
                freq[s[2]-'a']++;
                for(int i=3;i<n;i++) {
                    freq[s[i]-'a']++;
                    if(freq[0]>2 or (freq[0]==2 and freq[1]==1)) {
                        ans=true;
                        break;
                    }
                }
                if(ans) {
                    return 4;
                }
                else return -1;
            }
        }
    }
}

bool debugger(ll &t){
    testcase random = generateTestCase();
    cout<<random.s<<" ";
    ll ans1 = bruteForce(random);
    ll ans2 = optimizedSolution(random);
    if(ans1 != ans2) {
        cout<<"WA on testcase "<<t<<endl;
        // for(ll i=0;i<random.arr.size();i++) {
        //     for(ll j=0;j<random.arr.size();j++) {
        //         cout<<random.arr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        // cout<<random.n<<" -> "<<random.a<<" "<<random.b<<endl;
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