/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        if (head == null || k == 1)
            return head;
        
        ListNode left = head, right, now, prev, rightnext, gprev = null, nn;
        while (true)    {
            right = left;
            for (int i = 0; i < k - 1; i++) {
                right = right.next;
                if (right == null)
                    break;
            }
            if (right == null)
                break;
            
            rightnext = right.next;
            
            prev = left;
            now = left.next;
            for (int i = 0; i < k - 1; i++) {
                nn = now.next;
                now.next = prev;
                prev = now;
                now = nn;
            }
            
            left.next = rightnext;
            if (left == head)   {
                head = right;
            }
            else    {
                gprev.next = right;
            }
            gprev = left;
            
            left = left.next;
            if (left == null)
                break;
        
        }
        
        return head;
    }
}