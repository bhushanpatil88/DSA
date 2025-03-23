import java.util.Arrays;
import java.util.Comparator;

public class Intervals {
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

    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points,Comparator.comparingInt(a -> a[0]));
        int end = points[0][1];
        int arrow = 1;
        for(int i=1;i<points.length;i++){
            if(points[i][0] > end){
                arrow++;
                end = points[i][1];
            }
            else end = Math.min(end, points[i][1]);
        }

        return arrow;
    }
}
