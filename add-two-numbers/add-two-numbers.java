import java.math.*;

public class Solution {

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
}
