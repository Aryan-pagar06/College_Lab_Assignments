
import java.util.Scanner;

public class TSP {

    static int getDistance(int[] tour, int[][] dist) {
        int n = tour.length;
        int total = 0;

        for (int i = 0; i < n - 1; i++) {
            total += dist[tour[i]][tour[i + 1]];
        }

        total += dist[tour[n - 1]][tour[0]];

        return total;
    }

    static void solveTSP(int n, int[][] dist) {
        int[] curr = new int[n];

        for (int i = 0; i < n; i++) {
            curr[i] = i;
        }

        int currDist = getDistance(curr, dist);

        while (true) {
            int[] bestTour = curr.clone();
            int minDist = currDist;

            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {

                    int[] nextTour = curr.clone();

                    int temp = nextTour[i];
                    nextTour[i] = nextTour[j];
                    nextTour[j] = temp;

                    int nextDist = getDistance(nextTour, dist);

                    if (nextDist < minDist) {
                        minDist = nextDist;
                        bestTour = nextTour;
                    }
                }
            }

            if (minDist >= currDist) {
                break;
            }

            curr = bestTour;
            currDist = minDist;
        }

        System.out.print("Shortest Route: ");

        for (int i = 0; i < n; i++) {
            System.out.print(curr[i] + " -> ");
        }

        System.out.println(curr[0]);

        System.out.println("Minimum Distance: " + currDist);
    }

    static void runHardcoded() {
        int n = 4;

        int[][] dist = {
            {0, 400, 500, 300},
            {400, 0, 300, 400},
            {500, 300, 0, 400},
            {300, 500, 400, 0}
        };

        solveTSP(n, dist);
    }

    static void runDynamic(Scanner sc) {
        System.out.print("Enter number of cities: ");
        int n = sc.nextInt();

        if (n <= 0) {
            System.out.println("Invalid number of cities!");
            return;
        }

        int[][] dist = new int[n][n];

        System.out.println("Enter distance matrix:");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = sc.nextInt();
            }
        }

        solveTSP(n, dist);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Select an option:");
        System.out.println("1. Run with hardcoded values");
        System.out.println("2. Enter values dynamically");

        System.out.print("Choice: ");
        int choice = sc.nextInt();

        if (choice == 1) {
            runHardcoded();
        } else if (choice == 2) {
            runDynamic(sc);
        } else {
            System.out.println("Invalid choice!");
        }

        sc.close();
    }
}
