#include <iostream>

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void ShakerSort(int arr[], int size)
{
    int ii = 0;
    int j, k;
    int lb = 1, ub = size - 1;
    int x;
    do {
        k = 0;
        for (j = ub; j > 0; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(&arr[j], &arr[j - 1]);
                k = j;
            }
        }
        lb = k + 1;
        for (j = 1; j <= ub; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(&arr[j], &arr[j - 1]);
                k = j;
            }

            std::cout << ++ii << ") ";

            for (int i = 0; i < size; ++i)
                {
                    std::cout << arr[i] << ", ";
                }

            std::cout << std::endl;

        }
        ub = k - 1;
    } while (lb < ub);

    
}

int main()
{
    const int size = 10;
    const int N = 4;
    int arr[size];

    srand(time(nullptr));

    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % (20 * N) + 1;
    }

    std::cout << "Massive: " << std::endl;

    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << ", ";
    }

    std::cout << std::endl << "\nSorting:" << std::endl;

    ShakerSort(arr, size);

    std::cout << "\nSorted massive: " << std::endl;

    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << ", ";
    }

    return 0;
    system("pause");
}