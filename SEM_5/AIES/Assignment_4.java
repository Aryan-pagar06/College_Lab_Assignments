
import java.util.Scanner;

public class TicTacToe {

    static char[] board = {
        '1', '2', '3',
        '4', '5', '6',
        '7', '8', '9'
    };

    static void printBoard() {
        System.out.println();
        System.out.println(" " + board[0] + " | " + board[1] + " | " + board[2]);
        System.out.println("---+---+---");
        System.out.println(" " + board[3] + " | " + board[4] + " | " + board[5]);
        System.out.println("---+---+---");
        System.out.println(" " + board[6] + " | " + board[7] + " | " + board[8]);
        System.out.println();
    }

    static boolean checkWin(char player) {

        int[][] wins = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
            {0, 4, 8}, {2, 4, 6}
        };

        for (int[] w : wins) {
            if (board[w[0]] == player &&
                board[w[1]] == player &&
                board[w[2]] == player) {
                return true;
            }
        }

        return false;
    }

    static boolean isFull() {
        for (char c : board) {
            if (c != 'X' && c != 'O') {
                return false;
            }
        }
        return true;
    }

    static int minimax(boolean isMaximizing) {

        if (checkWin('O')) {
            return 1;
        }

        if (checkWin('X')) {
            return -1;
        }

        if (isFull()) {
            return 0;
        }

        if (isMaximizing) {

            int best = -1000;

            for (int i = 0; i < 9; i++) {
                if (board[i] != 'X' && board[i] != 'O') {

                    char old = board[i];
                    board[i] = 'O';

                    int score = minimax(false);

                    board[i] = old;

                    best = Math.max(best, score);
                }
            }

            return best;

        } else {

            int best = 1000;

            for (int i = 0; i < 9; i++) {
                if (board[i] != 'X' && board[i] != 'O') {

                    char old = board[i];
                    board[i] = 'X';

                    int score = minimax(true);

                    board[i] = old;

                    best = Math.min(best, score);
                }
            }

            return best;
        }
    }

    static int bestMove() {

        int bestScore = -1000;
        int move = -1;

        for (int i = 0; i < 9; i++) {
            if (board[i] != 'X' && board[i] != 'O') {

                char old = board[i];
                board[i] = 'O';

                int score = minimax(false);

                board[i] = old;

                if (score > bestScore) {
                    bestScore = score;
                    move = i;
                }
            }
        }

        return move;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("TIC TAC TOE");
        System.out.println("You are X, Computer is O");

        while (true) {

            printBoard();

            System.out.print("Enter position (1-9): ");
            int pos = sc.nextInt();

            if (pos < 1 || pos > 9 ||
                board[pos - 1] == 'X' ||
                board[pos - 1] == 'O') {

                System.out.println("Invalid move! Try again.");
                continue;
            }

            board[pos - 1] = 'X';

            if (checkWin('X')) {
                printBoard();
                System.out.println("You win!");
                break;
            }

            if (isFull()) {
                printBoard();
                System.out.println("Draw!");
                break;
            }

            int move = bestMove();
            board[move] = 'O';

            System.out.println("Computer chooses position " + (move + 1));

            if (checkWin('O')) {
                printBoard();
                System.out.println("Computer wins!");
                break;
            }

            if (isFull()) {
                printBoard();
                System.out.println("Draw!");
                break;
            }
        }

        sc.close();
    }
}
