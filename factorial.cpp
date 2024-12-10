#include <iostream>



class Factorial
{
public:
   
   int doFactorial(int num){

        if (num <= 1)
        {
            return num;
        }else{
            return num * doFactorial(num - 1);
        }
        
   }

   
};


int main(){

    Factorial factorial;

    int number;

    std::cout << "Enter a number: "; 
    std::cin >> number;

    int answer = factorial.doFactorial(number);


    std::cout << "The factorial is: " << answer << std::endl;

    

    return 0;
   }
