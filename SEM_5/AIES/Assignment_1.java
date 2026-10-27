
import java.util.*;

public class EightPuzzle {

    static class Node {
        int[][] state;
        int x, y, g, h, f;
        Node parent;

        Node(int[][] s, int x, int y, int g, Node parent) {
            this.state = s;
            this.x = x;
            this.y = y;
            this.g = g;
            this.parent = parent;

            h = manhattan();
            f = g + h;
        }

        int manhattan() {
            int d = 0;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int val = state[i][j];

                    if (val != 0) {
                        int r = (val - 1) / 3;
                        int c = (val - 1) % 3;

                        d += Math.abs(i - r) + Math.abs(j - c);
                    }
                }
            }

            return d;
        }

        String key() {
            StringBuilder s = new StringBuilder();

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    s.append(state[i][j]);
                }
            }

            return s.toString();
        }
    }

    static void printPath(Node node) {
        if (node == null) {
            return;
        }

        printPath(node.parent);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(node.state[i][j] + " ");
            }
            System.out.println();
        }

        System.out.println();
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int[][] start = new int[3][3];
        int x = 0, y = 0;

        System.out.println("Enter Initial State:");

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                start[i][j] = sc.nextInt();

                if (start[i][j] == 0) {
                    x = i;
                    y = j;
                }
            }
        }

        PriorityQueue<Node> open = new PriorityQueue<>(
            (a, b) -> Integer.compare(a.f, b.f)
        );

        Set<String> closed = new HashSet<>();

        open.add(new Node(start, x, y, 0, null));

        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        while (!open.isEmpty()) {

            Node curr = open.poll();

            if (curr.h == 0) {
                System.out.println("Goal Reached");
                printPath(curr);
                sc.close();
                return;
            }

            closed.add(curr.key());

            for (int k = 0; k < 4; k++) {

                int nx = curr.x + dx[k];
                int ny = curr.y + dy[k];

                if (nx >= 0 && nx < 3 &&
                    ny >= 0 && ny < 3) {

                    int[][] temp = new int[3][3];

                    for (int i = 0; i < 3; i++) {
                        temp[i] = curr.state[i].clone();
                    }

                    int swap = temp[curr.x][curr.y];
                    temp[curr.x][curr.y] = temp[nx][ny];
                    temp[nx][ny] = swap;

                    Node child = new Node(
                        temp, nx, ny, curr.g + 1, curr
                    );

                    if (!closed.contains(child.key())) {
                        open.add(child);
                    }
                }
            }
        }

        System.out.println("No Solution");
        sc.close();
    }
}
