/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
import java.math.*;

public class Sum2ListNode {

    private static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            ListNode curr = this;
            while (curr != null) {
                System.out.print(curr.val);
                curr = curr.next;
            }
            return sb.toString();
        }
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        StringBuilder x1 = new StringBuilder();
        while (l1 != null) {
            x1.insert(0, l1.val);
            l1 = l1.next;
        }

        StringBuilder x2 = new StringBuilder();
        while (l2 != null) {
            x2.insert(0, l2.val);
            l2 = l2.next;
        }

        BigInteger first = new BigInteger(x1.toString());
        BigInteger second = new BigInteger(x2.toString());
        BigInteger sum = first.add(second);

        String s = sum.toString();
        ListNode result = new ListNode();

        System.out.println(x1.toString());
        System.out.println(x2.toString());
        System.out.println(s);

        ListNode curResult = result;
        for (int i = s.length() - 1; i >= 0; i--) {
            curResult.val = Integer.parseInt(String.valueOf(s.charAt(i)));
            if (i == 0) {
                curResult.next = null;
            } else {
                curResult.next = new ListNode();
            }
            curResult = curResult.next;
        }
        return result;
    }

    public static void main(String[] args) {
        Sum2ListNode s = new Sum2ListNode();
        ListNode l1 = new ListNode();
        l1.val = 2;
        l1.next = new ListNode(4);
        l1.next.next = new ListNode(3);
        ListNode l2 = new ListNode();
        l2.val = 5;
        l2.next = new ListNode(6);
        l2.next.next = new ListNode(4);

        System.out.println(s.addTwoNumbers(l1, l2));
    }
}
