/*
cat <<EOF >mistaken-paste
*/

#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define BIG 2000000007
#define VERYBIG 200000000000007LL

#define MOD 1000000007
typedef uint64_t ull;
typedef  int64_t sll;

#define N_MAX 200000
#define M_MAX 100000

#ifdef __cplusplus
#include <queue>
#include <stack>
// #include <tuple>
#include <functional>

using namespace std; // I'm NOT gonna use C++ without compro. shit

typedef priority_queue<ull, vector<ull>, greater<ull> > upque123;
typedef priority_queue<ull, vector<ull> > upque321;
typedef priority_queue<sll, vector<sll>, greater<sll> > spque123;
typedef priority_queue<sll, vector<sll> > spque321;

#endif

typedef struct {
	int32_t a;
	int32_t b;
} hw;

typedef struct {
	sll a;
	sll b;
} hwll;

typedef struct {
	hwll a;
	hwll b;
} linell;


typedef struct {
	ull s;
	ull t;
	int32_t c;
} struct_a;

typedef struct {
	int32_t from;
	int32_t to;
	sll cost;
} struct_b;



const hw vector8[8] = {
	{-1, -1},
	{-1,  0},
	{-1, +1},
	{ 0, -1},
	{ 0, +1},
	{+1, -1},
	{+1,  0},
	{+1, +1}
};

ull n, m;
ull h, w;
ull k;
ull q;
ull vua, vub, vuc, vud, vue, vuf;
sll vsa, vsb, vsc, vsd, vse, vsf;
long double vra, vrb, vrc;
double vda, vdb, vdc;
size_t slen;
size_t tlen;
char ch, dh;

void swap_adj (ull *a, ull *b) {
	if (*a != *b) {
		ull tmp = *b;
		*b = *a;
		*a = tmp;
	}
	return;
}

int32_t digits (ull x) {
	int32_t i = 1;
	while (x >= 10) {
		x /= 10;
		i++;
	}
	return i;
}

ull umin (ull x, ull y) {
	return (x < y) ? x : y;
}

ull umax (ull x, ull y) {
	return (x > y) ? x : y;
}

sll smin (sll x, sll y) {
	return (x < y) ? x : y;
}

sll smax (sll x, sll y) {
	return (x > y) ? x : y;
}

ull gcd (ull x, ull y) {
	if (x < y) {
		return gcd(y, x);
	} else if (y == 0) {
		return x;
	} else {
		return gcd(y, x % y);
	}
}

ull bitpow (ull a, ull x, ull modulo) {
	ull result = 1;
	while (x) {
		if (x & 1) {
			result *= a;
			result %= modulo;
		}
		x /= 2;
		a = (a * a) % modulo;
	}
	return result;
}

ull divide (ull a, ull b, ull modulo) {
	return (a * bitpow(b, modulo - 2, modulo)) % modulo;
}

ull ullabs (ull a, ull b) {
	if (a >= b) {
		return a - b;
	} else {
		return b - a;
	}
}

sll sllabs (sll a, sll b) {
	if (a >= b) {
		return a - b;
	} else {
		return b - a;
	}
}

sll nibutanlobo (bool (*func)(sll arg), sll ok, sll ng) {
	while (sllabs(ok, ng) > 1) {
		sll med = (ok + ng) / 2;
		if (func(med)) {
			ok = med;
		} else {
			ng = med;
		}

		// printf("debug: [%lld %lld)\n", ok, ng);
	}

	if (!func(ok)) return ok * 2 - ng;
	return ok;
}

void printUquotient (ull left, ull right) {
	const int32_t digits = 20;

	printf("%llu.", left / right);
	left %= right;
	for (int32_t i = 0; i < digits; i++) {
		left *= 10;
		printf("%1d", left / right);
		left %= right;
	}
	puts("");

	return;
}

void printSquotient (sll left, sll right) {
	if (left * right < 0) putchar('-');
	printUquotient(sllabs(left, 0), sllabs(right, 0));

	return;
}

int bitcount (ull n) {
	int result = 0;
	while (n) {
		if (n & 1) result++;
		n /= 2;
	}
	return result;
}

