#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 100000000
#define FOR(i,a,n) for(i=(a);i<(n);i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
ll dfs(ll a,ll b){
	ll c;
	if(a==b) return a;
	if(a>b) swap(ll,a,b);
	c=(b-1)/a;
	return 2*a*c+dfs(a,b-a*c);
}
int main(void)
{
	ll n,x;
	scanf("%lld%lld",&n,&x);
	printf("%lld\n",n+dfs(x,n-x));
	return 0;
} ./Main.c: In function �main�:
./Main.c:30:2: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&x);
  ^