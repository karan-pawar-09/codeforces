/*
author:Karan
created:23.08.2021 22:20:42
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'



const ll mx = 2e5 + 10;
map<pair<ll, ll>, ll> M;
vector<ll> graph[mx];
ll res;
void dfs(ll node, ll par, ll ans, ll rank) {
    res = max(ans, res);
    for (auto x : graph[node]) {
        if (x != par) {
            ll temp = ans;
            ll tempRank = M[{x, node}];
            if (tempRank < rank) {
                temp++;
            }
            dfs(x, node, temp, tempRank);
        }
    }
}


vector<pair<ll, ll>> printTreeEdges(vector<ll> prufer, ll m)
{
    ll vertices = m + 2;
    vector<ll> vertex_set(vertices);

    // Initialize the array of vertices
    for (ll i = 0; i < vertices; i++)
        vertex_set[i] = 0;

    // Number of occurrences of vertex in code
    for (ll i = 0; i < vertices - 2; i++)
        vertex_set[prufer[i] - 1] += 1;


    ll j = 0;

    // Find the smallest label not present in
    // prufer[].
    vector<pair<ll, ll>> edges;
    for (ll i = 0; i < vertices - 2; i++)
    {
        for (j = 0; j < vertices; j++)
        {

            // If j+1 is not present in prufer set
            if (vertex_set[j] == 0)
            {

                // Remove from Prufer set and print
                // pair.
                vertex_set[j] = -1;
                edges.push_back({ j + 1, prufer[i] });

                vertex_set[prufer[i] - 1]--;

                break;
            }
        }
    }

    j = 0;

    // For the last element
    ll a, b;
    for (ll i = 0; i < vertices; i++)
    {
        if (vertex_set[i] == 0 && j == 0)
        {

            a = i + 1;
            //cout << "(" << (i + 1) << ", ";
            j++;
        }
        else if (vertex_set[i] == 0 && j == 1) {
            //cout << (i + 1) << ")\n";
            b = i + 1;
        }
    }
    edges.push_back({ a, b });
    return edges;
}

// generate random numbers in between l an r
ll ran(ll l, ll r)
{
    return l + (rand() % (r - l + 1));
}

// Function to Generate Random Tree
vector<pair<ll, ll>> generateRandomTree(ll n)
{

    ll length = n - 2;
    vector<ll> arr(length);

    // Loop to Generate Random Array
    for (ll i = 0; i < length; i++)
    {
        arr[i] = ran(0, length + 1) + 1;
    }
    return printTreeEdges(arr, length);
}


ll countt(ll n, vector<pair<ll, ll>>& edges) {
    ll count = 0;
    set<ll> st;
    st.insert(1);
    while (st.size() != n) {
        count++;
        for (auto x : edges) {
            if (st.count(x.first) || st.count(x.second)) {
                st.insert(x.first);
                st.insert(x.second);
            }
        }
    }
    return count;
}

//------------------------------------------------------------------------------------------------------------//
struct testcase {
    ll n;
    vector<ll> arr;
};

ll randomNumber(ll a, ll b) {
    return a + (rand() % b);
}

vector<ll> generateRandomPermutation(ll N) {
    vector<ll> numbers(N);
    for(ll i = 0; i < N; i++) {
        numbers[i] = i+1;
    }
    random_shuffle(numbers.begin(), numbers.end());
    return numbers;
}

string randomString(const ll len) {

    string tmp_s;
    static const char alphanum[] =
        "()";
    // "abcdefghijklmnopqrstuvwxyz";
 // "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
 // "abcdefghijklmnopqrstuvwxyz";

    //srand((unsigned)time(NULL) * 1);
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
        ll p = randomNumber(0, x);
        // ll x=randomNumber(0,2);   //for -ve no
        // if(x==0) p=-p;
        ans[i] = p;
    }
    return ans;
}
vector<string> randomStringArr(ll n) {
    vector<string> ans(n);
    for (ll i = 0;i < n;i++) {
        ans[i] = randomString(randomNumber(1, 10));
    }
    return ans;
}
testcase generateTestCase() {
    testcase randomTest;
    randomTest.n = randomNumber(1, 10);
    randomTest.arr = generateRandomPermutation(randomTest.n);
    return randomTest;
}

vector<ll>  bruteForce(testcase T) {
    ll n = T.n;
    vector<ll> arr = T.arr;
    vector<vector<ll>> dp;
    for(ll i = 0; i < n; i++) {
        for(ll j = i; j < n; j++) {
            vector<ll> temp;
            for(ll k = j + 1; k < n; k++) {
                temp.push_back(arr[k]);
            }
            for(ll k = j; k >= i; k--) {
                temp.push_back(arr[k]);
            }
            for(ll k = 0; k < i; k++) {
                temp.push_back(arr[k]);
            }
            dp.push_back(temp);
        }
    }
    sort(all(dp), greater<vector<ll>>());
    return dp[0];
}

vector<ll> optimizedSolution(testcase T) {
    ll n = T.n;
    vector<ll> arr = T.arr;
    vector<ll> res;
    ll maxi = 0;
    ll index = 0;
    for(ll i = 1; i < n; i++) {
        if(arr[i] > maxi) {
            maxi = arr[i];
            index = i;
        }
    }
    vector<vector<ll>> dp;

    for(ll i = 0; i < index; i++) {
        vector<ll> temp;
        for(ll j = index-1; j >= i; j--) {
            temp.push_back(arr[j]);
        }
        for(ll j = 0; j < i; j++) {
            temp.push_back(arr[j]);
        }
        dp.push_back(temp);
    }
    if(index == n-1) {
        vector<ll> temp;
        for(ll i = 0; i < index; i++) {
            temp.push_back(arr[i]);
        }
        dp.push_back(temp);
    }
    sort(all(dp), greater<vector<ll>>());
    for(ll i= index; i<n;i++) res.push_back(arr[i]);
    for(auto x: dp[0]) res.push_back(x);
    return res;
}



bool debugger(ll& t) {
    testcase random = generateTestCase();
    // cout<<random.s<<" ";
    vector<ll>  answ1 = bruteForce(random);
    vector<ll>  answ2 = optimizedSolution(random);
    if (answ1 != answ2) {
        cout << "WA on testcase " << t << endl;
        
        for(auto x: answ1) cout<<x<<" ";
        cout<<endl;
        for(auto x: answ2) cout<<x<<" ";
        cout<<endl;
        cout<<"__________"<<endl;
        // cout<<random.n<<" "<<random.m<<endl;
        // cout<<answ1<<" "<<answ2<<endl;
        cout << random.n << endl;
        for(auto x: random.arr) {
            cout<<x<<" ";
        }
        cout << endl;
        return false;
    }
    else {
        cout << "AC on testcase " << t << endl;
        // cout<<random.n<<endl;
        // for(auto x: random.arr) cout<<x<<" ";
        // cout<<endl;
        // for(auto x: answ1) cout<<x<<" ";
        // cout<<endl;
        // for(auto x: answ2) cout<<x<<" ";
        // cout<<endl;
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