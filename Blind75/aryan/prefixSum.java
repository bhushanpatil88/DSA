public class prefixSum {
    //1732
    public int largestAltitude(int[] nums) {
        int  n = nums.length;
        int [] pref = new int[n+1];
        int maxi = 0;
        for(int i = 1;i<=n;i++){
            pref[i] = pref[i-1] + nums[i-1];
            maxi = Math.max(maxi,pref[i]);
        }
        return maxi;
    }

    // 724
    public int pivotIndex(int[] nums) {
        int n = nums.length;
        int [] pref = new int [n+1];
        for(int i=1;i<=n;i++)pref[i] = pref[i-1]+nums[i-1];

        for(int i=1;i<=n;i++){
            if(pref[i-1]==(pref[n]-pref[i]))return i-1;
        }
        return -1;
    }
}
