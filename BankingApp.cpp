//============================================================================
// Name        : BankingApp.cpp
// Author      : Michael Tekin
// Description : Banking App for calculating interest earned with and without
//               additional monthly deposits.
//============================================================================


#include <iostream>
#include <iomanip> //Used for formatting text
using namespace std;

//Using double in order to properly work with reasonably large values
double initialInvestment; //Given by user
double monthlyDeposit; //Given by user
double annualInterestRate; //Given by user
double numOfYears; //Number of years to continue earning interest. Given by user
double annualEarnedInterest; //Calculated year end interest
double monthlyOpening; //Temp value for calculating year end balance
double monthlyInterestEarned; //Used to calculate year end interest earned
string monthlyOpeningString; //Used for properly aligning text in static reports
string annualEarnedInterestString; //Used for properly aligning text in static reports
string yearString; //Used for properly aligning text in static reports
bool validInput; //Used to ensure user enters a valid input


//Function for allowing programmer to create borders of any length with any character
void printBorder(int length, char character) {
	for (int i = 0; i < length; ++i) {
			cout << character;
	}
}


//Function for displaying input header similar to what was provided in requirements document
void displayInputHeader() {
	printBorder(56, '*');
	cout << endl;
	printBorder(22, '*');
	cout << " Data Input ";
	printBorder(22, '*');
	cout << endl;
}


//Function for gathering initial input values
void gatherInput(double& initialInvestment, double& monthlyDeposit, double& annualInterestRate, double& numOfYears) {
	validInput = false;
	while (!validInput) { //Continue trying to get input until valid input is provided for all inputs
		try {
			//Checking each of the following input attempts to ensure it's a number and that it is positive
			cout << "Initial Investment Amount: $";
			cin >> initialInvestment;
			if (cin.fail() || (initialInvestment < 0)) {
				cin.clear(); //Clear fail flag
				cin.ignore(256, '\n'); //Clear input buffer
				throw runtime_error("Invalid input. Input must be positive number.");
			}

			cout << "Monthly Deposit: $";
			cin >> monthlyDeposit;
			if (cin.fail() || (monthlyDeposit < 0)) {
				cin.clear(); //Clear fail flag
				cin.ignore(256, '\n'); //Clear input buffer
				throw runtime_error("Invalid input. Input must be positive number.");
			}

			cout << "Annual Interest: %";
			cin >> annualInterestRate;
			if (cin.fail() || (annualInterestRate < 0)) {
				cin.clear(); //Clear fail flag
				cin.ignore(256, '\n'); //Clear input buffer
				throw runtime_error("Invalid input. Input must be positive number.");
			}

			cout << "Number of years: ";
			cin >> numOfYears;
			if (cin.fail() || (numOfYears < 0)) {
				cin.clear(); //Clear fail flag
				cin.ignore(256, '\n'); //Clear input buffer
				throw runtime_error("Invalid input. Input must be positive number.");
			}

			system("pause"); //Prints "Press any key to continue . . ." and waits for user to press enter
			cout << endl << endl << endl;
		}
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl;
			continue;
		}
		validInput = true;
	}

}


//Function for displaying both static report headers
void displayReportHeader(string reportType) { //The parameter allows us to print each different report with minimal duplicate code
	cout << "Balance and Interest " << reportType << " Additional Monthly Deposits" << endl;
	printBorder(56, '=');
	cout << endl << "Year      Year End Balance      Year End Earned Interest" << endl;
	printBorder(56, '-');
	cout << endl;
}


//Function for displaying both static reports
void displayReport(double depositAmount) { //depositAmount parameter used to print a report with monthly deposits and without
	monthlyOpening = initialInvestment; //Initializing temporary variable "monthlyOpening" with input provided by user
	annualEarnedInterest = 0;
	for (int i = 1; i <= (numOfYears * 12); ++i) { //Times 12 used because loop will need to repeat for each month of the year
		monthlyInterestEarned = (monthlyOpening + depositAmount) * (annualInterestRate/100/12); //Formula for calculating interest earned per month
		annualEarnedInterest += monthlyInterestEarned;
		//Each subsequent month is the sum of the previous months opening, the deposit amount, and the interest earned
		monthlyOpening = monthlyInterestEarned + monthlyOpening + depositAmount;
		if (i % 12 == 0) { //If the loop has reached the end of the year, print that year ends values
			monthlyOpeningString = to_string(monthlyOpening); //Converting to string in order to get length so that we can properly align output
			annualEarnedInterestString = to_string(annualEarnedInterest); //Converting to string in order to get length so that we can properly align output
			yearString = to_string(i / 12);
			cout << fixed << setprecision(2)
				 << (i / 12) << setw(25 - monthlyOpeningString.length() - yearString.length()) << "$" << monthlyOpening << setw(28 - annualEarnedInterestString.length()) << "$" << annualEarnedInterest << endl << endl;
			annualEarnedInterest = 0; //Resetting annualEarnedInterest at the end of every year (after displaying that value)
		}
	}
	cout << endl << endl << endl;
}


int main() {
	displayInputHeader();
	gatherInput(initialInvestment, monthlyDeposit, annualInterestRate, numOfYears);

	displayReportHeader("Without");
	displayReport(0); //Display static report with 0 additional monthly deposits

	displayReportHeader("With");
	displayReport(monthlyDeposit); //Display static report with monthly deposits provided by user

	return 0;
}
