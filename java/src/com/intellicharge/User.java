package com.intellicharge;

public class User {

    private String name;
    private int currentUnits;
    private int previousUnits;
    private String customerType;

    public User() {
        this.name = "";
        this.currentUnits = 0;
        this.previousUnits = 0;
        this.customerType = "";
    }

    public User(String name, int currentUnits, int previousUnits) {
        setName(name);
        setCurrentUnits(currentUnits);
        setPreviousUnits(previousUnits);
    }

    private void validateUnits(int units) {
        if (units < 0) {
            throw new IllegalArgumentException("Units cannot be negative");
        }
    }

    public String getName() {
        return name;
    }

    public int getCurrentUnits() {
        return currentUnits;
    }

    public int getPreviousUnits() {
        return previousUnits;
    }

    public String getCustomerType() {
        return customerType;
    }

    public void setName(String name) {
        if (name == null || name.trim().isEmpty()) {
            throw new IllegalArgumentException("Name cannot be empty");
        }
        this.name = name.trim();
    }

    public void setCurrentUnits(int currentUnits) {
        validateUnits(currentUnits);
        this.currentUnits = currentUnits;
    }

    public void setPreviousUnits(int previousUnits) {
        validateUnits(previousUnits);
        this.previousUnits = previousUnits;
    }

    public void setCustomerType(String type) {
        if (type == null || type.trim().isEmpty()) {
            throw new IllegalArgumentException("Customer type required");
        }
        this.customerType = type.trim();
    }

    @Override
    public String toString() {
        return "User{name='" + name + "', current=" + currentUnits +
               ", previous=" + previousUnits +
               ", type=" + customerType + "}";
    }
}
