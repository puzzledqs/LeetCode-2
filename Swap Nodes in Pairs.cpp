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
    public ListNode swapPairs(ListNode head) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        if (head == null)
            return head;
            
        ListNode n1 = head, n2 = head.next, n1prev = null, tmp = null;
        while (true)   {
            if (n2 == null)
                break;
            n1.next = n2.next;
            n2.next = n1;
            if (n1 == head) {
                head = n2;                
            }
            else    {
                n1prev.next = n2;
            }
            
            n1prev = n1;
            n1 = n1.next;
            if (n1 == null)
                break;
            n2 = n1.next;
        }
        
        return head;
    }
}