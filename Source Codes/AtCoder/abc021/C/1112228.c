long M=1e9+7,s;d[200][101],n,a,b,m,u,v,c[101],G[101][200];main(){scanf("%d%d%d%*d",&n,&a,&b);for(n++;~scanf("%d%d",&u,&v);G[u][c[u]++]=v)G[v][c[v]++]=u;for(d[m=0][a]=1;!d[m++][b];)for(u=n;s=0,--u;d[m][u]=s%M)for(v=c[u];v--;s+=d[m-1][G[u][v]]);printf("%d\n",d[m-1][b]);} ./Main.c:1:16: warning: data definition has no type or storage class
 long M=1e9+7,s;d[200][101],n,a,b,m,u,v,c[101],G[101][200];main(){scanf("%d%d%d%*d",&n,&a,&b);for(n++;~scanf("%d%d",&u,&v);G[u][c[u]++]=v)G[v][c[v]++]=u;for(d[m=0][a]=1;!d[m++][b];)for(u=n;s=0,--u;d[m][u]=s%M)for(v=c[u];v--;s+=d[m-1][G[u][v]]);printf("%d\n",d[m-1][b]);}
                ^
./Main.c:1:16: warning: type defaults to �int� in declaration of �d� [-Wimplicit-int]
./Main.c:1:28: warning: type defaults to �int� in declaration of �n� [-Wimplicit-int]
 long M=1e9+7,s;d[200][101],n,a,b,m,u,v,c[101],G[101][200];main(){scanf("%d%d%d%*d",&n,&a,&b);for(n++;~scanf("%d%d",&u,&v);G[u][c[u]++]=v)G[v][c[v]++]=u;for(d[m=0][a]=1;!d[m++][b];)for(u=n;s=0,--u;d[m][u]=s%M)for(v=c[u];v--;s+=d[m-1][G[u][v]]);printf("%d\n",d[m-1][b]);}
                            ^
./Main.c:1:30: warning: type defaults to �int� in declaration of �a� [-Wimplicit-int]
 long M=1e9+7,s;d[200][101],n,a,b,m,u,v,c[101],G[101][200];main(){scanf("%d%d%d%*d",&n,&a,&b);for(n++;~scan...