#ifdef __cplusplus

typedef struct {
	int32_t to;
	sll cost;
} edge;
typedef pair<sll, int32_t> P;

std::vector<edge> g[N_MAX];
void dijk_init (ull n, struct_b arr[]) {
	edge x;
	for (int32_t i = 0; i < n; i++) {
		x.to = arr[i].to;
		x.cost = arr[i].cost;
		g[arr[i].from].push_back(x);
	}
}

bool dijkstra (int s, sll distance[]) {
	priority_queue<P, std::vector<P>, greater<P> > que; // (????, ????)
	que.push(P(distance[s], s));

	bool ischanged = false;
	while (!que.empty()) {
		P p = que.top();
		que.pop();

		sll v = p.second;
		if (distance[v] < p.first) continue;

		int32_t maxsize = g[v].size();
		for (int32_t i = 0; i < maxsize; i++) {
			edge e = g[v][i];
			if (distance[e.to] > distance[v] + e.cost) {
				distance[e.to] = distance[v] + e.cost;
				ischanged = true;
				que.push(P(distance[e.to], e.to));
			}
		}
	}

	return ischanged;
}

#endif

// sll dist[N_MAX];
// struct_b path[M_MAX * 2];

// ull a[N_MAX];
// ull a[M_MAX];
// sll a[N_MAX];
// ull a[N_MAX][N_MAX];
// sll a[N_MAX][N_MAX];
// ull b[N_MAX];
// ull b[M_MAX];
// sll b[N_MAX];
// ull c[N_MAX];
// sll c[M_MAX];
// char c[N_MAX];
// char s[N_MAX + 1];
// char s[N_MAX + 1][N_MAX + 1];
// char s[N_MAX + 1][M_MAX + 1];
// char t[N_MAX + 1];

// ull alphabets[26];
// char alphabets[26];

// ull dp[N_MAX + 1];
// sll dp[N_MAX + 1];
// ull dp[N_MAX + 1][N_MAX + 1];
// sll dp[N_MAX + 1][N_MAX + 1];
// bool dp[N_MAX + 1];
// bool dp[N_MAX + 1][N_MAX + 1];
// hwll arr[N_MAX];
// hwll arr[M_MAX];
// hwll brr[M_MAX];

ull p10[30];

double distance (sll x1, sll y1, sll x2, sll y2) {
	double xdist2, ydist2, origindist, dist;

	xdist2 = (x1 - x2) * (x1 - x2);
	ydist2 = (y1 - y2) * (y1 - y2);
	return sqrt(xdist2 + ydist2);
}

int32_t pullcomp (const void *left, const void *right) {
	ull l = *(ull*)left;
	ull r = *(ull*)right;
	if (l < r) {
		return -1;
	}
	if (l > r) {
		return +1;
	}
	return 0;
}

int32_t phwllABcomp (const void *left, const void *right) {
	hwll l = *(hwll*)left;
	hwll r = *(hwll*)right;
	if (l.a < r.a) {
		return -1;
	}
	if (l.a > r.a) {
		return +1;
	}
	if (l.b < r.b) {
		return -1;
	}
	if (l.b > r.b) {
		return +1;
	}
	return 0;
}

ull singleContained (ull x) {
	ull itemnum = n / x;
	// ull maxnum = p10[x - 1] * 9;

	if (x > 10 || itemnum < p10[x - 1] * 9) {
		return MOD + bitpow(10, x - 1, MOD) * 9 - itemnum + 1;
	} else {
		return 0;
	}
}

