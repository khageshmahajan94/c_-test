/*
Calculator : 
Write a calculator program which provides a command-line interface 
Write Clean code 
Consider all possible test cases
*/
#include <iostream>
#include <cstdlib>

enum cal {Add = 1, Substract, Multiply, Division};

class Calculator
{
public:
    double add(int argc, char** argv)
    {
        double result = 0;
        char* end;
        for(int i=1; i<argc;i++)
        {
            result = result + (std::strtod(argv[i], &end));
        }

        return result;
    }

    double sub(int argc, char** argv)
    {
        char* end;
        double result = (std::strtod(argv[1], &end));
        
        for(int i=2; i<argc;i++)
        {
            result = result - (std::strtod(argv[i], &end));
        }

        return result;
    }

    double mul(int argc, char** argv)
    {
        double result = 1;
        char* end;
        for(int i=1; i<argc;i++)
        {
            result = result * (std::strtod(argv[i], &end));
        }

        return result;
    }

    double div(int argc, char** argv)
    {
        char* end;
        double result = (std::strtod(argv[1], &end));
        
        for(int i=2; i<argc;i++)
        {
            if((std::strtod(argv[i], &end)) != 0)
            {
                result = result / (std::strtod(argv[i], &end));
            }
            else
            {
                std::cout << "Cannot divide by Zero!" << std::endl;
                return 0;
            }
            
        }

        return result;
    }
};

int main(int argc, char* argv[])
{
    Calculator calc;
    double result;
    
    std::cout << "What Operation do you want to perform 1.Addition, 2.Substraction, 3.Multiplication, 4.Division : " << std::endl;
    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case Add:
        result = calc.add(argc, argv);
        std::cout << result << std::endl;
        break;
    case Substract:
        result = calc.sub(argc, argv);
        std::cout << result << std::endl;
        break;
    case Multiply:
        result = calc.mul(argc, argv);
        std::cout << result << std::endl;
        break;
    case Division:
        result = calc.div(argc, argv);
        std::cout << result << std::endl;
        break;
    default:
        break;
    }
}