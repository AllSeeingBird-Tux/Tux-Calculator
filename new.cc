#include <iostream>
#include <string>
using namespace std;

int main() {
    int number;
    int numberc;
    char type;
    char operation;
    int result;

    std::cout << "Do you want to use indices(s) or multiplication/divison/addition/subtraction(m)?: ";
    std::cin >> type;

    type = std::tolower(type);

    std::cout << "Enter a number: ";
    std::cin >> number;


    switch(type) {
        case 's':
        result = number * number;
        break;

        case 'm':
        std::cout << "Enter another number: ";
        std::cin >> numberc;

        std::cout << "Enter the operation you want to use: ";
        std::cin >> operation;

        switch(operation) {
            case '+':
                result = number + numberc;
                break;
            case '-':
                result = number - numberc;
                break;
            case '*':
                result = number * numberc;
                break;
            case '/':
                result = number / numberc;
                break;
        }
    }

    
    std::cout << "Result: " << result;

    return 0;
}