ull solve () {
	sll i, j, ki;
	ull result = 0;
	// sll result = 0;
	// double result = 0;
	ull maybe = 0;
	// sll maybe = 0;
	ull sum = 0;
	// sll sum = 0;
	ull item;
	ull *dpcell;
	// ????????????

	p10[0] = 1;
	for (i = 1; i <= 15; i++) {
		p10[i] = p10[i - 1] * 10;
	}

	result = 0;

	for (i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ull x;

			result = (result + singleContained(i)) % MOD;
			// printf("\t%lld: %llu\n", i, result);
			if (i * i != n) {
				result = (result + singleContained(n / i)) % MOD;
				// printf("\t%lld: %llu\n", n / i, result);
			}
		}
	}
	// printf("%llu...\n", result);

	const ull fullfillable = 7;

	for (i = 1; i <= fullfillable; i++) {
		ull medfilled;
		medfilled = 0;
		for (j = i; j <= fullfillable; j++) {
			// printf("%lld/%lld\n", i, j);
			medfilled += p10[j - 1] * j * 9;
			// printf("%lld/%lld: %llu\n", i, j, medfilled);

			if (medfilled > n) {
				break;
			}
			ull remain = n - medfilled;

			ull lx = i - 1;
			ull rx = j + 1;
			ull lmax = (lx ? p10[lx - 1] * 9 - 1 : 0);
			ull rmax = p10[rx - 1] * 9 - 1;

			if (lx == 0) {
				// printf("remain; %llu\n", remain);
				if (remain % rx) continue;
				sll actualright = remain / rx;
				if (actualright < rmax) {
					result++;
					result %= MOD;
				}
				// printf("->>%llu\n", result);
				continue;
			}

			ull ldelta = rx / gcd(lx, rx);
			sll leftmax = lmax, rightmax = rmax;
			// printf("\t%lld/%lld, %lld/%lld\n", leftmax, rightmax, lx, rx);
			// fflush(stdout);
			// scanf("%*s");
			while (leftmax >= 0 && ((remain < leftmax * lx) || ((remain - leftmax * lx) % rx))) {
				// printf("\tl: %lld\n", leftmax);
				// scanf("%*s");
				leftmax--;
			}
			while (rightmax >= 0 && ((remain < rightmax * rx) || ((remain - rightmax * rx) % lx))) {
				// printf("\tr: %lld\n", rightmax);
				// scanf("%*s");
				rightmax--;
			}
			// printf("lm: %lld, rm: %lld\n", leftmax, rightmax);

			if (leftmax < 0 || rightmax < 0) continue;
			ull leftmin = (lx ? (remain - rightmax * rx) / lx : 0);
			if (leftmin > leftmax) continue;

			result += (leftmax - leftmin) / ldelta + 1;
			result %= MOD;
			// printf("->%llu\n", result);
		}
	}
	// printf("%llu...\n", result);

	i = 1;
	ull minlen = 1;
	ull currentx = 1;
	while (i <= n) {
		if (n % i) {
			ull right = n % i;
			ull left = i - right;
			ull x = n / i;

			// printf("x: %lld, left: %llu, right: %llu\n", x, left, right);
			if (x > 10 || (left < p10[x - 1] * 9 && right < p10[x] * 9)) {
				result++;
				result %= MOD;
			}
		}

		i++;
		// if (i >= p10[currentx]) currentx++;
		// minlen += p10[currentx - 1];
		// printf("%lld:: %llu(%llu)\n", i, result, minlen);
	}

	printf("%llu\n", result);
	// printf("%.12lf\n", (double)result);
	// puts(s);

	return 0;

	success:
	// puts("YES");
	// puts("Yes");
	printf("%llu\n", result);
	// puts("0");
	// puts("CONTINUE");
	return 0;

	fail:
	// puts("NO");
	// puts("No");
	// puts("0");
	puts("-1");
	// puts("-1 -1 -1");
	// puts("Impossible");
	return 1;
}

int32_t main (void) {
	int32_t i, j;
	int32_t x, y;

	// scanf("%lf%lf", &vda, &vdb);
	// scanf("%lld%lld%lld%lld", &vsa, &vsb, &vsc, &vsd);
	// scanf("%llu%llu", &vua, &vub, &vuc, &vud);
	// scanf("%llu%llu", &h, &w);
	scanf("%llu", &n, &m);
	// scanf("%*llu");
	// scanf("%llu", &k, &m, &n);
	// scanf("%llu%llu", &vua, &vub, &vuc, &vud, &vue, &vuf);
	// scanf("%lld", &vsa, &vsb, &vsc);
	// scanf("%s", s);
	// scanf("%s", t);
	// scanf("%llu", &m);
	// scanf("%llu", &q);
	// for (i = 0; i < n; i++) {
	// 	scanf("%llu", &a[i]);
	// 	// a[i]--;
	// }
	// for (i = 0; i < n; i++) {
	// 	scanf("%llu", &b[i]);
	// }
	// for (i = 0; i < h; i++) {
	// 	scanf("%llu", &a[i]);
	// }

	// for (i = 0; i < w; i++) {
	// 	scanf("%llu", &b[i]);
	// }	
	// for (i = 0; i < m; i++) {
	// 	scanf("%llu", &b[i]);
	// }
	// for (i = 0; i < h; i++) {
	// 	scanf("%s", s[i]);
	// }
	// scanf("%s", t);
	// for (i = 0; i < n; i++) {
	// 	scanf("%lld", &a[i]);
	// 	scanf("%lld", &b[i]);
	// 	// scanf("%llu", &c[i]);
	// 	// arr[i].a--;
	// 	// arr[i].b--;
	// 	// a[i]--;
	// 	// b[i]--;
	// }
	// for (i = 0; i < m; i++) {
	// 	scanf("%llu%llu", &arr[i].a, &arr[i].b);
	// 	arr[i].a--;
	// 	arr[i].b--;
	// }
	// for (i = 0; i < k; i++) {
	// 	scanf("%llu%llu", &brr[i].a, &brr[i].b);
	// 	brr[i].a--;
	// 	brr[i].b--;
	// }
	// for (i = 0; i < m; i++) {
	// 	for (j = 0; j < m; j++) {
	// 		scanf("%llu", &a[i][j]);
	// 	}
	// }
	// for (i = 0; i < n; i++) {
	// 	scanf("%llu%llu%llu", &a[i], &b[i], &c[i]);
	// }

	// scanf("%llu", &q);
	// scanf("%llu", &k);
	// k--;
	// for (i = 0; i < q; i++) {
	// 	scanf("%llu%llu", &a[i], &b[i]);
	// 	a[i]--;
	// 	b[i]--;
	// 	// solve();
	// }

	// for (i = 0; i < m; i++) {
	// 	scanf("%llu%llu", &arr[i].a, &arr[i].b);
	// 	arr[i].a--;
	// 	arr[i].b--;
	// }
	// for (i = 0; i < n; i++) {
	// 	for (j = 0; j < m; j++) {
	// 		scanf("%llu", &a[i][j]);
	// 		a[i][j]--;
	// 	}
	// }

	solve();

	// for (i = 0; i < m; i++) {
	// 	scanf("%llu%llu%llu", &vua, &vub, &vuc);
	// 	// scanf("%s%s", s, t);
	// 	// scanf("%f%f%f", &vda, &vdb, &vdc);
	// 	// scanf("%s", s);
	// 	solve();
	// }

	// while (scanf("%llu%llu", &n, &k), n + k) {
	// 	for (i = 0; i < n; i++) {
	// 		scanf("%llu", &a[i]);
	// 	}
	// 	solve();
	// }

	return 0;
} ./Main.c: In function �printUquotient�:
./Main.c:188:9: warning: format �%llu� expects argument of type �long long unsigned int�, but argument 2 has type �ull {aka long unsigned int}� [-Wformat=]
  printf("%llu.", left / right);
         ^
./Main.c:192:10: warning: format �%d� expects argument of type �int�, but argument 2 has type �ull {aka long unsigned int}� [-Wformat=]
   printf("%1d", left / right);
          ^
./Main.c: In function �solve�:
./Main.c:461:9: warning: format �%llu� expects argument of type �long long unsigned int�, but argument 2 has type �ull {aka long unsigned int}� [-Wformat=]
  printf("%llu\n", result);
         ^
./Main.c:470:9: warning: format �%llu� expects argument of type �long long unsigned int�, but argument 2 has type �ull {aka long unsigned int}� [-Wformat=]
  printf("%llu\n", result);
         ^
./Main.c: In function �main�:
./Main.c:493:8: warning: format �%llu� expects argument of type �long long unsigned int *�, but argument 2 has type �ull * {aka long unsigned int *}�...