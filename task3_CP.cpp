#include <iostream>
using namespace std;

float taxCalculator(char, float);

main()
{
    float price;
    char type;
    float result;

    cout << "Enter type of vehicle: ";
    cin >> type;
    cout << "Enter price: ";
    cin >> price;

    result = taxCalculator(type, price);

    cout << "Final Price of " << type << " type vehicle with tax amount is: " << result << endl;
}
float taxCalculator(char type, float price)
{
    float tax;
    float finalPrice;

    if (type == 'M')
    {
        tax = (price * 6) / 100;
        finalPrice = price + tax;
        return finalPrice;
    }
    if (type == 'E')
    {
        tax = (price * 8) / 100;
        finalPrice = price + tax;
        return finalPrice;
    }
    if (type == 'S')
    {
        tax = (price * 10) / 100;
        finalPrice = price + tax;
        return finalPrice;
    }
    if (type == 'V')
    {
        tax = (price * 12) / 100;
        finalPrice = price + tax;
        return finalPrice;
    }
    if (type == 'T')
    {
        tax = (price * 15) / 100;
        finalPrice = price + tax;
        return finalPrice;
    }
}