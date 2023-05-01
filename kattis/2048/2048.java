import java.util.*;

class Kattis2048 {
    public static int[][] makeMatrix() {
        int[][] res = new int[4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                res[i][j] = new Scanner(System.in).nextInt();
            }
        }

        return res;
    }

    public static int[][] mergeLeft(int[][] mat) {
        int[][] res = new int[4][4];
        for (int i = 0; i < 4; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < 4; j++) {
                if (mat[i][j] != 0) {
                    row.add(mat[i][j]);
                }
            }
            List<Integer> newRow = new ArrayList<>();
            while (row.size() > 0) {
                int currentTile = row.get(0);
                int nextTile = 0;
                if (row.size() >= 2) {
                    nextTile = row.get(1);
                }

                if (nextTile != 0) {
                    if (nextTile == currentTile) {
                        newRow.add(2 * currentTile);
                        row.remove(1);
                    } else {
                        newRow.add(currentTile);
                    }
                    row.remove(0);
                } else {
                    newRow.add(currentTile);
                    break;
                }
            }
            for (int q = 0; q < newRow.size(); q++) {
                res[i][q] = newRow.get(q);
            }
        }
        return res;
    }

    public static int[][] transpose(int[][] mat) {
        int[][] res = new int[4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                res[i][j] = mat[j][i];
            }
        }
        return res;
    }

    public static int[][] reverse(int[][] mat) {
        int[][] res = new int[4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                res[i][j] = mat[i][3-j];
            }
        }
        return res;
    }

    public static int[][] mergeRight(int[][] mat) {
        int[][] mat2 = reverse(mat);
        return reverse(mergeLeft(mat2));
    }

    public static int[][] mergeUp(int[][] mat) {
        int[][] mat2 = transpose(mat);
        return transpose(mergeLeft(mat2));
    }

    public static int[][] mergeDown(int[][] mat) {
        int[][] mat2 = reverse(transpose(mat));
        return transpose(reverse(mergeLeft(mat2)));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] mat = new int[4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                mat[i][j] = sc.nextInt();
            }
        }
        int dir = sc.nextInt();
        int[][] res = new int[4][4];
        if (dir == 0) {
            res = mergeLeft(mat);
        } else if (dir == 1) {
            res = mergeUp(mat);
        } else if (dir == 2) {
            res = mergeRight(mat);
        } else if (dir == 3) {
            res = mergeDown(mat);
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                System.out.print(res[i][j]);
                if (j != 3) {
                    System.out.print(" ");
                }
            }
            if (i != 3) {
                System.out.println("");
            }
        }
    }
}
