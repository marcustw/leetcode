import java.util.ArrayList;
import java.util.Scanner;

class CardTrading {
    private static long cardTrading(int N, int T, int K, int[] cards, int[][] prices) {
        long amount = 0;
        ArrayList<int[]> arr = new ArrayList<>();
        for (int i=1; i<=T; i++) {
            int buyPrice = prices[i][0];
            int sellPrice = prices[i][1];
            arr.add(new int[] {Math.max(2-cards[i], 0) * buyPrice, cards[i] * sellPrice});
        }
        arr.sort((x,y) -> (x[0]+x[1])-(y[0]+y[1]));

        for (int i=0; i<K; i++) {
            amount -= arr.get(i)[0];
        }
        for (int i=K; i<arr.size(); i++) {
            amount += arr.get(i)[1];
        }

        return amount;
    }

    public static void main(String[] args) {
        // handling input
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), T = sc.nextInt(), K = sc.nextInt(); // number of cards Anthony has
        int[] cards = new int[T+1];
        for (int i=0; i<N; i++) {
            int card = sc.nextInt();
            cards[card]++;
        }
        int[][] prices = new int[T+1][2];
        for (int i=1; i<=T; i++) {
            prices[i][0] = sc.nextInt();
            prices[i][1] = sc.nextInt();
        }

        long amount = cardTrading(N, T, K, cards, prices);

        System.out.print(amount);
    }

}