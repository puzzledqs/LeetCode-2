/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool myfunction(Interval i,Interval j) {
    return i.start < j.start;
}

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        intervals.push_back(newInterval);
        return merge(intervals);
    }
    
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (intervals.size() == 0)
            return vector<Interval>();
        
        sort(intervals.begin(), intervals.end(), myfunction);
        
        vector<Interval> ans;
        Interval now;
        now = intervals[0];
        for (int i = 1; i < intervals.size(); i++)  {
            if (intervals[i].start > now.end)   {
                ans.push_back(now);
                now = intervals[i];
            }
            else    {
                now.end = max(now.end, intervals[i].end);
            }
        }
        
        ans.push_back(now);
        return ans;
    }
};


