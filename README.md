# OOPD Assignment 1 (Monsoon 2024)

## Steps to Compile and Build the C++ Code Using Makefile

1. Place the `Makefile` in the root directory of your project folder.
2. Open the terminal and use the following commands:
   - `make`: To build the executables.(Both debug, optimized)
   - `./debug_binary`: To run the debug version.
   - `./optimized_binary`: To run the optimized version.

# Q1. Property Profit and LTCG Tax Calculator

## Overview
In the first question, we computes the selling price of a property and the Long-Term Capital Gains (LTCG) tax based on historical inflation and property growth rates. It uses data from a CSV file to determine the inflation and property growth rates for specific years. The calculation considers the purchase year, cost price, and selling year provided by the user.

## Features
- **Loading Inflation and Property Rate Data**: The program reads inflation and property rates for each year from a CSV file (`price-inflation.csv`).
- **Profit Calculation**: Computes the profit based on the difference between property growth rate and inflation for each year in the period.
- **LTCG Tax Calculation**: Applies a 20% tax rate on the actual profit.

## Steps Involved

### 1. Data Loading:
The CSV file is loaded, and the inflation and property growth rates are stored in vectors for each year.

### 2. User Input:
The user provides the following:
- `costPrice`: Initial cost price of the property in lakhs.
- `purchaseYear`: The year the property was bought.
- `sellingYear`: The year the property is to be sold.

### 3. Profit Factor Calculation:
For each year between the purchase and selling years, the profit factor is calculated as:

**profitFactor** = ∏ from purchaseYear+1 to sellingYear * (1 + (growthRate - inflationRate) / 100)

Where:
- `growthRate`: Property rate growth for each year.
- `inflationRate`: Inflation rate for each year.

### 4. Actual Profit Calculation:
The actual profit is computed using the formula:

**actualProfit** = costPrice * profitFactor - costPrice

### 5. Selling Price Calculation:
The selling price is derived as:

**reducedProfit** = 0.80 * actualProfit 

**sellingPrice** = costPrice + reducedProfit

### 6. LTCG (Long-Term Capital Gains) Calculation:
The LTCG is computed at a 20% tax rate on the actual profit:

**LTCG** = 0.20 * actualProfit

## Program Structure

### Class `InflationRate`:
Manages loading data from a CSV file and provides methods to retrieve inflation and property growth rates for a given year.

### Class `TaxCalculator`:
Performs the main calculations: profit factor, actual profit, selling price, and LTCG.

## File Structure
- **`price-inflation.csv`**: CSV file containing yearly inflation and property growth data in the format `Year, PropertyRate, InflationRate`.
- **`main.cpp`**: Contains the program's main logic and execution flow.

## Example CSV File (`price-inflation.csv`):
Year,PropertyRate,InflationRate 2001,4.5,3.2 2002,5.0,3.0 ...

## References
- Reading CSV data: https://iq.opengenus.org/read-and-write-in-csv-in-cpp/
- Makefile tutorial: https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html
- Code assistance from **ChatGPT** / **Claude**.
