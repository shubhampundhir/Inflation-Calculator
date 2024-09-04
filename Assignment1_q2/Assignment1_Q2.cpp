#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class InflationRate {
private:
    vector<int> years;
    vector<double> inflationRates;

public:
    void loadData(const string& filename) {
        ifstream file(filename);
        string line;
        if (getline(file, line)) {}

        while (getline(file, line)) {
            stringstream ss(line);
            string date, propertyRate, inflation;

            if (getline(ss, date, ',') && getline(ss, propertyRate, ',') && getline(ss, inflation, ',')) {
                int year = stoi(date.substr(0, 4));
                years.push_back(year);
                inflationRates.push_back(stod(inflation));
            }
        }
    }

    double getInflationRate(int year) const {
        for (size_t i = 0; i < years.size(); ++i) {
            if (years[i] == year) {
                return inflationRates[i];
            }
        }
        return 0.0;
    }
};

class PropertyRate {
private:
    vector<int> years;
    vector<double> propertyRates;

public:
    void loadData(const string& filename) {
        ifstream file(filename);
        string line;
        if (getline(file, line)) {}

        while (getline(file, line)) {
            stringstream ss(line);
            string date, propertyRate, inflation;

            if (getline(ss, date, ',') && getline(ss, propertyRate, ',') && getline(ss, inflation, ',')) {
                int year = stoi(date.substr(0, 4));
                years.push_back(year);
                propertyRates.push_back(stod(propertyRate));
            }
        }
    }

    double getPropertyRate(int year) const {
        for (size_t i = 0; i < years.size(); ++i) {
            if (years[i] == year) {
                return propertyRates[i];
            }
        }
        return 0.0;
    }
};

class TaxCalculator {
private:
    double costPrice;
    int purchaseYear;
    InflationRate inflationRate;
    PropertyRate propertyRate;

public:
    TaxCalculator(double costPrice, int purchaseYear, const InflationRate& inflationRate, const PropertyRate& propertyRate)
        : costPrice(costPrice), purchaseYear(purchaseYear), inflationRate(inflationRate), propertyRate(propertyRate) {}

    double computeProfitFactor(int sellingYear) const {
        double profitFactor = 1.0;
        for (int year = purchaseYear + 1; year <= sellingYear; ++year) {
            double growthRate = propertyRate.getPropertyRate(year);
            double inflation = inflationRate.getInflationRate(year);

            // Debugging output
            // cout << "Year: " << year << ", Growth Rate: " << growthRate << "%, Inflation Rate: " << inflation << "%" << endl;

            profitFactor *= (1 + (growthRate - inflation) / 100);
        }
        return profitFactor;
    }

    double computeActualProfit(int sellingYear) const {
        double profitFactor = computeProfitFactor(sellingYear);
        return costPrice * profitFactor - costPrice;
    }

    double computeTraditionalLTCG(int sellingYear) const {
        double actualProfit = computeActualProfit(sellingYear);
        return actualProfit * 0.20;
    }

    double computeNewLTCG(int sellingYear) const {
        double growthFactor = 1.0;
        for (int year = purchaseYear + 1; year <= sellingYear; ++year) {
            double growthRate = propertyRate.getPropertyRate(year);

            // Debugging output
            // cout << "Year: " << year << ", Growth Rate: " << growthRate << "%" << endl;

            growthFactor *= (1 + growthRate / 100);
        }
        double sellingPrice = costPrice * growthFactor;
        double actualProfit = sellingPrice - costPrice;
        return actualProfit * 0.125;
    }

    void compareTaxes(int sellingYear) const {
        double traditionalTax = computeTraditionalLTCG(sellingYear);
        double newTax = computeNewLTCG(sellingYear);

        cout << "Traditional LTCG Tax (20% with inflation adjustment): Rs " <<fixed<<setprecision(2) << traditionalTax << " lakhs" << endl;
        cout << "New LTCG Tax (12.5% without inflation adjustment): Rs " <<fixed<<setprecision(2) << newTax << " lakhs" << endl;

        double difference = traditionalTax - newTax;
        if (difference > 0) {
            cout << "Traditional taxation leads to higher taxes by Rs " <<fixed<<setprecision(2) << difference << " lakhs." << endl;
        } else {
            cout << "New taxation leads to higher taxes by Rs " <<fixed<<setprecision(2) << -difference << " lakhs." << endl;
        }
    }
};

int main() {
    InflationRate inflationRate;
    PropertyRate propertyRate;
    inflationRate.loadData("C:/Users/hp/Downloads/OOPD/price-inflation.csv");
    propertyRate.loadData("C:/Users/hp/Downloads/OOPD/price-inflation.csv");

    double costPrice;
    int purchaseYear;
    int sellingYear;

    cout << "Enter the cost price of the property (in lakhs): ";
    cin >> costPrice;

    cout << "Enter the purchase year: ";
    cin >> purchaseYear;

    cout << "Enter the selling year: ";
    cin >> sellingYear;

    TaxCalculator taxCalculator(costPrice, purchaseYear, inflationRate, propertyRate);
    taxCalculator.compareTaxes(sellingYear);

    return 0;
}
