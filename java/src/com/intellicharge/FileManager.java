package com.intellicharge;

import java.io.*;
import java.nio.file.*;

public class FileManager {

    private static final String DATA_DIR = "data";
    private static final String INPUT_FILE = "input.txt";
    private static final String OUTPUT_FILE = "output.txt";

    public FileManager() {
        File dir = new File(DATA_DIR);
        if (!dir.exists()) {
            dir.mkdirs();
        }
    }

    public boolean writeInputFile(User user) {

        String path = DATA_DIR + File.separator + INPUT_FILE;

        try (PrintWriter writer = new PrintWriter(new FileWriter(path))) {

            writer.println(user.getName());
            writer.println(user.getCurrentUnits());
            writer.println(user.getPreviousUnits());
            writer.println(user.getCustomerType());

            System.out.println("[FileManager] Input file written");
            return true;

        } catch (IOException e) {
            System.err.println("[FileManager] Write error: " + e.getMessage());
            return false;
        }
    }

    public String readOutputFile() {

        String path = DATA_DIR + File.separator + OUTPUT_FILE;

        try {
            return new String(Files.readAllBytes(Paths.get(path)));
        } catch (IOException e) {
            System.err.println("[FileManager] Read error: " + e.getMessage());
            return null;
        }
    }

    public void cleanup() {
        File input = new File(DATA_DIR + File.separator + INPUT_FILE);
        if (input.exists()) {
            input.delete();
        }
    }
}
