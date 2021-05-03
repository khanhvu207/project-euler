#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define TLE() cerr<<"\nTime elapsed: "<<1000*clock()/CLOCKS_PER_SEC<<"ms.\n";
const ll MOD = 1E9+7;
const ll IINF = 1E18;
const int INF = 1e9;
const double EPS = 1E-9;
const double PI = atan(1.0) * 4.0;
template<class T> T getbit(T s, int i) {return s>>i&1;}
template<class T> void flipbit(T& s, int i) {s^=(1LL<<i);}
constexpr int cntbit(ll x) {return __builtin_popcountll(x);}
constexpr int lg2(ll x) {return __lg(x);} // return int(log2(x))
// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
ll fpow(ll a,ll p){ll res=1LL;while(p){if(p&1LL) res=res*a%MOD;a=a*a%MOD;p>>=1LL;} return res;}

void io_optimization() {
	ios_base::sync_with_stdio(0); cin.tie(0);
}

int main() {
	int d = 100;
	int res = 0;
	set<int> cnt[d + 5];
	bool vst[d + 5] = {false};
	for (int a = 2; a <= d; ++a) {
		if (vst[a]) continue;
		for (int x = a, p = 1; x <= d; x *= a, ++p) {
			vst[x] = true;
			for (int b = 2; b <= d; ++b) 
				cnt[a].insert(p * b);
		}
		res += sz(cnt[a]);
	}
	cout << res << '\n';
	// ^ solution here
	TLE();
	return 0;
}