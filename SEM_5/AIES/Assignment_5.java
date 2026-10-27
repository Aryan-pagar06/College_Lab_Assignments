import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Mini Expert System");

        System.out.print("Do you have fever? (yes/no): ");
        String fever = sc.nextLine();

        System.out.print("Do you have cough? (yes/no): ");
        String cough = sc.nextLine();

        if (fever.equalsIgnoreCase("yes") &&
            cough.equalsIgnoreCase("yes")) {
            System.out.println("Possible flu");
        }
        else if (fever.equalsIgnoreCase("yes")) {
            System.out.println("Possible fever");
        }
        else if (cough.equalsIgnoreCase("yes")) {
            System.out.println("Possible cold");
        }
        else {
            System.out.println("No symptoms detected");
        }

        sc.close();
    }
}