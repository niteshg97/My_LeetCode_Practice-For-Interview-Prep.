class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end()); // whenever there is intervals based Questions .. sort on the basis of first element 
        int n = intervals.size();
        int count=0;
        int i =0;
        int j=1;
        while(j<n){
            vector<int> curr_interval=intervals[i];
            vector<int> next_interval=intervals[j];
            int cs = curr_interval[0];
            int ce = curr_interval[1];

            int ns = next_interval[0];
            int ne = next_interval[1];

            if(ce<=ns){ // no  overlaping condition... toh aage badho ..
            i=j;
            j++;
            }
            else if(ce <= ne ){ // overlaping 
            j++;
            count++;
            }
            else if (ce > ne ) { // overlaping condition...
            i=j;
            j++;
            count++;
            }

        }
        return count;
        
    }
};