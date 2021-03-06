#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <ctime>
#include<complex>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b)-1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
//typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 1000 * 100 + 47;
const int MAX1 = 1000 * 100 + 47;

int A[MAX];

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	FOR(i, 0, n) cin >> A[i];
	sort(A, A + n);
	reverse(A, A + n);
	int x = 0, y = 1;
	FOR(i, 0, n + 1)
	{
		if (i + 1 > A[i])
		{
			x = i - 1;
			y = i;
			break;
		}
	}

	//cout << "*" << x << " " << y << endl;

	bool v1 = (A[x] - y + 1) % 2;
	int cnt = 0;
	FOR(i, x + 1, n)
	{
		cnt += A[i] == y;
	}

	//cout << "!!" << cnt << endl;
	bool v2 = (cnt + 1) % 2;
	//cout << "!!" << v1 << " " << v2 << endl;
	if (!v1 || !v2)
	{
		cout << "First" << endl;
		return 0;
	}

	cout << "Second" << endl;
}