#include <iostream>
using namespace std;

int main(int argv, char **argc){
    double kg=0;

    cout << "introduce your weight in kgs: ";
    cin >> kg;

    cout << "your weight in pounds is: " << kg * 2.20462 << endl;

    return 0;
}