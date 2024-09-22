/*
 *Levi Hoffer
 *ljh0047
 *project1_HofferLevi_ljh0047
 *How to compile: g++ project1_HofferLevi_ljh0047.cpp
 *./a.out
*/
#include <iostream>
using namespace std;

int main() {
    double rate;
    double inRate;//rate that is inputed
    double monthlyPay;//monthly payment
    double loanAmount;
    int month = 0;
    double currentBal;//current balance
    double principal;
    double interest = 0;
    double cumInt = 0;//interest cumulated

    //get loan amount
    while(true) {
        cout << "Loan Amount:";
        cin >> loanAmount;
        currentBal = loanAmount;
        if(loanAmount <= 0) {//check to see if the value is valid, loop if it isn't
            cout << "Please provide a larger loan amount" << endl;
        }
        else {//if entered value is acceptable, break the loop
            break;
        }
    }

    //get interest rate
    while(true) {
        cout << "Interest Rate (% per year):";
        cin >> inRate;
        if(inRate <= 0) {//check to see if the value is valid, loop if it isn't
            cout << "Please provide a larger interest rate" << endl;
        }
        else {//if entered value is acceptable, break the loop
            break;
        }
    }
    inRate *= .01; //convert to decimal
    inRate /= 12; //divide by 12 for 12 months
    rate = inRate * 100; //create a new variable to print to the user


    //get monthly payment amount
    while(true){
        cout << "Monthly Payments:";
        cin >> monthlyPay;
        interest = currentBal * inRate;
        if(monthlyPay <= interest) {//check to see if the value is valid, loop if it isn't
            cout << "Please provide a larger monthly payment" << endl;
        }
        else {//if entered value is acceptable, break the loop
            break;
        }
    }


    currentBal = loanAmount;
    //print the top of the table
    cout << "***********************************************************" << endl
         << "       Amortization Table" << endl
         << "***********************************************************" << endl;
    //print the first  and second column
    printf("%-7s%-12s%-12s%-9s%-10s%-10s\n", "Month", "Balance", "Payment", "Rate", "Interest", "Principal");
    printf("%-7d%-12.2f%-12s%-9s%-10s%-10s\n", month, currentBal, "N/A", "N/A", "N/A", "N/A");
    month++;//increase month since month 0 has already been printed
    while(currentBal > 0) {
        interest = currentBal * inRate;
        cumInt += interest;
        principal = monthlyPay - interest;
        currentBal -= principal;
        if(currentBal <= 0) {//checks if you are at the last month in which special variables must be used
            double lastPay = monthlyPay + currentBal;
            double lastPrincipal = lastPay - interest;
            printf("%-7d%-12.2f%-12.2f%-9.2f%-10.2f%-10.2f\n", month, 0.00, lastPay, rate, interest, lastPrincipal);
        }
        else {//normal loop iteration
            printf("%-7d%-12.2f%-12.2f%-9.2f%-10.2f%-10.2f\n", month, currentBal, monthlyPay, rate, interest, principal);
            month += 1;
        }
    }

    //printing the last statement
    cout << "***********************************************************" << endl << endl;
    cout << "It takes "<< month << " months to pay off the loan." <<endl;
    printf("%s%.2f", "Total interest paid is: $", cumInt);
    cout << endl;


    return 0;


}
