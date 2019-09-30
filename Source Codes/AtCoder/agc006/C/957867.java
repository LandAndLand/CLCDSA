import java.io.*;
import java.util.*;
public class Main {
  
 public static void main(String[] args)
 {
  int n=Fs.nextInt();
  long[] x=Fs.nextLongArray(n);
  long[] sabu=new long[n];
  for(int i=1;i<n;i++)sabu[i]=x[i]-x[i-1];
  int m=Fs.nextInt();
  long k=Fs.nextLong();
  int[] a=Fs.nextIntArray(m);
  long[] tikan=e(n);
  long[] h=e(n);
  for(int i=0;i<m;i++){
   int sw=a[i];
   long tem=h[sw-1];
   h[sw-1]=h[sw];
   h[sw]=tem;
  }
  h=pow(h,k);
  sabu=mul(h,sabu);
  for(int i=1;i<n;i++)x[i]=x[i-1]+sabu[i];
  for(long lo:x)Fs.pl(lo);
  Fs.flush();
 }
 
 static long[] mul(long a[],long b[]){
    long[] c= new long[a.length];
    for(int i=0;i<a.length;i++){
        c[i]=b[(int)a[i]];
    }
    return c;
  }
  static long[] pow(long[] a,long n){
      long[] c =(long[]) a.clone();
      long[] t = e(a.length);
      while(n>0){
          if(n%2==1){
              t=mul(t,c);
          }
          c=mul(c,c);
          n=n/2;
      }
      return t;
  }
  static long[] e(int n){
      long[] c = new long[n];
      for(int i=0;i<n;i++){
          c[i]=i;
      }
      return c;
  }
}
class Fs {
	//static{Runtime.getRuntime().addShutdownHook(new Thread(()->flush()));}
	private static final byte[] buffer = new byte[1024];
	private static int ptr = 0;
	private static int buflen = 0;
	private static boolean hasNextByte() {
		if (ptr < buflen)  return true;
		else{
			ptr = 0;
			try {
				buflen = System.in.read(buffer);
			} catch (IOException e) {e.printStackTrace();}
			if (buflen <= 0)  return false;
		}
		return true;
	}
	private static int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
	private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
	private static void skipUnprintable() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}
	public static boolean hasNext() { skipUnprintable(); return hasNextByte();}
	public static String next() {
		if (!hasNext()) throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while(isPrintableChar(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	public static int nextInt() {return (int)nextLong();}
	public static long nextLong() {
		if (!hasNext()) throw new NoSuchElementException();
		long n = 0;
		boolean minus = false;
		int b = readByte();
		if (b == '-') {
			minus = true;
			b = readByte();
		}
		if (b < '0' || '9' < b)  throw new NumberFormatException();
		while(true){
			if ('0' <= b && b <= '9') n = n * 10 + b-'0';
			else if(b == -1 || !isPrintableChar(b)) return minus ? -n : n;
			else throw new NumberFormatException();
			b = readByte();
		}
	}
	public static long[] nextLongArray(int i){
		long[] result=new long[i];
		for(int j=0;j<i;j++)  result[j]=nextLong();
		return result;
	}
	public static void nextLongArray(long[]... arrays){
		for(int j=0;j<arrays[0].length;j++)
			for(long[] array:arrays) array[j]=nextLong();
	}
	public static int[] nextIntArray(int i){
		int[] result=new int[i];
		for(int j=0;j<i;j++)  result[j]=nextInt();
		return result;
	}
	public static void nextIntArray(int[]... arrays){
		for(int j=0;j<arrays[0].length;j++)
			for(int[] array:arrays)  array[j]=nextInt();
	}
	static StringBuilder sb=new StringBuilder();
	public static void flush(){
		System.out.print(sb);
		sb=new StringBuilder();
	}
	public static void pr(Object[] o,String str){for(Object ob:o) sb.append(ob).append(str);}
	public static void pl(Object[] o,String str){
		pr(o,str);
		pl();
	}
	public static void pr(Object o){sb.append(o);}
	public static void pl(Object o){sb.append(o).append("\n");}
	public static void pl(){sb.append("\n");}
	public static int[] prefSum(int[] la){
		int[] result=new int[la.length];
		for(int i=0;i<la.length;i++) result[i]=(i==0)?la[i]:result[i-1]+la[i];
		return result;
	}
	public static long[] prefSum(long[] la,long mod){
		long[] result=new long[la.length];
		for(int i=0;i<la.length;i++) result[i]=(i==0)?(la[i]+mod)%mod:(result[i-1]+la[i]+mod)%mod;
		return result;
	}
	public static int lastLowerIndex(long[] array,long lo){return lastLowerOrEqualIndex(array,lo-1);}
	public static int lastLowerOrEqualIndex(long[] array,long lo){
		if(array[array.length-1]<=lo){return array.length-1;}
		if(array[0]>lo){return -1;}
		int tmax=array.length-1, tmin=0;
		int haba=tmax-tmin;
		int tindex=tmin+haba/2;
		while(haba>0){
			if(array[tindex]<=lo){tmin=tindex;}
			else{tmax=tindex-1;}
			haba=tmax-tmin;
			tindex=tmin+haba/2+(haba==1?1:0);
		}
		return tindex;
	}
	public static long gcd(long a,long b){
		if(a>b)a%=b;
		while(a>0){
			b%=a;
			if(b==0)return a;
			a%=b;
		}
		return b;
	}
	public static long modPow(long a,long b,long mod){
		long c=1;
		while(b>0){
			if(b%2==1)  c=(c*a)%mod;
			a=(a*a)%mod;
			b/=2;
		}
		return c;
	}
	public static long inv(long a,long mod){
		long b=mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d=a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		return p < 0 ? p + mod : p;
	}
	static long time=0;
	public static void keisoku(){
		if(time==0) time=System.nanoTime();
		else{
			long t=System.nanoTime();
			pl((t-time)/1000000000.0+"sec");
			time=t;
		}
	}
}