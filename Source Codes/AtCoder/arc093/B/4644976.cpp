#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

const int MOD = 1e9 + 7;
const int iINF = 1000000000;
const long long int llINF = 1000000000000000000;

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vvvl = vector<vector<vector<ll>>>;
using edge = struct {
  int to;
  int cost;
};
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define RREP(i, n) for (ll i = (n)-1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define AUTO(i, m) for (auto &i : m)
#define ALL(a) (a).begin(), (a).end()
#define MAX(vec) *std::max_element(vec.begin(), vec.end())
#define MIN(vec) *std::min_element(vec.begin(), vec.end())
#define ARGMAX(vec)                                                            \
  std::distance(vec.begin(), std::max_element(vec.begin(), vec.end()))
#define ARGMIN(vec)                                                            \
  std::distance(vec.begin(), std::min_element(vec.begin(), vec.end()))
#define BIT(n, num) std::bitset<(n)>((num)).to_string()
#define REV(T) greater<T>()
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define VVL(a, b, c) vector<vector<ll>>(a, vector<ll>(b, c))
#define VVVL(a, b, c, d)                                                       \
  vector<vector<vector<ll>>>(a, vector<vector<ll>>(b, vector<ll>(c, d)))

typedef pair<ll, ll> pll;
bool paircomp(const pll &a, const pll &b) {
  if (a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}

ll POW(ll n, ll m) {
  if (m == 0) {
    return 1;
  } else if (m % 2 == 0) {
    ll tmp = POW(n, m / 2);
    return (tmp * tmp) % MOD;
  } else {
    return (n * POW(n, m - 1)) % MOD;
  }
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll A, B;
  char c1 = '.';
  char c2 = '#';
  cin >> A >> B;
  A--;
  B--;

  cout << ((A / 50) + 2 + (B / 50)) * 3 << " " << 100 << endl;

  REP(i, A / 50) {
    REP(j, 100) cout << c2;
    cout << endl;
    REP(j, 100) cout << (j % 2 == 0 ? c2 : c1);
    cout << endl;
    REP(j, 100) cout << c2;
    cout << endl;
  }

  REP(j, 100) cout << c2;
  cout << endl;
  REP(j, (A % 50) * 2) cout << (j % 2 == 0 ? c2 : c1);
  FOR(j, (A % 50) * 2, 100) cout << c2;
  cout << endl;
  REP(j, 100) cout << c2;
  cout << endl;

  REP(i, B / 50) {
    REP(j, 100) cout << c1;
    cout << endl;
    REP(j, 100) cout << (j % 2 == 0 ? c1 : c2);
    cout << endl;
    REP(j, 100) cout << c1;
    cout << endl;
  }

  REP(j, 100) cout << c1;
  cout << endl;
  REP(j, (B % 50) * 2) cout << (j % 2 == 0 ? c1 : c2);
  FOR(j, (B % 50) * 2, 100) cout << c1;
  cout << endl;
  REP(j, 100) cout << c1;
  cout << endl;

  return 0;
}