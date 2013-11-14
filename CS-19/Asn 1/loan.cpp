/**
 * John Carlyle
 * jcarlyle
 * john.w.carlyle@gmail.com
 * Solitaire.cpp
 * Assignment #1 Loan Payment Calculator
 * Calculates loan payments
 * Code Status: Working/Tested
 */

#include <iostream>
#include <iomanip>
#include <math.h>

int getInt(std::string);
float getPmt(int,int,int,int);

int main() {
  std::cout << "John Carlyle, jcarlyle, john.w.carlyle@gmail.com\n";
  std::cout << "?/?/?, Loan Payment Calculator, #1\n";
  int loanAmt = getInt("Enter the loan amount: ");
  int interestRate = getInt("Enter annual interset rate: ");
  int pmtsPerYear = getInt("Enter the number of payments per year: ");
  int years = getInt("Enter the number of years for the loan to be borrowed: ");

  std::cout << "payment = $" << std::setprecision (2) << std::fixed << getPmt(loanAmt, interestRate, pmtsPerYear, years) << std::endl; 
}


int getInt(std::string prompt) {
  int validInt;
  bool valid = false;
  std::cout << prompt;
  while (!valid) {
    std::cin >> validInt;
    if (std::cin.fail()) {
      std::cin.clear();
      std::string error;
      std::getline(std::cin, error);
      std::cout << error << " is not a valid integer, try again: ";
    }
    else 
      valid = true;
  }
  return validInt;
}


float getPmt(int loan, int rate, int peryear, int years) {
  float interest = rate / 100.0f / peryear;
  float numPayments = peryear * years;
  float payment = loan / ((1 - pow(1+interest, -numPayments))/interest);
  return payment;
}

