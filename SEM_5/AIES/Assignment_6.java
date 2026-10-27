import java.util.*;

public class Main {

    static String reply(String text) {
        String[] words = text.toLowerCase().split("[^a-z0-9]+");

        for (String w : words) {
            if (w.equals("hi") || w.equals("hello") || w.equals("hey")) {
                String[] responses = {"Hi!", "Hello!"};
                Random random = new Random();
                return responses[random.nextInt(responses.length)];
            }
        }

        for (String w : words) {
            if (w.equals("name")) {
                return "I am a chatbot.";
            }
        }

        return "Sorry, I don't understand.";
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.print("You: ");
            String msg = sc.nextLine();

            if (msg.equalsIgnoreCase("bye")) {
                System.out.println("Bot: Goodbye!");
                break;
            }

            System.out.println("Bot: " + reply(msg));
        }

        sc.close();
    }
}