#include <iostream>
#include <string>
#include <cmath>
#include <string>
using namespace std;

int main() {
    int number;
    int numberc;
    char type;
    int sqtype;
    char operation;
    int result = 0;

    std::cout << "Do you want to use indices(s), roots(r) or  multiplication/divison/addition/subtraction(m)?: ";
    std::cin >> type;

    type = std::tolower(type);

    std::cout << "Enter a number: ";
    std::cin >> number;


    switch(type) {
        case 's':
        {
            std::cout << "What indice do you want to use?: ";
            std::cin >> sqtype;

            result = pow(number, sqtype);
            break;
    }
        

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
            case 'x':
                result = number * numberc;
                break;
            case '/':
                result = number / numberc;
                break;
        }
        break;

        case 'r':
            result = sqrt(number);
            break;


    }

    
    std::cout << "Result: " << result << std::endl;

    return 0;
       }   

