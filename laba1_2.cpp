#include <iostream>

#define N 10

void Sort(int A[])
{
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = 0; j < N - i - 1; ++j)
        {
            if (A[j] > A[j + 1])
            {
                std::swap(A[j], A[j + 1]);
            }
        }
    }
}

int main()
{
    int A[N];

    srand(time(nullptr));

    for (int i = 0; i < N; ++i)
    {
        A[i] = rand() % 100;
    }

    std::cout << "Massive: " << std::endl;

    for (int i = 0; i < N; ++i)
    {
        std::cout << A[i] << " ";
    }

    Sort(A);

    std::cout << "\nSorted massive: " << std::endl;

    for (int i = 0; i < N; ++i)
    {
        std::cout << A[i] << " ";
    }

    return 0;
    system("pause");
}