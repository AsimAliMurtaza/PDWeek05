#include <iostream>
using namespace std;

float pyramidVolume(float, float, float, string);
main()
{
    float length;
    float width;
    float height;
    string unit;
    float result;

    cout << "Enter Length: ";
    cin >> length;
    cout << "Enter Width: ";
    cin >> width;
    cout << "Enter height: ";
    cin >> height;
    cout << "Enter unit in lower case: ";
    cin >> unit;

    result = pyramidVolume(length, width, height, unit);

    cout << "Volume of pyramid is= " << result << endl;

}

float pyramidVolume(float length, float width, float height, string unit)
{


    if (unit == "millimeters")
    {
        float totalVolume;
        totalVolume = ((length * width * height) / 3) * 1000000000; 
        return totalVolume; 
    }
    if (unit == "centimeters")
    {
        float totalVolume;
        totalVolume = ((length * width * height) / 3) * 1000000; 
        return totalVolume; 
    }
        if (unit == "kilometers")
    {
        float totalVolume;
        totalVolume = ((length * width * height) / 3) / 1000000000; 
        return totalVolume; 
    }
}