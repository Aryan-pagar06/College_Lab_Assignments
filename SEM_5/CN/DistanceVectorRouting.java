import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int INF = 999;
        int n;

        System.out.print("Enter number of nodes: ");
        n = scanner.nextInt();

        int[][] cost = new int[20][20];
        int[][] dist = new int[20][20];
        int[][] nextHop = new int[20][20];

        // Input cost matrix[cite: 1]
        System.out.println("\nEnter the cost matrix:");
        System.out.println("Enter 999 for infinity (no direct connection).\n");

        for (int i = 0; i < n; i++) {
            System.out.print("Row " + (i + 1) + ": ");
            for (int j = 0; j < n; j++) {
                cost[i][j] = scanner.nextInt();
                
                // Initial distance is the same as cost[cite: 1]
                dist[i][j] = cost[i][j];

                // Set next hop[cite: 1]
                if (i == j) {
                    nextHop[i][j] = -1;
                } else if (cost[i][j] != INF) {
                    nextHop[i][j] = j;
                } else {
                    nextHop[i][j] = -1;
                }
            }
        }

        // Display initial routing tables[cite: 2]
        System.out.println("\n========== INITIAL ROUTING TABLES ==========");

        for (int i = 0; i < n; i++) {
            System.out.println("\nRouter " + (i + 1));
            System.out.println("Destination\tCost\tNext Hop");

            for (int j = 0; j < n; j++) {
                System.out.print((j + 1) + "\t\t");

                if (dist[i][j] == INF) {
                    System.out.print("INF\t");
                } else {
                    System.out.print(dist[i][j] + "\t");
                }

                if (nextHop[i][j] == -1) {
                    System.out.println("-");
                } else {
                    System.out.println((nextHop[i][j] + 1));
                }
            }
        }

        // Distance Vector Algorithm[cite: 2]
        boolean changed;

        do {
            changed = false;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        // Check if i can reach k and k can reach j[cite: 2]
                        if (cost[i][k] != INF && dist[k][j] != INF) {
                            int newCost = cost[i][k] + dist[k][j];
                            if (newCost < dist[i][j]) {
                                dist[i][j] = newCost;
                                nextHop[i][j] = nextHop[i][k];
                                changed = true;
                            }
                        }
                    }
                }
            }
        } while (changed);

        // Display final routing tables[cite: 3]
        System.out.println("\n========== FINAL ROUTING TABLES ==========");

        for (int i = 0; i < n; i++) {
            System.out.println("\nRouter " + (i + 1));
            System.out.println("Destination\tCost\tNext Hop");

            for (int j = 0; j < n; j++) {
                System.out.print((j + 1) + "\t\t");

                if (dist[i][j] == INF) {
                    System.out.print("INF\t");
                } else {
                    System.out.print(dist[i][j] + "\t");
                }

                if (nextHop[i][j] == -1) {
                    System.out.println("-");
                } else {
                    System.out.println((nextHop[i][j] + 1));
                }
            }
        }

        // Find shortest path[cite: 3]
        int source, destination;

        System.out.print("\nEnter source node: ");
        source = scanner.nextInt();

        System.out.print("Enter destination node: ");
        destination = scanner.nextInt();

        source--;
        destination--;

        if (dist[source][destination] == INF) {
            System.out.println("\nNo path exists between the selected nodes.");
        } else {
            System.out.println("\n========== SHORTEST PATH ==========");
            System.out.print("Path: ");
            int current = source;
            System.out.print(current + 1);

            while (current != destination) {
                current = nextHop[current][destination];
                System.out.print(" -> " + (current + 1));
            }

            System.out.println("\nMinimum Cost: " + dist[source][destination]);
        }

        scanner.close();
    }
}