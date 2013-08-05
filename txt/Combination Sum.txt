public class Solution {
    private ArrayList<ArrayList<Integer>> ans;
    
    public ArrayList<ArrayList<Integer>> combinationSum(int[] candidates, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        Arrays.sort(candidates);
        //reverse(candidates);
        ans = new ArrayList<ArrayList<Integer>>();
        DFS(candidates, new ArrayList<Integer>(), target, 0);
        
        return ans;
    }
    
    public void DFS(int[] a, ArrayList<Integer> now, int target, int start) {
        ArrayList<Integer> tmp = now;
        do  {
            if (target == 0)    {
                ans.add((ArrayList<Integer>)tmp.clone());
                return;
            }
            
            if (start < a.length - 1)   {
                DFS(a, (ArrayList<Integer>)tmp.clone(), target, start + 1);
            }
            tmp.add(a[start]);
            target -= a[start];
        }
        while (target >= 0);
    }
    
    public void reverse(int[] a)    {
        int temp = 0, n = a.length;
        for (int i = 0; i < n / 2; i++) {
            temp = a[i];
            a[i] = a[n - 1 - i];
            a[n - 1 - i] = temp;
        }
    }
}