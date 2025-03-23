import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class hashMap {
    //2215
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet<>();
        for(int n : nums1){
           set1.add(n);
        }
        Set<Integer> set2 = new HashSet<>();
        for(int n : nums2){
           set2.add(n);
        }
        List<Integer> ls1 = new ArrayList<>();
         for(int n : set1){
            if(!set2.contains(n)){
                ls1.add(n);
            }
         }
         List<Integer> ls2 = new ArrayList<>();
         for(int n : set2){
            if(!set1.contains(n)){
                ls2.add(n);
            }
         }
        List<List<Integer>> ls = new ArrayList<>();
        ls.add(ls1);
        ls.add(ls2);

        return ls;
    }

    //1207
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer,Integer> map=new HashMap<>();
        Set<Integer> set=new HashSet<>();
        for(int i=0;i<arr.length;i++){
            map.put(arr[i],map.getOrDefault(arr[i],0)+1);
        }
        for(int num:map.values()){
            set.add(num);
        }
        return map.size() == set.size();
    }

    //1657
    public boolean closeStrings(String word1, String word2) {
        int[] freq1 = new int[26];
        int[] freq2 = new int[26];

        for (char ch : word1.toCharArray()) {
            freq1[ch - 'a']++;
        }

        for (char ch : word2.toCharArray()) {
            freq2[ch - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if ((freq1[i] == 0 && freq2[i] != 0) || (freq1[i] != 0 && freq2[i] == 0)) {
                return false;
            }
        }

        Arrays.sort(freq1);
        Arrays.sort(freq2);

        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }

        return true;
    }

    //2352
    public int equalPairs(int[][] grid) {
        int n = grid.length;
        HashMap<String, Integer> freqMap = new HashMap<>();
        char[] chars = new char[n];

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                chars[col] = (char) (grid[row][col] + '0');
            }
            String s = new String(chars);
            freqMap.put(s, freqMap.getOrDefault(s, 0) + 1);
        }

        int count = 0;
        for (int col = 0; col < n; col++) {
            for (int row = 0; row < n; row++) {
                chars[row] = (char) (grid[row][col] + '0');
            }

            String s = new String(chars);
            if (freqMap.containsKey(s))
                count += freqMap.get(s);
        }

        return count;
    }
}
