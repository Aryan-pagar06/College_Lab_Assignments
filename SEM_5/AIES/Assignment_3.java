
import java.util.*;

public class SendMoreMoney {

    public static void main(String[] args) {

        int[] digits = new int[10];

        for (int i = 0; i < 10; i++) {
            digits[i] = i;
        }

        do {
            int s = digits[0];
            int e = digits[1];
            int n = digits[2];
            int d = digits[3];
            int m = digits[4];
            int o = digits[5];
            int r = digits[6];
            int y = digits[7];

            if (s == 0 || m == 0) {
                continue;
            }

            int send = s * 1000 + e * 100 + n * 10 + d;
            int more = m * 1000 + o * 100 + r * 10 + e;
            int money = m * 10000 + o * 1000 + n * 100
                        + e * 10 + y;

            if (send + more == money) {

                System.out.println("S = " + s);
                System.out.println("E = " + e);
                System.out.println("N = " + n);
                System.out.println("D = " + d);
                System.out.println("M = " + m);
                System.out.println("O = " + o);
                System.out.println("R = " + r);
                System.out.println("Y = " + y);

                System.out.println();
                System.out.println(" " + send);
                System.out.println("+ " + more);
                System.out.println("------");
                System.out.println(" " + money);

                break;
            }

        } while (nextPermutation(digits));

    }

    static boolean nextPermutation(int[] a) {
        int i = a.length - 2;

        while (i >= 0 && a[i] >= a[i + 1]) {
            i--;
        }

        if (i < 0) {
            return false;
        }

        int j = a.length - 1;

        while (a[j] <= a[i]) {
            j--;
        }

        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        int left = i + 1;
        int right = a.length - 1;

        while (left < right) {
            temp = a[left];
            a[left] = a[right];
            a[right] = temp;

            left++;
            right--;
        }

        return true;
    }
}



import java.util.*;

public class Cryptarithmetic {

    static String w1, w2, w3;

    static ArrayList<Character> uniqueLetters = new ArrayList<>();

    static int[] assignedDigits = new int[10];
    static boolean[] usedDigits = new boolean[10];

    static boolean solved = false;

    static long getWordValue(String word) {
        long value = 0;

        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);

            int index = uniqueLetters.indexOf(ch);

            value = value * 10 + assignedDigits[index];
        }

        return value;
    }

    static void solve(int index) {

        if (index == uniqueLetters.size()) {

            for (int i = 0; i < uniqueLetters.size(); i++) {

                if (uniqueLetters.get(i) == w1.charAt(0)
                    && assignedDigits[i] == 0) {
                    return;
                }

                if (uniqueLetters.get(i) == w2.charAt(0)
                    && assignedDigits[i] == 0) {
                    return;
                }

                if (uniqueLetters.get(i) == w3.charAt(0)
                    && assignedDigits[i] == 0) {
                    return;
                }
            }

            long num1 = getWordValue(w1);
            long num2 = getWordValue(w2);
            long num3 = getWordValue(w3);

            if (num1 + num2 == num3) {

                solved = true;

                for (int i = 0; i < uniqueLetters.size(); i++) {
                    System.out.println(
                        uniqueLetters.get(i) + " = " + assignedDigits[i]
                    );
                }

                System.out.println();
                System.out.println(" " + num1);
                System.out.println("+ " + num2);
                System.out.println("------");
                System.out.println(" " + num3);
            }

            return;
        }

        for (int d = 0; d <= 9; d++) {

            if (!usedDigits[d]) {

                usedDigits[d] = true;
                assignedDigits[index] = d;

                solve(index + 1);

                if (solved) {
                    return;
                }

                usedDigits[d] = false;
            }
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter first word: ");
        w1 = sc.next().toUpperCase();

        System.out.print("Enter second word: ");
        w2 = sc.next().toUpperCase();

        System.out.print("Enter result word: ");
        w3 = sc.next().toUpperCase();

        String combined = w1 + w2 + w3;

        for (int i = 0; i < combined.length(); i++) {

            char ch = combined.charAt(i);

            if (!uniqueLetters.contains(ch)) {
                uniqueLetters.add(ch);
            }
        }

        if (uniqueLetters.size() > 10) {
            System.out.println(
                "More than 10 unique letters. Cannot solve."
            );
            sc.close();
            return;
        }

        solve(0);

        if (!solved) {
            System.out.println("No solution found.");
        }

        sc.close();
    }
}

