s;main(x,a){scanf("%*d%d",&x);for(;~(scanf("%d",&a));x/=2)s+=x%2*a;printf("%d\n",s);} ./Main.c:1:1: warning: data definition has no type or storage class
 s;main(x,a){scanf("%*d%d",&x);for(;~(scanf("%d",&a));x/=2)s+=x%2*a;printf("%d\n",s);}
 ^
./Main.c:1:1: warning: type defaults to �int� in declaration of �s� [-Wimplicit-int]
./Main.c:1:3: warning: return type defaults to �int� [-Wimplicit-int]
 s;main(x,a){scanf("%*d%d",&x);for(;~(scanf("%d",&a));x/=2)s+=x%2*a;printf("%d\n",s);}
   ^
./Main.c: In function �main�:
./Main.c:1:3: warning: type of �x� defaults to �int� [-Wimplicit-int]
./Main.c:1:3: warning: type of �a� defaults to �int� [-Wimplicit-int]
./Main.c:1:13: warning: implicit declaration of function �scanf� [-Wimplicit-function-declaration]
 s;main(x,a){scanf("%*d%d",&x);for(;~(scanf("%d",&a));x/=2)s+=x%2*a;printf("%d\n",s);}
             ^
./Main.c:1:13: warning: incompatible implicit declaration of built-in function �scanf�
./Main.c:1:13: note: include �<stdio.h>� or provide a declaration of �scanf�
./Main.c:1:68: warning: implicit declaration of function �printf� [-Wimplicit-functi...