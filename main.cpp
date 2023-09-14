#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

// Calculate AGI and repair any negative values
int CalcAGI(int &wages, int &interest, int &unemployment) {
  /* Complete the function and update the return statement */
  // AGI is calculated and any negative output will be positive
  if ((wages < 0) || (interest < 0) || (unemployment < 0)) {
    wages = wages * -1;
    interest = interest * -1;
    unemployment = unemployment * -1;
  }
  return wages + interest + unemployment;
}

// Calculate deduction depending on single, dependent or married
int GetDeduction(int &status) {
  /* Complete the function and update the return statement */
  // deduction is calculated based on the number the user types in
  if (status == 0) {
    return 6000;
  } else if (status == 1) {
    return 12000;
  } else if (status == 2) {
    return 24000;
  } else {
    return 6000;
  }

  return -1;
}

// Calculate taxable but not allow negative results
int CalcTaxable(const int agi, const int deduction) {
  /* Complete the function and update the return statement */
  // taxable is calculated with only positive numbers
  int total = agi - deduction;
  if (total < 0)
    return 0;

  return total;
}

// Calculate tax for single or dependent
int CalcTax(const int status, const int taxable) {
  /* Complete the function and update the return statement */
  double tax;
  // calculation based on status and income
  // tax for dependent or single filers and income based
  if ((status == 0) || (status == 1)) {
    if ((taxable >= 0) && (taxable <= 10000)) {
      tax = taxable * 0.1;
    } else if ((taxable >= 10001) && (taxable <= 40000)) {
      tax = (1000 + (taxable - 10000) * 0.12);
    } else if ((taxable >= 40001) && (taxable <= 85000)) {
      tax = (4600 + (taxable - 40000) * 0.22);
    } else {
      tax = (14500 + (taxable - 85000) * 0.24);
    }
  }
  // tax for married filers and income based
  if (status == 2) {
    if ((taxable >= 0) && (taxable <= 20000)) {
      tax = taxable * 0.1;
    } else if ((taxable >= 20001) && (taxable <= 80000)) {
      tax = (2000 + (taxable - 20000) * 0.12);
    } else {
      tax = (9200 + (taxable - 80000) * 0.22);
    }
  }
  // output
  tax = round(tax);

  // should be rounded to nearest whole number before returning and should be
  // int

  return tax;
}

// Calculate tax due and check for negative withheld
int CalcTaxDue(const int tax, int withheld) {
  /* Complete the function and update the return statement */
  // calculates taxes due and withheld=0 if less than 0
  int total = tax - withheld;
  if (withheld < 0) {
    withheld = 0;
    total = tax - withheld;
  }
  return total;
  ;
}

int main() {
  int wages, interest, unemployment, status, withheld;
  int tax, agi, due, deduction, taxable;

  // Step #1: Input information
  // output and input for wages
  cout << "Enter your wage: $";
  cin >> wages;
  // output and input for interest
  cout << "Enter your interest: ";
  cin >> interest;
  // output and input for unemployment compensation
  cout << "Enter your unemployment compensation: $";
  cin >> unemployment;
  // output and input for status
  cout << "Enter your status (0-2): ";
  cin >> status;
  // output when inccorect status value is inputted
  while ((status > 2) || (status < 0)) {
    cout << "Incorrect. Please Enter a vaild number: ";
    cin >> status;
  }
  ////output and input for withheld
  cout << "Enter how much taxes that are withheld: $"<<endl;
  cin >> withheld;

  // Step #2: Calculate AGI
  // agi output
  agi = CalcAGI(wages, interest, unemployment);

  cout << "AGI: $" << agi << endl;
  // deduction output
  deduction = GetDeduction(status);
  cout << "Deduction: $" << deduction << endl;
  // taxable output
  taxable = CalcTaxable(agi, deduction);
  cout << "Taxable income: $" << taxable << endl;
  // tax output
  tax = CalcTax(status, taxable);
  cout << "Federal tax: $" << tax << endl;
  // due output
  due = CalcTaxDue(tax, withheld);
  cout << "Tax due: $" << due << endl;
  return 0;
}