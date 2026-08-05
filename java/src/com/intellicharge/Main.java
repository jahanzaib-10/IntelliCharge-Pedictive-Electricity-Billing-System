package com.intellicharge;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        System.out.println("  INTELLICHARGE BILLING SYSTEM v1.0\n");
        
        Scanner scanner = new Scanner(System.in);
        SystemController controller = new SystemController();

        try {
            System.out.print("Enter customer name: ");
            String name = scanner.nextLine().trim();

            System.out.print("Enter current month units: ");
            int currentUnits = Integer.parseInt(scanner.nextLine().trim());
            
            System.out.print("Enter previous month units: ");
            int previousUnits = Integer.parseInt(scanner.nextLine().trim());

            System.out.print("Enter customer type (Domestic / Commercial / Industrial): ");
            String customerType = scanner.nextLine().trim();

            User user = new User(name, currentUnits, previousUnits);
            user.setCustomerType(customerType);   

            System.out.println("\nProcessing...\n");

            boolean success = controller.processUser(user);

            if (success) {
                controller.displayResults();
            } else {
                System.err.println("Billing failed.");
            }

        } catch (NumberFormatException e) {
            System.err.println("Units must be numbers only.");
        } catch (Exception e) {
            System.err.println(e.getMessage());
        } finally {
            scanner.close();
        }

        System.out.println("\nThank you for using IntelliCharge.");
    }
}
