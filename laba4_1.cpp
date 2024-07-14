#include <iostream>
#include <string>

struct AEROFLOT
{
    std::string CITY, TYPE, NUM;
    //int NUM;
};

void TrainDataFillInformation(AEROFLOT a[], int N)
{
    int i = 0;
    for (i = 0; i < N; ++i)
    {
        std::cout << "\nEnter info for plane number: " << i + 1 << std::endl;
        std::cout << "Enter destination: ";
        std::cin >> a[i].CITY;
        std::cout << "Enter type of aircraft: ";
        std::cin >> a[i].TYPE;
        std::cout << "Enter flight number: ";
        std::cin >> a[i].NUM;
    }
}

void InformationOutput(AEROFLOT a[], std::string b, int N)
{
    int c = 0;
    std::cout << "\nPlanes to: " << b << std::endl;
    for (int i = 0; i < N; ++i)
    {
        if (a[i].CITY == b)
        {
            std::cout << "Plane number: " << a[i].NUM << ", Type of aircraft: " << a[i].TYPE;
            c++;
        }
    }
    if (c == 0)
    {
        std::cout << "There's no planes" << std::endl;
    }
}

int main()
{
    int N;
    std::cout << "Enter number of planes: ";
    std::cin >> N;

    AEROFLOT* a = new AEROFLOT[N];

    TrainDataFillInformation(a, N);

    std::string b;
    std::cout << "\nEnter destination: ";
    std::cin >> b;

    InformationOutput(a, b, N);

    return 0;
}