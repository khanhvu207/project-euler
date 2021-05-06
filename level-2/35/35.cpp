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

const int MAXSIEVE = 1E6 + 5;
bitset <MAXSIEVE> notComposite;
vector <int> prime;

void sieve() {
    notComposite.flip();
    for (int i = 2; i * i < MAXSIEVE; ++i)
        if (notComposite.test(i))
            for (int j = i * i; j < MAXSIEVE; j += i) notComposite.reset(j);
    for (int i = 2; i < MAXSIEVE; ++i)
        if (notComposite.test(i)) prime.emplace_back(i);
}

bool is_prime(int x) {
	return binary_search(all(prime), x);
}

int count_digits(int x) {
	int sum = 0;
	while (x > 0) x /= 10, sum++;
	return sum;
}

int rotate(int p, int num_digits) {
	int x = p;
	int t = 1;
	while (--num_digits) x /= 10, t *= 10;
	return (p % t) * 10 + x;
}

bool check(int p) {
	set<int> s;
	int d = count_digits(p);
	while (true) {
		if (s.count(p) > 0) break;
		if (!is_prime(p)) return false;
		s.insert(p);
		p = rotate(p, d);
	}
	return true;
}

int main() {
	sieve();
	int cnt = 0;
	for (int p : prime) {
		if (!check(p)) continue;
		++cnt;
		cerr << p << '\n';
	}
	cout << cnt << '\n';
	// ^ solution here
	TLE();
	return 0;
}