#include <iostream>  // Include the input/output stream library

// Function declaration: Adds two numbers and returns the result
int add(int a, int b) {
    return a + b;
}

// Main function: Entry point of the program
int main() {
    int num1, num2;  // Declare two integer variables

    // Prompt the user for input
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    // Call the add function and store the result
    int sum = add(num1, num2);

    // Output the result
    std::cout << "The sum of " << num1 << " and " << num2 << " is " << sum << std::endl;

    return 0;  // Indicate that the program ended successfully
}
