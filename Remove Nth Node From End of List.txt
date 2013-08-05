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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ListNode left = head;
        ListNode right = head;
        for (int i = 0; i < n - 1; i++) {
            right = right.next;
            if (right == null)
                return null;
        }
        
        ListNode leftprev = null;
        while (right.next != null)   {
            leftprev = left;
            left = left.next;
            right = right.next;
        }
        
        if (left == head)    {
            head = head.next;
        }
        else if (left.next == null)  {
            leftprev.next = null;
        }
        else    {
            left.val = left.next.val;
            left.next = left.next.next;
        }
        return head;
    }
}