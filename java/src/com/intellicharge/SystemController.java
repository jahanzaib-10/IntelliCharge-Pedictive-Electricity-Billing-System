package com.intellicharge;

import java.io.*;

public class SystemController {

    private FileManager fileManager;
    private String lastResults;

    private static final String CPP_EXECUTABLE = "bin\\calculator.exe";

    public SystemController() {
        this.fileManager = new FileManager();
        this.lastResults = null;
    }

    public boolean processUser(User user) {

        System.out.println("\n[Controller] Starting billing process");

        if (!fileManager.writeInputFile(user)) {
            System.err.println("[Controller] Input file write failed");
            return false;
        }

        if (!executeCppCalculator()) {
            System.err.println("[Controller] C++ execution failed");
            return false;
        }

        lastResults = fileManager.readOutputFile();
        if (lastResults == null) {
            System.err.println("[Controller] Output read failed");
            return false;
        }

        return true;
    }

    private boolean executeCppCalculator() {

        try {
            ProcessBuilder pb = new ProcessBuilder(CPP_EXECUTABLE);
            pb.redirectErrorStream(true);

            Process process = pb.start();

            BufferedReader reader =
                new BufferedReader(new InputStreamReader(process.getInputStream()));

            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println("[C++] " + line);
            }

            int exitCode = process.waitFor();
            return exitCode == 0;

        } catch (Exception e) {
            System.err.println("[Controller] Error running C++ program");
            return false;
        }
    }

    public void displayResults() {
        if (lastResults != null) {
            System.out.println(lastResults);
        }
    }

    public void cleanup() {
        fileManager.cleanup();
    }
}
