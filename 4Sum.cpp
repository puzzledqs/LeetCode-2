public class Solution {
    public ArrayList<ArrayList<Integer>> fourSum(int[] num, int target) {
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
                
                int k = j + 1;
                int l = num.length - 1;
                while (k < l)   {
                    if (k > j + 1 && num[k] == num[k - 1])
                        k++;
                    else if (l < num.length - 1 && num[l] == num[l + 1])
                        l--;
                    else    {
                        int sum = num[i] + num[j] + num[k] + num[l];
                        if (sum > target)   {
                            l--;
                        }
                        else if (sum < target)  {
                            k++;
                        }
                        else    {
                            ArrayList<Integer> tmp = new ArrayList<Integer>(4);
                            tmp.add(num[i]);
                            tmp.add(num[j]);
                            tmp.add(num[k]);
                            tmp.add(num[l]);
                            ans.add(tmp);
                            k++;
                            l--;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
}