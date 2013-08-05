public class Solution {
    public ArrayList<ArrayList<Integer>> threeSum(int[] num) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
        Arrays.sort(num);
        for (int i = 0; i < num.length; i++)    {
            if (i > 0 && num[i] == num[i - 1])
                continue;
            for (int j = i + 1; j < num.length; j++)    {
                if (j > i + 1 && num[j] == num[j - 1])
                    continue;
                boolean k = biFind(0 - num[i] - num[j], num, j + 1, num.length - 1);
                ArrayList<Integer> a = new ArrayList<Integer>();
                a.add(num[i]); a.add(num[j]); a.add(-num[i]-num[j]);
                if (k)
                    ans.add(a);
            }
        }
        return ans;
    }
    
    public boolean biFind(int t, int[] num, int s, int e) {
        if (s > e || t < num[s] || t > num[e])
            return false;
        int m = (s + e) / 2;
        if (num[m] == t)    {
            return true;
        }
        else if (t < num[m])    {
            return biFind(t, num, s, m - 1);
        }
        else 
            return biFind(t, num, m + 1, e);
    }
}