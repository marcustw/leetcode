import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

class WA2 {
    static boolean isStackFull(int stackSize, int i) {
        return stackSize > (int) Math.pow(3, i);
    }

    static String format(int i) {
        if (i < 10) {
            return "    " + i;
        } else if (i < 100) {
            return "   " + i;
        } else if (i < 1000) {
            return "  " + i;
        } else if (i < 10000) {
            return "  " + i;
        } else {
            return String.valueOf(i);
        }
    }

    static int mpush(List<Stack<Integer>> multiStack) {
        int count = 1;
        multiStack.get(0).push(1);
        for (int j = 0; j < multiStack.size() - 1; j++) {
            Stack<Integer> sj = multiStack.get(j);
            if (isStackFull(sj.size(), j)) {
                Stack<Integer> sjPlus1 = multiStack.get(j+1);
                int tf = (int) Math.pow(3, j);
                for (int k = 0; k < tf; k++) {
                    sjPlus1.push(1);
                    sj.pop();
                    count+= 2;
                }
            }
        }
        int i = multiStack.size() - 1;
        Stack<Integer> s = multiStack.get(i);
        if (isStackFull(s.size(), i)) {
            Stack<Integer> newStack = new Stack<>();
            int tf = (int) Math.pow(3, i);
            for (int k = 0; k < tf; k++) {
                newStack.push(1);
                s.pop();
                count += 2;
            }
            multiStack.add(newStack);
        }
        return count;
    }

    static int mpop(List<Stack<Integer>> multiStack) {
        int count = 1;
        multiStack.get(0).pop();
        for (int j = 0; j < multiStack.size() - 1; j++) {
            Stack<Integer> sj = multiStack.get(j);
            if (sj.size() == 0) {
                Stack<Integer> sjPlus1 = multiStack.get(j+1);
                int tf = (int) Math.pow(3, j);
                for (int k = 0; k < tf; k++) {
                    sjPlus1.pop();
                    sj.push(1);
                    count+= 2;
                }
            }
        }
        int i = multiStack.size() - 1;
        Stack<Integer> s = multiStack.get(i);
        if (s.size() == 0) {
            multiStack.remove(i);
        }
        return count;
    }

    static void printStack(List<Stack<Integer>> multiStack) {
        for (Stack v : multiStack) {
            System.out.print(v.size() + ", ");
        }
        System.out.println();
    }

    static int amorMPUSHCost(List<Stack<Integer>> multiStack) {
        return 2 * (multiStack.size() -1) + 3;
    }

    static int amorMPOPCost(List<Stack<Integer>> multiStack) {
        int size = multiStack.size();
        int n = 0;
        for (Stack s : multiStack) {
            n += s.size();
        }
        boolean isSumOf3 = (2 * (n-1) + 1) == (int) Math.pow(3, size - 1);
        if (isSumOf3) {
            return (4 * sumOf3(size)) ;
        } else {
            return 0;
        }
    }

    static int sumOf3(int i) {
        double n = 0;
        for (int j = 0; j <= i; j++) {
            n += Math.pow(3, j);
        }
        return (int) n;
    }

    static void checkConstraint(int bankAcc) throws Exception {
        if (bankAcc < 0) {
            throw new Exception();
        }
    }

    static int actualMPOPCost(List<Stack<Integer>> multiStack) {
        List<Stack<Integer>> anotherStack = new ArrayList<>();
        for (Stack<Integer> s : multiStack) {
            Stack<Integer> toAdd = new Stack<>();
            toAdd.addAll(s);
            anotherStack.add(toAdd);
        }
        int count = 1;
        anotherStack.get(0).pop();
        for (int j = 0; j < anotherStack.size() - 1; j++) {
            Stack<Integer> sj = anotherStack.get(j);
            if (sj.size() == 0) {
                Stack<Integer> sjPlus1 = anotherStack.get(j+1);
                int tf = (int) Math.pow(3, j);
                for (int k = 0; k < tf; k++) {
                    sjPlus1.pop();
                    sj.push(1);
                    count+= 2;
                }
            }
        }
        int i = anotherStack.size() - 1;
        Stack<Integer> s = anotherStack.get(i);
        if (s.size() == 0) {
            anotherStack.remove(i);
        }
        return count;
    }

    public static void main(String[] args) throws Exception {
        List<Stack<Integer>> multiStack = new ArrayList<>();
        multiStack.add(new Stack<>());
        int bankAcc = 0;
        int total = 0;
        int max = 0;
        System.out.println(Math.log(2*4 + 1) / Math.log(3));
        for (int n = 0; n < 1000; n++) {
            int i = multiStack.size() - 1;
            int actualMPOPCost = n == 0 ? -0 : actualMPOPCost(multiStack);
            int amortizedCost = n == 0 ? 1 : (2*(i) + 3);
            int actualMPUSHCost = mpush(multiStack);
            max++;
            bankAcc += (amortizedCost - actualMPUSHCost);
            total += actualMPUSHCost;
//            System.out.printf("n = %s | actual cost = %s | amortized cost = %s | account status = %s | total cost = %s    |     ",
//                    format(n), format(actualMPUSHCost), format(amortizedCost), format(bankAcc), format(total));
            System.out.printf("n = %s | MPUSH cost = %s | MPOP cost = %s | AMORTISED COST = %s |",
                    format(n), format(actualMPUSHCost), format(actualMPOPCost), format(amortizedCost));
            System.out.printf(" bank acc = %s       |      ", format(bankAcc));
            printStack(multiStack);
            checkConstraint(bankAcc);
        }
    }
}