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

bool distict_digits(int x) {
	set<int> s;
	while (x > 0) {
		if (s.count(x % 10) > 0) return false;
		s.insert(x % 10);
		x /= 10;
	}
	return true;
}

const int ok = (1 << 10) - 2;
map<int, int> encoding;
vector<int> cands;

int main() {
	for (int i = 1; i <= 1000000; ++i) 
		if (distict_digits(i)) {
			cands.push_back(i);
			int x = i;
			int mask = 0;
			while (x > 0) {
				mask |= (1 << (x % 10));
				x /= 10;
			}
			encoding[i] = mask;
		}
	
	vector<ll> res;
	for (int i : cands) {
		for (int j : cands) {
			if (j * j > i) break;
			if (i % j == 0) {
				if (!distict_digits(i / j)) continue;
				int mask = 0;
				if (encoding[i] & encoding[j]) continue;
				if (encoding[i] & encoding[i / j]) continue;
				if (encoding[j] & encoding[i / j]) continue;
				mask |= encoding[i];
				mask |= encoding[j];
				mask |= encoding[i / j];
				if (mask == ok) {
					res.push_back(i);
					break;
				}
			}
		}
	}
	ll sum = accumulate(all(res), 0LL);
	cout << sum << '\n';
	// ^ solution here
	TLE();
	return 0;
}