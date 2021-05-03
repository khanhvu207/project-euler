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

// f(n) = n^2 + an + b
// b has to be a prime number, since n = 0, f(n) = b

bool is_prime(int x) {
	if (x < 2) return false;
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0) return false;
	return true;
}

int main() {
	int d = 1000;
	vector<int> prime;
	for (int i = 0; i <= d; ++i) 
		if (is_prime(i)) prime.push_back(i);
	int res = 0;
	int best = 0;
	for (int b : prime) {
		for (int a = -999; a < 1000; ++a) {
			for (int n = 0; is_prime(n * n + a * n + b); ++n) {
				if (n > best) {
					best = n;
					res = a * b;
				}
			}
		}
	}
	cout << best << ' ' << res << '\n';
	// ^ solution here
	TLE();
	return 0;
}