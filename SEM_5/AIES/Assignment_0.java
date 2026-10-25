
import java.util.Scanner;

public class WaterJugProblem {

    static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static int solve(int fromCap, int toCap, int target) {
        int from = 0;
        int to = 0;
        int steps = 0;

        while (from != target && to != target) {
            if (from == 0) {
                from = fromCap;
                System.out.println("Fill -> (" + from + ", " + to + ")");
            } else if (to == toCap) {
                to = 0;
                System.out.println("Empty -> (" + from + ", " + to + ")");
            } else {
                int pourAmt = Math.min(from, toCap - to);
                from -= pourAmt;
                to += pourAmt;

                System.out.println("Pour -> (" + from + ", " + to + ")");
            }

            steps++;
        }

        System.out.println("Target reached");
        return steps;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Jug1 Capacity : ");
        int jug1Cap = sc.nextInt();

        System.out.print("Enter Jug2 Capacity : ");
        int jug2Cap = sc.nextInt();

        System.out.print("Enter Target : ");
        int target = sc.nextInt();

        if (target < 0 ||
            target > Math.max(jug1Cap, jug2Cap) ||
            target % gcd(jug1Cap, jug2Cap) != 0) {

            System.out.println("No solution possible");
            sc.close();
            return;
        }

        System.out.println("\nMethod 1 (Jug1 -> Jug2)");
        int step1 = solve(jug1Cap, jug2Cap, target);

        System.out.println();

        System.out.println("Method 2 (Jug2 -> Jug1)");
        int step2 = solve(jug2Cap, jug1Cap, target);

        System.out.println();

        if (step1 < step2) {
            System.out.println(
                "Method 1 is better with " + step1 + " steps."
            );
        } else if (step2 < step1) {
            System.out.println(
                "Method 2 is better with " + step2 + " steps."
            );
        } else {
            System.out.println(
                "Both methods take same number of steps."
            );
        }

        sc.close();
    }
}



import java.util.*;

public class MissionariesCannibals {

    static class State {
        int m, c;
        boolean left;
        State parent;

        State(int m, int c, boolean left, State parent) {
            this.m = m;
            this.c = c;
            this.left = left;
            this.parent = parent;
        }
    }

    static int[][] moves = {
        {1, 0},
        {2, 0},
        {0, 1},
        {0, 2},
        {1, 1}
    };

    static boolean isValid(int m, int c) {
        if (m < 0 || c < 0 || m > 3 || c > 3) {
            return false;
        }

        int rm = 3 - m;
        int rc = 3 - c;

        if (m > 0 && c > m) {
            return false;
        }

        if (rm > 0 && rc > rm) {
            return false;
        }

        return true;
    }

    public static void main(String[] args) {

        Queue<State> q = new LinkedList<>();
        Set<String> visited = new HashSet<>();

        State start = new State(3, 3, true, null);

        q.add(start);
        visited.add("3,3,true");

        while (!q.isEmpty()) {

            State cur = q.poll();

            if (cur.m == 0 && cur.c == 0 && !cur.left) {

                Stack<State> st = new Stack<>();

                while (cur != null) {
                    st.push(cur);
                    cur = cur.parent;
                }

                while (!st.isEmpty()) {
                    State s = st.pop();

                    System.out.println(
                        "(" + s.m + "," + s.c + "," +
                        (s.left ? "Left" : "Right") + ")"
                    );
                }

                return;
            }

            for (int i = 0; i < 5; i++) {

                int nm, nc;

                if (cur.left) {
                    nm = cur.m - moves[i][0];
                    nc = cur.c - moves[i][1];
                } else {
                    nm = cur.m + moves[i][0];
                    nc = cur.c + moves[i][1];
                }

                boolean side = !cur.left;

                if (isValid(nm, nc)) {

                    String key = nm + "," + nc + "," + side;

                    if (!visited.contains(key)) {
                        visited.add(key);

                        q.add(
                            new State(nm, nc, side, cur)
                        );
                    }
                }
            }
        }

        System.out.println("No Solution");
    }
}



import java.util.Scanner;

public class TowerOfHanoi {

    static int total_moves = 0;

    static void towerOfHanoi(
        int n, String src, String helper, String dest
    ) {
        if (n == 1) {
            System.out.println(
                "transfer disk " + n + " from " +
                src + " to " + dest
            );

            total_moves++;
            return;
        }

        towerOfHanoi(n - 1, src, dest, helper);

        System.out.println(
            "transfer disk " + n + " from " +
            src + " to " + dest
        );

        total_moves++;

        towerOfHanoi(n - 1, helper, src, dest);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of disks: ");
        int n = sc.nextInt();

        if (n <= 0) {
            System.out.println("Enter a positive number of disks.");
            sc.close();
            return;
        }

        towerOfHanoi(n, "S", "H", "D");

        System.out.println("Total moves = " + total_moves);

        sc.close();
    }
}
