s[1<<17];k,A,B,a;main(M){for(scanf("%*d%d",s);~scanf("%d%d",&A,&B);M=1){for(;B/M/M;s[++M]-=k)s[M]+=k=~-A/M<B/M;for(k=B/M;k;s[M=B/k--+1]--)s[M=fmax(~-A/k+1,M)]++;}for(;k++<*s;)printf("%d ",a+=s[k]);} ./Main.c:1:1: warning: data definition has no type or storage class
 s[1<<17];k,A,B,a;main(M){for(scanf("%*d%d",s);~scanf("%d%d",&A,&B);M=1){for(;B/M/M;s[++M]-=k)s[M]+=k=~-A/M<B/M;for(k=B/M;k;s[M=B/k--+1]--)s[M=fmax(~-A/k+1,M)]++;}for(;k++<*s;)printf("%d ",a+=s[k]);}
 ^
./Main.c:1:1: warning: type defaults to �int� in declaration of �s� [-Wimplicit-int]
./Main.c:1:10: warning: data definition has no type or storage class
 s[1<<17];k,A,B,a;main(M){for(scanf("%*d%d",s);~scanf("%d%d",&A,&B);M=1){for(;B/M/M;s[++M]-=k)s[M]+=k=~-A/M<B/M;for(k=B/M;k;s[M=B/k--+1]--)s[M=fmax(~-A/k+1,M)]++;}for(;k++<*s;)printf("%d ",a+=s[k]);}
          ^
./Main.c:1:10: warning: type defaults to �int� in declaration of �k� [-Wimplicit-int]
./Main.c:1:12: warning: type defaults to �int� in declaration of �A� [-Wimplicit-int]
 s[1<<17];k,A,B,a;main(M){for(scanf("%*d%d",s);~scanf("%d%d",&A,&B);M=1){for(;B/M/M;s[++M]-=k)s[M]+=k=~-A/M<B/M;for(k=B/M;k;s[M=B/k--+1]--)s[M=fmax(~-A/k+1,M)]++;}for(;k++<*s;)printf("%d ",a+=s[k]);}
            ^
....