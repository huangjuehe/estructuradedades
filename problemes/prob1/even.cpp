#include <iostream>
using namespace std;

int main (int argv, char **argc){
    int number;
    cout << "Introduce a number: ";
    cin >> number;
    cout << "Your number is " << ( (number % 2 == 0)? "even" : "odd" ) << endl;

    return 0;
}