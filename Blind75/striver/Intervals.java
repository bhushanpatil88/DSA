package striver;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

public class Intervals {
    // 57
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int n = intervals.length;
        List<int []> res = new ArrayList<>();

        int i = 0;
        while(i<n && intervals[i][1] < newInterval[0]){
            res.add(intervals[i]);
            i++;
        }

        while(i<n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
            newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
            i++;
        }

        res.add(newInterval);

        while(i<n)res.add(intervals[i++]);

        return res.toArray(new int[res.size()][]);
    }

    //  56
    public int[][] merge(int[][] intervals) {
        
        int [] arr;
        List<int []> lt = new ArrayList<>();
        arr = intervals[0];
        for(int i = 1;i<intervals.length;i++){
            if(intervals[i][0] <= arr[1] ){
                arr[0] = Math.min(arr[0], intervals[i][0]);
                arr[1] = Math.max(arr[1], intervals[i][1]);
            }
            else{
                lt.add(arr);
                arr = intervals[i];
            }
        }
        lt.add(arr);

        return lt.toArray(new int[lt.size()][]);
    }

    // 435
    public int eraseOverlapIntervals(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[1]));
        
        int cnt = 1;
        int last = intervals[0][1];
        for(int i = 1;i<n;i++){
            if(intervals[i][0] >= last){
                cnt++;
                last = intervals[i][1];
            }
        }
        return n-cnt;
    }

    // repeating and missing elements
    public static int[] findMissingRepeatingNumbers(int[] a) {
        int n = a.length; 
        int xr = 0;

        for (int i = 0; i < n; i++) {
            xr = xr ^ a[i];
            xr = xr ^ (i + 1);
        }

        int number = (xr & ~(xr - 1));

        int zero = 0;
        int one = 0;
        for (int i = 0; i < n; i++) {
            if ((a[i] & number) != 0) {
                one = one ^ a[i];
            }
            else {
                zero = zero ^ a[i];
            }
        }

        for (int i = 1; i <= n; i++) {
            if ((i & number) != 0) {
                one = one ^ i;
            }
            else {
                zero = zero ^ i;
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == zero) cnt++;
        }

        if (cnt == 2) return new int[] {zero, one};
        return new int[] {one, zero};
    }
    
    // 2402
    public int mostBooked(int n, int[][] meetings) {
        PriorityQueue<Integer> freeRooms = new PriorityQueue<>();
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>(
            (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]
        );
        int[] booked = new int[n];

        for (int i = 0; i < n; i++) freeRooms.add(i);
        Arrays.sort(meetings, Comparator.comparingInt(a -> a[0]));

        for(int i = 0;i<meetings.length;i++){
            int start = meetings[i][0];
            int end = meetings[i][1];

            while(!pq.isEmpty() && pq.peek()[0]<=start){
                freeRooms.add(pq.poll()[1]);
            }

            if(!freeRooms.isEmpty()){
                int id = freeRooms.poll();
                pq.add(new int[]{end,id});
                booked[id]++;
            }
            else{
                int[] p = pq.poll();
                booked[p[1]]++;
                pq.add(new int[]{p[0] + end - start, p[1]});
            }
        }
        int maxRooms = 0, maxIndex = -1;
        for (int i = 0; i < n; i++) {
            if (booked[i] > maxRooms) {
                maxRooms = booked[i];
                maxIndex = i;
            }
        }

        return maxIndex;
    }
}
