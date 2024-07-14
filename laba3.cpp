#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <string>

int find_el(int* arr, int count, int element)
{
    for (int i = 0; i < count; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }

    return -1;
}

int KMPSearch(char* string, char* substring)
{
    int sl, ssl;
    int res = -1;
    sl = strlen(string);
    ssl = strlen(substring);

    if (sl == 0)
    {
        std::cout << "Invalid string input\n";
    }
    else if (ssl == 0)
    {
        std::cout << "Invalid substring input\n";
    }
    else
    {
        int i, j = 0, k = -1;
        int* d;
        d = new int[ssl];
        d[0] = -1;

        while (j < ssl - 1)
        {
            while (k >= 0 && substring[j] != substring[k])
                k = d[k];
            j++;
            k++;
            if (substring[j] == substring[k])
                d[j] = d[k];
            else
                d[j] = k;
        }
        i = 0;
        j = 0;

        while (j < ssl && i < sl)
        {
            while (j >= 0 && string[i] != substring[j])
                j = d[j];
            i++;
            j++;
        }
        delete[] d;

        res = j == ssl ? i - ssl : -1;
    }

    return res;
}

int DirectSearch(char* string, char* substring)
{
    int sl, ssl;
    int res = -1;
    sl = strlen(string);
    ssl = strlen(substring);
    if (sl == 0)
        std::cout << "Invalid string input\n";
    else if (ssl == 0)
        std::cout << "Invalid substring input\n";
    else
        for (int i = 0; i < sl - ssl + 1; i++)
            for (int j = 0; j < ssl; j++)
                if (substring[j] != string[i + j])
                    break;
                else if (j == ssl - 1)
                {
                    res = i;
                    break;
                }

    return res;
}

int main()
{
    srand(unsigned int(0));
    int arr[5000];

    for (int i = 0; i < 5000; i++)
    {
        arr[i] = rand() % 1201 - 200;
         
    }

    int element = 845;
    int index = find_el(arr, 5000, element);
    if (index != -1)
    {
        std::cout << "Element " << element << " found at index: " << index << std::endl;
    }
    else
    {
        std::cout << "Element " << element << " not found" << std::endl;
    }

    char str[300];
    for (int i = 0; i < 300; i++)
    {
        char ch = 'a' + rand() % 26;
        str[i] = ch;

        //std::cout << i << ") " << str[i] << std::endl;
    }

    std::cout << "\nString: ";

    for (int i = 0; i < 300; i++) {
        if (i % 50 == 0) {
            std::cout << std::endl;
        }

        std::cout << str[i];
    }

    char substring[] = "j";
    int found_pos = KMPSearch(str, substring);
    std::cout << "\n\nSubstring: " << substring << std::endl;

    if (found_pos != -1)
    {
        std::cout << "\nSubstring found at index: " << found_pos << std::endl;
    }
    else
    {
        std::cout << "\nSubstring not found" << std::endl;
    }
    return 0;
}