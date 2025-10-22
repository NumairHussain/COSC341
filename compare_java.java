import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class FileExample {
    public static void main(String[] args) {
        try {
            // Reading from a file using Scanner
            File inputFile = new File("input.txt");
            Scanner scanner = new Scanner(inputFile);

            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                System.out.println("Read line: " + line);
            }
            scanner.close();

            // Writing to a file using PrintWriter
            PrintWriter writer = new PrintWriter("output.txt");
            writer.println("Hello 5 world");
            writer.println("Another line");
            writer.close();

            System.out.println("File written successfully.");

        } catch (FileNotFoundException e) {
            System.out.println("File not found: " + e.getMessage());
        }
    }
}
