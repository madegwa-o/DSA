#include <iostream>

using namespace std;

class Multiplication
{

public:
    
    int multiply(int x, int y){
        if (y == 0)
        {
           return 0;
        }

        if (y<0)
        {
            return -multiply(x, -y);
        }

        return x + multiply(x, y-1);
        
        
    }
};

int main(){

    Multiplication multiplication;

    int a,b;

    cout << "input two numbers: ";
    cin >> a >> b;

    cout << " The multiple is "<< multiplication.multiply(a,b) << endl;

}

