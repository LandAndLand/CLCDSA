main(long n){scanf("%ld",&n);printf("%.f",n/5.5+.33);} ./Main.c:1:1: warning: return type defaults to �int� [-Wimplicit-int]
 main(long n){scanf("%ld",&n);printf("%.f",n/5.5+.33);}
 ^
./Main.c: In function �main�:
./Main.c:1:14: warning: implicit declaration of function �scanf� [-Wimplicit-function-declaration]
 main(long n){scanf("%ld",&n);printf("%.f",n/5.5+.33);}
              ^
./Main.c:1:14: warning: incompatible implicit declaration of built-in function �scanf�
./Main.c:1:14: note: include �<stdio.h>� or provide a declaration of �scanf�
./Main.c:1:30: warning: implicit declaration of function �printf� [-Wimplicit-function-declaration]
 main(long n){scanf("%ld",&n);printf("%.f",n/5.5+.33);}
                              ^
./Main.c:1:30: warning: incompatible implicit declaration of built-in function �printf�
./Main.c:1:30: note: include �<stdio.h>� or provide a declaration of �printf