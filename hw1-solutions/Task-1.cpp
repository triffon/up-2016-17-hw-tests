#include <iostream>

using namespace std;

int main()
{
    int number;
    cin >> number;

    if (number < 1 || number > 3000)
    {
        cout << "Invalid number!" << endl;
        return 0;
    }

    if (number >= 2000) {cout << "MM"; number -= 2000;}
    if (number >= 1000) {cout <<  "M"; number -= 1000;}
    if (number >=  900) {cout << "CM"; number -=  900;}
    if (number >=  500) {cout <<  "D"; number -=  500;}
    if (number >=  400) {cout << "CD"; number -=  400;}
    if (number >=  200) {cout << "CC"; number -=  200;}
    if (number >=  100) {cout <<  "C"; number -=  100;}
    if (number >=   90) {cout << "XC"; number -=   90;}
    if (number >=   50) {cout <<  "L"; number -=   50;}
    if (number >=   40) {cout << "XL"; number -=   40;}
    if (number >=   20) {cout << "XX"; number -=   20;}
    if (number >=   10) {cout <<  "X"; number -=   10;}
    if (number >=    9) {cout << "IX"; number -=    9;}
    if (number >=    5) {cout <<  "V"; number -=    5;}
    if (number >=    4) {cout << "IV"; number -=    4;}
    if (number >=    2) {cout << "II"; number -=    2;}
    if (number >=    1) {cout <<  "I"; number -=    1;}

    cout << endl;
    return 0;
}
