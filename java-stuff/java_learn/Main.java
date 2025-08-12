package java_learn;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); 
        System.out.print("Name: "); 
        String name =scanner.nextLine(); 
        scanner.close(); 
        System.out.println("Hello, " + name); 
    }
}
