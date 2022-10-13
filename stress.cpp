/*
author:Karan
created:23.08.2021 22:20:42
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'


const ll inf = 1e9+10;
 
ll aa[4] = {-1, 0, 1, 0};
ll bb[4] = {0, 1, 0, -1};
 
bool isGood(ll a, ll b, ll n, ll m, vector<vector<bool>> &visited, ll x, ll y, ll d) {
    if(a<=0 || a>n || b<=0 || b>m) return false;
    if(visited[a][b]) return false;
    if((abs(x-a) + abs(y-b)) <=d ) return false;
    return true;
}

//------------------------------------------------------------------------------------------------------------//
struct testcase {
    ll n;
    vector<int> a;
    vector<int> b;
    vector<string> st;
};

ll randomNumber(ll a, ll b) {
    return a + (rand() % b);
}

string randomString(const ll len) {

    string tmp_s;
    static const char alphanum[] =
        "abcdefghijklmnopqrstuvwxyz";
    // "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    // "abcdefghijklmnopqrstuvwxyz";

// srand( (unsigned) time(NULL) * getpid());
    tmp_s.reserve(len);
    for (ll i = 0; i < len; ++i) {
        if (i == 0) {
            tmp_s += alphanum[rand() % (sizeof(alphanum) - 2)];
        }
        else
            tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

vector<vector<ll>> randomMatrix(const ll n) {
    srand(time(0));
    vector<vector<ll>> ans(n);
    for (ll i = 0;i < n;i++) {
        ll p = randomNumber(1, 9);
        ans[i].push_back(p);
        for (ll j = 0;j < p;j++) {
            ll q = randomNumber(1, 10);
            ans[i].push_back(q);
        }
    }

    return ans;
}
vector<ll> randomArray(const ll n, ll x) {
    vector<ll> ans(n);
    for (ll i = 0;i < n;i++) {
        ll p = randomNumber(1, x - 1);
        // ll x=randomNumber(0,2);   //for -ve no
        // if(x==0) p=-p;
        ans[i] = p;
    }
    return ans;
}
vector<string> randomStringArr(ll n) {
    vector<string> ans(n);
    for(int i=0;i<n;i++) {
        ans[i] =randomString(randomNumber(1, 10));
    }
    return ans;
}
testcase generateTestCase() {
    testcase randomTest;
    randomTest.n = randomNumber(1, 5);
    randomTest.a = randomArray(randomTest.n, 3);
    randomTest.b = randomArray(randomTest.n, 10);
    randomTest.st = randomStringArr(randomTest.n);
    return randomTest;
}


vector<ll>  bruteForce(testcase T) {
    ll N = T.n;
    string S = T.s;
    vector<ll> Dict = T.dict;
    vector<ll> ans(150, 0);
    char mx;
    cout<<S<<endl;
    for (int i = 0; i < N; i++) {
        mx = 0;
        for (int j = 0; j <= i; j++) {
            cout<<S[j]<<" ";
            mx = max(mx, S[j]);
        }
        cout<<mx<<endl;
        for (int j = 0; j <= i; j++) {
            // If S[j] is 'a' and
            // Dict[S[j]] is -1 then
            // make S[j] equals to 'z'
            if (S[j] + Dict[mx - 'a'] < 97) {
                S[j] = S[j] +
                    Dict[mx - 'a'] + 26;
            }
 
            // If S[j] is 'z' and
            // Dict[S[j]] is 1
            // then make S[j] equals to 'a'
            else if (S[j] + Dict[mx - 'a']
                     > 122) {
                S[j] = S[j] +
                    Dict[mx - 'a'] - 26;
            }
 
            else {
                S[j] += Dict[mx - 'a'];
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        ans[S[i]]++;
    }
    
    return ans;
}

vector<ll> optimizedSolution(testcase T) {
    ll n = T.n;
    string s = T.s;
    vector<ll> dict = T.dict;
    char curmax = 'a';
    vector<int> pre(n, 0);
    for(int i=0;i<n;i++) {
        if(s[i] > curmax) curmax = s[i];
        cout<<(int) (curmax-'a')<<endl;
        pre[i] = dict[(int) (curmax-'a')];
    }
    for(auto x:pre) {
        cout<<x<<endl;
    }
    for(int i=n-2;i>=0;i--) {
        pre[i] += pre[i+1];
    }
    
    vector<ll> count(150, 0);
    for(int i=0;i<n;i++) {
        char c = (char) ('a' +((s[i]-'a')+pre[i]) %26);
        count[c]++;
    }
    return count;
}



bool debugger(ll& t) {
    testcase random = generateTestCase();
    // cout<<random.s<<" ";
    vector<ll>  answ1 = bruteForce(random);
    vector<ll>  answ2 = optimizedSolution(random);
    if (answ1 != answ2) {
        cout << "WA on testcase " << t << endl;
        // cout<<random.n<<" "<<random.m<<endl;
        // cout<<answ1<<" "<<answ2<<endl;
        cout<<random.s<<endl;
        for(auto x: random.dict) {
            cout<<x<<" ";
        }
        cout<<endl;
        for(int i='a';i<='z';i++) {
            cout<<answ1[i]<<" ";
        }
        cout<<endl;
        for(int i='a';i<='z';i++) {
            cout<<answ2[i]<<" ";
        }
        cout<<endl;
        return false;
    }
    else {
        cout << "AC on testcase " << t << endl;
        cout << endl;
        return true;
    }
}


bool solve(ll& t) {
    if (!debugger(t)) {
        return false;
    }
    else {
        return true;
    }
}

int32_t main() {
    ll t;
    cin >> t;
    for (ll i = 1;i <= t;i++) {
        if (!solve(i)) break;
    }
    return 0;
}