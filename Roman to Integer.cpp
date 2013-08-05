public class Solution {
    public int romanToInt(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int ans = 0;
        int[] value = new int[27];
        value['M' - 'A'] = 1000;
        value['D' - 'A'] = 500;
        value['C' - 'A'] = 100;
        value['L' - 'A'] = 50;
        value['X' - 'A'] = 10;
        value['V' - 'A'] = 5;
        value['I' - 'A'] = 1;
        for (int i = 0; i < s.length() - 1; i++)  {
            if (value[s.charAt(i) - 'A'] < value[s.charAt(i + 1) - 'A'])
                ans -= value[s.charAt(i) - 'A'];
            else 
                ans += value[s.charAt(i) - 'A'];
        }
        ans += value[s.charAt(s.length() - 1) - 'A'];
        return ans;
    }
}