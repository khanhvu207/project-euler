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

int compute_cycle(int x) {
	// Compute the reciprocal cycle of x
	// For example: 1 / 7 = 0.(142857) -> cycle length = 6
	int t = 1;
	int counter = 0;
	int res = 0;
	map<int, int> last_time;
	for (int i = 0; i < 2000 && t > 0; ++counter, ++i) {
		if (last_time.count(t) != 0) {
			res = max(res, counter - last_time[t]);
		}
		last_time[t] = counter;
		t *= 10;
		int p = t / x;
		t -= p * x;
	}	
	return res;
}

int main() {
	int d = 1000;
	int res = 0;
	int best = 0;
	for (int i = 1; i <= d; ++i) {
		int cycle_length = compute_cycle(i);
		if (cycle_length > best) {
			best = cycle_length;
			res = i;
		}
	}
	cout << res << '\n';
	return 0;
}