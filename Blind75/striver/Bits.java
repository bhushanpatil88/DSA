package striver;


import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.System.out;
import java.util.*;
import java.io.*;
import java.math.*;



public class Bits
{
    static FastReader in = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);




    // 371
    /*

    Set union A | B
    Set intersection A & B
    Set subtraction A & ~B
    Set negation ALL_BITS ^ A or ~A
    Set bit A |= 1 << bit
    Clear bit A &= ~(1 << bit)
    Test bit (A & 1 << bit) != 0
    Extract last bit A&-A or A&~(A-1) or x^(x&(x-1))
    Remove last bit A&(A-1)
    Get all 1-bits ~0

    A^B does the similar work as addition but it doesn't take care of carry
    A&B checks if we have any carry which will be used for the next bit, so we do a left shift

    a = 2 b = 3

        0010
     ^  0011
        -----
        0001  -> no carry considered

        0010
      & 0011
        ----
        0010 -> carry considered
        0100 -> shifted to left

        0001
      ^ 0100
       ------
        0101   -> 5

        */
    public int getSum(int a, int b) {
        while(b!=0){
            int t = (a&b)<<1;
            a = a^b;
            b = t;
        }
        return a;
    }
    
    public static void solve() throws Exception{
    }
    
    public static void main(String hi[]) throws Exception
    {
        try {
            
            int T=in.nextInt();
            while(T-- > 0){
                solve();
            }
            out.close();
        } catch (Exception e) {
            return;
        }
        
    }

    // 191
    public int hammingWeight(int n) {
        int cnt = 0;
        while(n>0){
            n = n&(n-1);
            cnt++;
        }
        return cnt;
    }

    // 338
    public int[] countBits(int n) {
        int [] cnt = new int[n+1];
        cnt[0] = 0;
        if(n==0)return cnt;
        cnt[1] = 1;
        if(n==1)return cnt;
        cnt[2] = 1;
        int pow = 2;
        for(int i = 3;i<=n;i++){
            if((i&(i-1))==0){
                pow = i;
                cnt[i] = 1;
            }   
            else{
                cnt[i] = 1 + cnt[i-pow];
            }
        }

        return cnt;
    }

    // 268
    public int missingNumber(int[] nums) {
        int x = 0;
        for(int i = 0;i<nums.length;i++){
            x ^= (i+1);
            x ^= nums[i];
        }
        return x;
    }

    // 190
    public int reverseBits(int num) {
        
        num = ((num & 0xffff0000) >>> 16) | ((num & 0x0000ffff) << 16);
        num = ((num & 0xff00ff00) >>> 8) | ((num & 0x00ff00ff) << 8);
        num = ((num & 0xf0f0f0f0) >>> 4) | ((num & 0x0f0f0f0f) << 4);
        num = ((num & 0xcccccccc) >>> 2) | ((num & 0x33333333) << 2);
        num = ((num & 0xaaaaaaaa) >>> 1) | ((num & 0x55555555) << 1);
        
        return num;
        
    }
    static class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br=new BufferedReader(new InputStreamReader(System.in));
        }
        String next(){
            while(st==null || !st.hasMoreTokens()){
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt(){
            return Integer.parseInt(next());
        }
        long nextLong(){
            return Long.parseLong(next());
        }
        double nextDouble(){
            return Double.parseDouble(next());
        }
        String nextLine(){
            String str="";
            try {
                str=br.readLine().trim();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return str;
        }

        int[] readArr(int N){
            int [] arr = new int[N];
            for(int i = 0;i<N;i++)
                arr[i] = in.nextInt();
            return arr;
        }
    }

    public static void print(int[] arr)
    {
        for(int x: arr)
            out.print(x+" ");
        out.println();
    }
    public static boolean isPrime(long n)
    {
        if(n < 2) return false;
        if(n == 2 || n == 3) return true;
        if(n%2 == 0 || n%3 == 0) return false;
        long sqrtN = (long)Math.sqrt(n)+1;
        for(long i = 6L; i <= sqrtN; i += 6) {
            if(n%(i-1) == 0 || n%(i+1) == 0) return false;
        }
        return true;
    }
    public static long gcd(long a, long b)
    {
        if(a > b)
            a = (a+b)-(b=a);
        if(a == 0L)
            return b;
        return gcd(b%a, a);
    }
    public static long totient(long n)
    {
        long result = n;
        for (int p = 2; p*p <= n; ++p)
            if (n % p == 0)
            {
                while(n%p == 0)
                    n /= p;
                result -= result/p;
            }
        if (n > 1)
            result -= result/n;
        return result;
    }
    public static ArrayList<Integer> findDiv(int N)
    {
        ArrayList<Integer> ls1 = new ArrayList<Integer>();
        ArrayList<Integer> ls2 = new ArrayList<Integer>();
        for(int i=1; i <= (int)(Math.sqrt(N)+0.00000001); i++)
            if(N%i == 0)
            {
                ls1.add(i);
                ls2.add(N/i);
            }
        Collections.reverse(ls2);
        for(int b: ls2)
            if(b != ls1.get(ls1.size()-1))
                ls1.add(b);
        return ls1;
    }
    public static void sort(int[] arr)
    {
        ArrayList<Integer> ls = new ArrayList<Integer>();
        for(int x: arr)
            ls.add(x);
        Collections.sort(ls);
        for(int i=0; i < arr.length; i++)
            arr[i] = ls.get(i);
    }
    public static long power(long x, long y, long p)
    {
        long res = 1L;
        x = x%p;
        while(y > 0)
        {
            if((y&1)==1)
                res = (res*x)%p;
            y >>= 1;
            x = (x*x)%p;
        }
        return res;
    }
       
}


