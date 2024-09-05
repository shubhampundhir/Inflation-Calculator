# Q2. COMPARING PROPERTY TAX BASED ON TRADITIONAL LTCG VS NEW LTCG POLICY.

This program calculates and compares property tax based on two methods of Long-Term Capital Gains (LTCG):
1. **Traditional LTCG**: 20% tax with inflation adjustment.
2. **New LTCG**: 12.5% tax without inflation adjustment.

## Features

- **Data Loading**: The program loads inflation and property growth rate data from a CSV file (price-inflation.csv).
- **Profit Calculation**: It computes the profit factor considering the growth and inflation rates year by year.
- **Tax Comparison**: It compares the taxes computed using the traditional LTCG and new LTCG methods and shows which one results in a higher tax.

## Data

- The program uses a CSV file containing the property rates and inflation rates, in the following format:
  Year,Property Rate,Inflation Rate 2001, 4.824, 3.7793
  
The CSV file must be named `price-inflation.csv` and should be available in the specified directory.

## How to Run

1. Clone the repository and navigate to the project directory.

2. Ensure that the CSV file `price-inflation.csv` is placed in the directory where the program is running.

3. Compile the program using the following command:
   **g++ -o tax_calculator assignment1_Q2.cpp**
   
5. Run the program:
  **./tax_calculator**
   
6. Follow the on-screen prompts to enter the cost price, purchase year, and selling year.

7. The program will display:
- The calculated LTCG tax based on both the traditional and new methods.
- A comparison of which method results in a higher tax.

## Inputs:
1. Enter the cost price of the property (in lakhs): " "
2. Enter the purchase year: 2000 Enter the selling year: "YYYY"
3. Traditional LTCG Tax (20% with inflation adjustment): Rs " " lakhs
4. New LTCG Tax (12.5% without inflation adjustment): Rs " " lakhs
    New taxation/Traditional taxation leads to higher taxes by Rs " " lakhs.

  
