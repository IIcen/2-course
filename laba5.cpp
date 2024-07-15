#include <iostream>
#include <string>
#include <list>

struct AEROFLOT
{
    std::string CITY, TYPE;
    int NUM;
};

void InformationInput(std::list<AEROFLOT>& a)
{
    int N;
    std::cout << "Enter number of planes: ";
    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        AEROFLOT plane;
        std::cout << "\nEnter info for plane number: " << i + 1 << std::endl;
        std::cout << "Enter destination: ";
        std::cin >> plane.CITY;
        std::cout << "Enter type of aircraft: ";
        std::cin >> plane.TYPE;
        std::cout << "Enter flight number: ";
        std::cin >> plane.NUM;
        a.push_back(plane);
    }
}

void InformationOutput(std::list<AEROFLOT>& a, std::string& b)
{
    int c = 0;
    std::cout << "\nPlanes to: " << b << std::endl;
    for (auto& n : a)
    {
        if (n.CITY == b)
        {
            std::cout << "Destination: " << n.CITY << ", Type of aircraft: " << n.TYPE << ", Flight number: " << n.NUM << std::endl;
            c++;
        }
    }
    if (c == 0)
    {
        std::cout << "There are no planes" << std::endl;
    }
}

void AllInformationOutput(std::list<AEROFLOT>& a)
{
    std::cout << "\nAll planes information:" << std::endl;
    for (auto& n : a)
    {
        std::cout << "Destination: " << n.CITY << ", Type of aircraft: " << n.TYPE << ", Flight number: " << n.NUM << std::endl;
    }
}

void Add(std::list<AEROFLOT>& a)
{
    AEROFLOT newplane;
    std::cout << "\nEnter info for the new plane:\n";
    std::cout << "Enter destination: ";
    std::cin >> newplane.CITY;
    std::cout << "Enter type of aircraft: ";
    std::cin >> newplane.TYPE;
    std::cout << "Enter flight number: ";
    std::cin >> newplane.NUM;
    a.push_back(newplane);
}

void Delete(std::list<AEROFLOT>& a, int n)
{
    auto c = a.begin();
    while (c != a.end())
    {
        if (c->NUM == n)
        {
            c = a.erase(c);
        }
        else
        {
            ++c;
        }
    }
}

int main()
{
    int NumDelete;
    std::string Destination;

    std::list<AEROFLOT> planes;

    InformationInput(planes);

    AllInformationOutput(planes);

    Add(planes);

    std::cout << "\nEnter plane destination to see information about it: ";
    std::cin >> Destination;
    InformationOutput(planes, Destination);

    std::cout << "\nEnter plane number to delete information about it: ";
    std::cin >> NumDelete;
    Delete(planes, NumDelete);

    AllInformationOutput(planes);

    return 0;
}