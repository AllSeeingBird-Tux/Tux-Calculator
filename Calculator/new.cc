#include <iostream>
#include <string>
using namespace std;

int main() {
    int number;
    int numberc;
    char type;
    char sqtype;
    char operation;
    int result = 0;

    std::cout << "Do you want to use indices(s) or  multiplication/divison/addition/subtraction(m)?: ";
    std::cin >> type;

    type = std::tolower(type);

    std::cout << "Enter a number: ";
    std::cin >> number;


    switch(type) {
        case 's':
        {
            std::cout << "Do you want to Square the number(S), Cube the number(C) or Quad the number(Q)?: ";
            std::cin >> sqtype;

        sqtype = std::tolower(sqtype);

        switch(sqtype) {
            case 's':
                result = number * number;
                break;

            case 'c':
                result = number * number * number;
                break;

            case 'q':
                result = number * number * number * number;
                break;
            
        }
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

        //case 'r':
        //{
            //std::cout << "Do you want to Square Root the number(S), Cube Root the number(C) or Quad Root the number(Q)?: ";
            //std::cin >> sqtype;

        //sqtype = std::tolower(sqtype);

        //switch(sqtype) {
            //case 's':
                //result = number / number;
                //break;

            //case 'c':
                //result = number / number / number;
                //break;

            //case 'q':
                //result = number / number / number / number;
                //break;
            
        //}
        //break;



    }

    
    std::cout << "Result: " << result << std::endl;

    return 0;
       }   

