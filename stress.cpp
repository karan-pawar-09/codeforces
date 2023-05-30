/*
author:Karan
created:23.08.2021 22:20:42
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'


const int mx = 2e5+10;
map<pair<int,int>, int> M;
vector<int> graph[mx];
int res;
void dfs(int node, int par, int ans, int rank) {
    res = max(ans, res);
    for(auto x: graph[node]) {
        if(x != par) {
            int temp = ans;
            int tempRank = M[{x, node}];
            if(tempRank < rank) {
                temp++;
            }
            dfs(x, node, temp, tempRank);
        }
    }
}


vector<pair<int, int>> printTreeEdges(vector<int> prufer, int m)
{
	int vertices = m + 2;
	vector<int> vertex_set(vertices);

	// Initialize the array of vertices
	for (int i = 0; i < vertices; i++)
		vertex_set[i] = 0;

	// Number of occurrences of vertex in code
	for (int i = 0; i < vertices - 2; i++)
		vertex_set[prufer[i] - 1] += 1;


	int j = 0;

	// Find the smallest label not present in
	// prufer[].
    vector<pair<int, int>> edges;
	for (int i = 0; i < vertices - 2; i++)
	{
		for (j = 0; j < vertices; j++)
		{

			// If j+1 is not present in prufer set
			if (vertex_set[j] == 0)
			{

				// Remove from Prufer set and print
				// pair.
				vertex_set[j] = -1;
                edges.push_back({j+1, prufer[i]});

				vertex_set[prufer[i] - 1]--;

				break;
			}
		}
	}

	j = 0;

	// For the last element
    int a, b;
	for (int i = 0; i < vertices; i++)
	{
		if (vertex_set[i] == 0 && j == 0)
		{

            a = i+1;
			//cout << "(" << (i + 1) << ", ";
			j++;
		}
		else if (vertex_set[i] == 0 && j == 1) {
			//cout << (i + 1) << ")\n";
            b= i+1;
        }
	}
    edges.push_back({a, b});
    return edges;
}

// generate random numbers in between l an r
int ran(int l, int r)
{
	return l + (rand() % (r - l + 1));
}

// Function to Generate Random Tree
vector<pair<int,int>> generateRandomTree(int n)
{

	int length = n - 2;
	vector<int> arr(length);

	// Loop to Generate Random Array
	for (int i = 0; i < length; i++)
	{
		arr[i] = ran(0, length + 1) + 1;
	}
	return printTreeEdges(arr, length);
}


int countt(int n, vector<pair<int, int>> &edges) {
    int count = 0;
    set<int> st;
    st.insert(1);
    while(st.size() != n) {
        count++;
        for(auto x: edges) {
            if(st.count(x.first) || st.count(x.second)) {
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
    vector<pair<int, int>> arr;
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
    randomTest.n = randomNumber(2,10);
    randomTest.arr = generateRandomTree(randomTest.n);
    return randomTest;
}

int  bruteForce(testcase T) {
    ll n = T.n;
    vector<pair<int, int>> arr = T.arr;
    M.clear();
    res = -1;
    for(int i=0;i<=n;i++) {
        graph[i].clear();
    }
   
    for(ll i=0;i<n-1;i++) {
        ll a = arr[i].first;
        ll b = arr[i].second;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        M[{a, b}] = i;
        M[{b, a}] = i;
    }

    dfs(1, -1, 0, 100000000);
    return res;

}

int optimizedSolution(testcase T) {
    ll n = T.n;
    vector<pair<int, int>> arr = T.arr;
    return countt(n, arr);
}



bool debugger(ll& t) {
    testcase random = generateTestCase();
    // cout<<random.s<<" ";
    int  answ1 = bruteForce(random);
    int  answ2 = optimizedSolution(random);
    if (answ1 != answ2) {
        cout << "WA on testcase " << t << endl;
        cout<<answ1<<" "<<answ2<<endl;
        // cout<<random.n<<" "<<random.m<<endl;
        // cout<<answ1<<" "<<answ2<<endl;
        cout<<random.n<<endl;
        for(auto x: random.arr) {
            cout<<x.first<<" "<<x.second<<endl;
        }
        cout << endl;
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