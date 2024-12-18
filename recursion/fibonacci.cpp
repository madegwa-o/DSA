#include <iostream>
#include <vector>


using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } 
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(){
    int n;

    cout << "Enter the number of fibonacci terms: ";
    cin >> n;

    cout << "answer is " << fibonacci(n);

}