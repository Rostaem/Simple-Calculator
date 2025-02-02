#include <iostream>
using namespace std;

int main() {
    char operation;
    double number1, number2;

    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    cout << "Enter two numbers: ";
    cin >> number1 >> number2;

    switch (operation) {
        case '+':
            cout << "Result: " << number1 + number2 << endl;
        break;
        case '-':
            cout << "Result: " << number1 - number2 << endl;
        break;
        case '*':
            cout << "Result: " << number1 * number2 << endl;
        break;
        case '/':
            if (number2 == 0) {
                cout << "Error: Division by zero is not allowed." << endl;
            } else {
                cout << "Result: " << number1 / number2 << endl;
            }
        break;
        default:
            cout << "Invalid operation." << endl;
        break;
    }

    return 0;
}
// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.