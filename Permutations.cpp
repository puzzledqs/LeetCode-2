public class Solution {
    public ArrayList<ArrayList<Integer>> permute(int[] num) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
        int[] init = num.clone();
        do  {
            ArrayList<Integer> tmp = new ArrayList<Integer>();
            for (int i: num)    {
                tmp.add(i);
            }
            ans.add(tmp);
            nextPermutation(num);
        }
        while (!Arrays.equals(num, init));
        return ans;
    }
    
    public void nextPermutation(int[] num) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if (num.length == 0)
            return;
        int k = 0, place = -1, swap = -1;
        while (k < num.length - 1)  {
            if (num[k] < num[k + 1])    {
                place = k;
                swap = k + 1;
            }
            else    {
                if (place >= 0 && num[k + 1] > num[place] && num[k + 1] < num[swap])
                    swap = k + 1;
            }
            k++;
        }
        if (place == -1)    {
            for (int i = 0; i < num.length / 2; i++)    {
                int tmp = num[i];
                num[i] = num[num.length - 1 - i];
                num[num.length - 1 - i] = tmp;
            }
        }
        else    {
            int tar = num[place];
            num[place] = num[swap];
            num[swap] = tar;
            Arrays.sort(num, place + 1, num.length);
        }
    }
}