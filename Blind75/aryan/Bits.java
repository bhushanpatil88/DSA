public class Bits {
    
    // 1318
    public int minFlips(int a, int b, int c) {
        int cnt = 0;
        for(int i = 0;i<32;i++){
            int bit_c = ((c>>i)&1);
            int bit_a = ((a>>i)&1);
            int bit_b = ((b>>i)&1);

            if(bit_c==1){
                if(bit_a==0 && bit_b==0)cnt += 1;
            }
            else{
                if(bit_a==1 && bit_b==1)cnt += 2;
                else if(bit_a==1 || bit_b==1)cnt+=1;
            }
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

    // 136
    public int singleNumber(int[] nums) {
        int x = 0;
        for(int c:nums) x^= c;

        return x;
    }
}
