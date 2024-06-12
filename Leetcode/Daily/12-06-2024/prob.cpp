class Solution {
public:
    void sortColors(vector<int>& v) {
        int n = v.size();
        int l = 0,mid = 0,h = n-1;

        while(mid<=h){
            if(v[mid]==0){
                swap(v[l],v[mid]);
                l++;
                mid++;
            }
            else if(v[mid]==1)mid++;
            else{
                swap(v[mid],v[h]);
                h--;
            }
        }
    }
};