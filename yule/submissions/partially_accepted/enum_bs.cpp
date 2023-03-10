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

vi primes;
int n;
int cnt(int at, int cur) {

    int res = 0;

    // One more prime
    int lo = at,
        hi = primes.size() - 1,
        last = at-1;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        if ((ll)cur * primes[mid] <= n) {
            last = mid;
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
    res += last - at + 1;

    // Two or more primes
    rep(nxt, at, primes.size()) {
        ll cur2 = (ll)cur * primes[nxt];
        if (cur2 * primes[nxt] > n) break;
        res += cnt(nxt+1, cur2);
    }
    return res;
}

int main() {
    cin >> n;
    primes = prime_sieve(n+1);
    cout << 1 + cnt(0,1) << endl;

    return 0;
}

