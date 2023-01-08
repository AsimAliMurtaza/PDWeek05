#include <iostream>
using namespace std;

void firm(int, int, int);

main()
{
    int hours;
    int days;
    int workers;

    cout << "Enter needed hours: ";
    cin >> hours;
    cout << "Enter days: ";
    cin >> days;
    cout << "Enter number of workers: ";
    cin >> workers;

    firm(hours, days, workers); 
}

void firm(int hours, int days, int workers)
{
   int hourTotal = days * 10;
   int hourAfterBreak = hourTotal * 0.1;
   int hourTotalAfterBreak = hourTotal - hourAfterBreak;
   int hourWorkerFinal = hourTotalAfterBreak * workers;
   int hourFinal = hourWorkerFinal - hours;
   int hourFinal2 = hours - hourWorkerFinal;


    if (hourWorkerFinal > hours)
    {
        cout <<"Yes! " << hourFinal << " hours left.";
    }
    if (hourWorkerFinal < hours)
    {
        cout << "Not enough time! " << hourFinal2 << " hours are needed.";
    }
}