import java.util.*;

public class Main {
    public static void main(String[] args) {

        //missionary and cannibals

        Queue<int[]> q = new LinkedList<>();
        Set<String> visited = new HashSet<>();

        q.add(new int[]{3, 3, 1});

        while (!q.isEmpty()) {
            int[] state = q.poll();

            int m = state[0];
            int c = state[1];
            int b = state[2];

            System.out.println(m + " " + c + " " + b);

            if (m == 0 && c == 0 && b == 0) {
                System.out.println("Goal reached");
                break;
            }

            String key = m + "," + c + "," + b;

            if (visited.contains(key)) {
                continue;
            }

            visited.add(key);

            int[][] moves = {
                {1, 0},
                {2, 0},
                {0, 1},
                {0, 2},
                {1, 1}
            };

            for (int[] move : moves) {
                int x = move[0];
                int y = move[1];

                int nm = b == 1 ? m - x : m + x;
                int nc = b == 1 ? c - y : c + y;

                if (nm >= 0 && nm <= 3 && nc >= 0 && nc <= 3) {

                    if ((nm == 0 || nm >= nc) &&
                        (nm == 3 || (3 - nm) >= (3 - nc))) {

                        q.add(new int[]{nm, nc, 1 - b});
                    }
                }
            }
        }
    }
}


public class Main {

    static void hanoi(int n, char source, char aux, char dest) {

        //hanoi

        if (n == 1) {
            System.out.println(source + " -> " + dest);
            return;
        }

        hanoi(n - 1, source, dest, aux);

        System.out.println(source + " -> " + dest);

        hanoi(n - 1, aux, source, dest);
    }

    public static void main(String[] args) {
        hanoi(3, 'A', 'B', 'C');
    }
}


import java.util.*;

public class Main {
    public static void main(String[] args) {

        int a = 4, b = 3;  // Jug capacities
        int target = 2;    // Required water

        Queue<int[]> q = new LinkedList<>();
        Set<String> visited = new HashSet<>();

        q.add(new int[]{0, 0});

        while (!q.isEmpty()) {
            int[] state = q.poll();

            int x = state[0];
            int y = state[1];

            String key = x + "," + y;

            if (visited.contains(key)) {
                continue;
            }

            visited.add(key);

            System.out.println(x + " " + y);

            if (x == target || y == target) {
                System.out.println("Goal reached");
                break;
            }

            // Fill jugs
            q.add(new int[]{a, y});
            q.add(new int[]{x, b});

            // Empty jugs
            q.add(new int[]{0, y});
            q.add(new int[]{x, 0});

            // Pour A into B
            int pour = Math.min(x, b - y);
            q.add(new int[]{x - pour, y + pour});

            // Pour B into A
            pour = Math.min(y, a - x);
            q.add(new int[]{x + pour, y - pour});
        }
    }
}