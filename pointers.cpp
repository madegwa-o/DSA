#include <iostream>
using namespace std;

int main(){

   string name = "Oscar";


    string *pName = &name;


    cout << name << endl;
    cout << &name << endl;
    cout << pName << endl;
    cout << *pName << endl;

   


    return 0;
}

