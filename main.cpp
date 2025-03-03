#include <iostream>
#include <type_traits>
#include <limits>
#include <sstream>
#include <iomanip>
using namespace std;
int WIDTH = 60;
//my input validation standard general function
template <typename T>
T input_validation(const string& prompt, T min, T max) {
	T value;
	string input;
	while (true) {
		cout << prompt;
		getline(cin, input);  // Read the whole line as a string

		stringstream ss(input);  // Use stringstream to check if the input can be parsed as the expected type

		// Try to parse the input
		if (ss >> value && ss.eof() && value >= min && value <= max) {
			// If parsing succeeded and there's nothing left in the stream, it's a valid input
			return value;
		} else {
			// Handle invalid input (non-numeric or extra characters)
			cout << "Invalid input. Please enter a valid number between " << min << " and " << max << ".\n";
		}
	}
}

//my output formatting standard general function
void display_main_menu() {
	// Top border
	cout << setfill('*') << setw(WIDTH) << "" << endl;

	// Title
	string title = "Welcome to The Basic Calculator Program!";
	int padding = (WIDTH - title.length()) / 2;
	cout << setfill(' ') << setw(padding + title.length()) << title
		 << setw(WIDTH - padding - title.length()) << "" << endl;

	string subtitle = "Choose an operator:";
	padding = (WIDTH - subtitle.length()) / 2;
	cout << setw(padding + subtitle.length()) << subtitle
		 << setw(WIDTH - padding - subtitle.length()) << "" << endl;

	// Bottom border
	cout << setfill('*') << setw(WIDTH) << "" << endl;

	// Main menu options
	vector<string> main_menu_options = {
		"1. + (addition)",
		"2. - (subtraction)",
		"3. * (multiplication)",
		"4. - (division)",
		"5. Exit",
	};
	for (const auto& option : main_menu_options) {
		cout << option << endl;
	}

	cout << "Enter your choice: ";
}

void perform_operation (int choice, double num1, double num2) {
	switch (choice) {
		case 1:
			cout << "Result: " << num1 + num2 << endl;
			break;
		case 2:
			cout << "Result: " << num1 - num2 << endl;
			break;
		case 3:
			cout << "Result: " << num1 * num2 << endl;
			break;
		case 4:
			if (num2 != 0 ) {
				cout << "Result: " << num1 / num2 << endl;
			} else {
				cout << "Division by Zero is not allowed" << endl;
			}
			break;
		default :
		cout << "Invalid choice." << endl;
		break;
	}
}

int main() {
	double max_double = numeric_limits<double>::max();
	double min_double = numeric_limits<double>::lowest();
	int choice = 0;

	while (true) {
		display_main_menu();
		choice = input_validation("", 1, 5 );

		if (choice == 5) {
			cout << "Exiting the program" << endl;
			break;
		}
		double num1 = input_validation("enter a number: ", min_double, max_double);
		double num2 = input_validation("enter a number: ", min_double, max_double);
		perform_operation(choice, num1, num2);
	}
}
// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.