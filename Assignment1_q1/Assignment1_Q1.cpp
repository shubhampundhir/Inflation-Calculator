#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// Class to handle inflation and property rate data
class InflationRate {
private:
    vector<int> years;
    vector<double> inflationRates;
    vector<double> propertyRates;

public:
    // Function to load data from CSV
    void loadData(const string& filename) {
        ifstream file(filename);
        string line;
        
        // Skip the header line
        if (getline(file, line)) {
            // You may optionally process the header line here, if needed
        }

        while (getline(file, line)) {
            stringstream ss(line);
            string date, propertyRate, inflation;

            if (getline(ss, date, ',') && getline(ss, propertyRate, ',') && getline(ss, inflation, ',')) {
                try {
                    // Extract year from date (format: YYYY-MM-DD)
                    if (date.size() >= 4) {
                        int year = stoi(date.substr(0, 4));
                        years.push_back(year);
                        propertyRates.push_back(stod(propertyRate));
                        inflationRates.push_back(stod(inflation));
                    } else {
                        cerr << "Error: Invalid date format in line: " << line << endl;
                    }
                } catch (const invalid_argument& e) {
                    cerr << "Error: Invalid data format in line: " << line << endl;
                } catch (const out_of_range& e) {
                    cerr << "Error: Data out of range in line: " << line << endl;
                }
            } else {
                cerr << "Error: Missing data in line: " << line << endl;
            }
        }
    }
    // Function to get the inflation rate for a given year
    double getInflationRate(int year) const {
        for (size_t i = 0; i < years.size(); ++i) {
            if (years[i] == year) {
                return inflationRates[i];
            }
        }
        return 0.0; // Default if year not found
    }

    // Function to get the property rate for a given year
    double getPropertyRate(int year) const {
        for (size_t i = 0; i < years.size(); ++i) {
            if (years[i] == year) {
                return propertyRates[i];
            }
        }
        return 0.0; // Default if year not found
    }
};

// Class to handle tax calculations
class TaxCalculator {
private:
    double costPrice;
    int purchaseYear;
    InflationRate inflationRate;

public:
    TaxCalculator(double costPrice, int purchaseYear, const InflationRate& inflationRate)
        : costPrice(costPrice), purchaseYear(purchaseYear), inflationRate(inflationRate) {}

    // Function to compute the profit factor
    double computeProfitFactor(int sellingYear) const {
        double profitFactor = 1.0;
        for (int year = purchaseYear + 1; year <= sellingYear; ++year) {
            double growthRate = inflationRate.getPropertyRate(year);
            double inflation = inflationRate.getInflationRate(year);
            profitFactor *= (1 + (growthRate - inflation) / 100);
        }
        return profitFactor;
    }

    // Function to compute the actual profit
    double computeActualProfit(int sellingYear) const {
        double profitFactor = computeProfitFactor(sellingYear);
        double actualProfit = costPrice * profitFactor - costPrice;
        cout << "Actual Profit: Rs " <<fixed<<setprecision(2) << actualProfit << " lakhs" << endl;  // Print Actual Profit
        return actualProfit;
    }

    // Function to compute the selling price
    double computeSellingPrice(int sellingYear) const {
        double actualProfit = computeActualProfit(sellingYear);
        double reducedProfit = actualProfit * 0.80; // 80% of actual profit
        double sellingPrice = costPrice + reducedProfit;
        cout << "Selling Price: Rs " <<fixed<<setprecision(2) << sellingPrice << " lakhs" << endl;  // Print Selling Price
        return sellingPrice;
    }

    // Function to compute LTCG with 20% tax rate
    double computeLTCG(int sellingYear) const {
        double actualProfit = computeActualProfit(sellingYear);
        double LTCG = actualProfit * 0.20; // 20% of actual profit
        cout << "LTCG (20% of Actual Profit): Rs " <<fixed<<setprecision(2) << LTCG << " lakhs" << endl;  // Print LTCG
        return LTCG;
    }
};

int main() {
    // Load data from CSV
    InflationRate inflationRate;
    inflationRate.loadData("C:/Users/hp/Downloads/OOPD/price-inflation.csv");

    // Input from user
    double costPrice;
    int purchaseYear;
    int sellingYear;

    cout << "Enter the cost price of the property (in lakhs): ";
    cin >> costPrice;

    cout << "Enter the purchase year: ";
    cin >> purchaseYear;

    cout << "Enter the selling year: ";
    cin >> sellingYear;

    // Create TaxCalculator object
    TaxCalculator taxCalculator(costPrice, purchaseYear, inflationRate);

    // Compute selling price and LTCG
    double sellingPrice = taxCalculator.computeSellingPrice(sellingYear);
    double LTCG = taxCalculator.computeLTCG(sellingYear);

    // Output the results
    cout << "Estimated selling price: Rs " <<fixed<<setprecision(2) << sellingPrice << " lakhs" << endl;
    cout << "Long-Term Capital Gains Tax (20%): Rs " <<fixed<<setprecision(2) << LTCG << " lakhs" << endl;

    return 0;
}
