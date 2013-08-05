public class Solution {
    public boolean isPalindrome(int x) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if (x < 0)
            return false;
        int high = 1;
        while (high * 10 <= x && high < 1000000000)
            high *= 10;
        while (x >= 10) {
            if (x / high != x % 10)
                return false;
            x = (x - x / high * high) / 10;
            high /= 100;
        }
        return true;
    }
}