#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = 2147483647;

vi prime_sieve(int n) {
  int mx = (n - 3) >> 1, sq, v, i = -1;
  vi primes;
  bool* prime = new bool[mx + 1];
  memset(prime, 1, mx + 1);
  if (n >= 2) primes.push_back(2);
  while (++i <= mx) if (prime[i]) {
    primes.push_back(v = (i << 1) + 3);
    if ((sq = i * ((i << 1) + 6) + 3) > mx) break;
    for (int j = sq; j <= mx; j += v) prime[j] = false; }
  while (++i <= mx)
    if (prime[i]) primes.push_back((i << 1) + 3);
  delete[] prime;
  return primes; }

vi primes = prime_sieve(32000000);

ll bt(int at, ll n, int par, bool just) {
    if (n == 0) {
        return 0;
    }
    ll sm = 0;
    if (just) {
        sm += par * n;
    }
    // TODO: Unroll part of the recursion
    if (at < primes.size() && n >= primes[at]) {
        sm += bt(at+1, n, par, false);
        sm += bt(at+1, n / primes[at] / primes[at], -par, true);
    }
    return sm;
}

int main() {
    ll n;
    cin >> n;
    cout << bt(0, n, 1, true) << endl;

    return 0;
}

