#include <iostream>
#include <string>
#include <list>

struct AEROFLOT
{
    std::string CITY, TYPE;
    int NUM;
};

class Stack
{
private:
    std::list<AEROFLOT> data;

public:
    void PushBack(const AEROFLOT& item)
    {
        data.push_back(item);
    }

    void PopBack()
    {
        if (!data.empty())
        {
            data.pop_back();
        }
        else
        {
            std::cout << "Stack is empty" << std::endl;
        }
    }

    AEROFLOT top() const
    {
        if (!data.empty())
        {
            return data.back();
        }
        else
        {
            std::cerr << "Stack is empty" << std::endl;
            exit(1);
        }
    }

    bool IsEmpty() const
    {
        return data.empty();
    }
};

void InformationInput(Stack& a)
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
        a.PushBack(plane);
    }
}

void InformationOutput(Stack& a, std::string& b)
{
    int c = 0;
    std::cout << "\nPlanes to: " << b << std::endl;
    Stack tempStack;
    while (!a.IsEmpty())
    {
        AEROFLOT n = a.top();
        a.PopBack();
        if (n.CITY == b)
        {
            std::cout << "Destination: " << n.CITY << ", Type of aircraft: " << n.TYPE << ", Flight number: " << n.NUM << std::endl;
            c++;
        }
        tempStack.PushBack(n);
    }
    while (!tempStack.IsEmpty())
    {
        AEROFLOT n = tempStack.top();
        tempStack.PopBack();
        a.PushBack(n);
    }
    
    if (c == 0)
    {
        std::cout << "There are no planes" << std::endl;
    }
}

void AllInformationOutput(Stack& a)
{
    std::cout << "\nAll planes information:" << std::endl;
    Stack tempStack;
    while (!a.IsEmpty())
    {
        AEROFLOT n = a.top();
        a.PopBack();
        std::cout << "Destination: " << n.CITY << ", Type of aircraft: " << n.TYPE << ", Flight number: " << n.NUM << std::endl;
        tempStack.PushBack(n);
    }
    while (!tempStack.IsEmpty())
    {
        AEROFLOT n = tempStack.top();
        tempStack.PopBack();
        a.PushBack(n);
    }
}

void Add(Stack& a)
{
    AEROFLOT newplane;
    std::cout << "\nEnter info for the new plane:\n";
    std::cout << "Enter destination: ";
    std::cin >> newplane.CITY;
    std::cout << "Enter type of aircraft: ";
    std::cin >> newplane.TYPE;
    std::cout << "Enter flight number: ";
    std::cin >> newplane.NUM;
    a.PushBack(newplane);
}

void Delete(Stack& a, int n)
{
    Stack Temporary;
    while (!a.IsEmpty())
    {
        AEROFLOT p = a.top();
        a.PopBack();
        if (p.NUM != n)
        {
            Temporary.PushBack(p);
        }
    }
    while (!Temporary.IsEmpty())
    {
        AEROFLOT n = Temporary.top();
        Temporary.PopBack();
        a.PushBack(n);
    }
}

int main()
{
    int NumDelete;
    std::string Destination;

    Stack planes;

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