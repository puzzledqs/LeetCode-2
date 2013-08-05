public class Solution {
    public int maxArea(int[] height) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int left = 0;
        int right = height.length - 1;
        int ans = 0;
        while (left < right)    {
            if ( (right - left) * (Math.min(height[left], height[right])) > ans)
                ans = (right - left) * (Math.min(height[left], height[right]));
            if (height[left] < height[right])
                left++;
            else if (height[left] > height[right])
                right--;
            else    {
                left++;
            }
        }
        
        return ans;
    }
}