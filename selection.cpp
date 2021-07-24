#include <iostream>

int main()
{
//input
    int n;
    do
    {
        std::cout << "Զանգվածի տարրերի քանակը․ \n n = ";
        std::cin >> n; 
    }
    while (n <= 0);

    int *p = new int[n];
    for(int i =  0; i < n; ++i)
    {
        std::cout << i << ": ";
        std::cin >> p[i];
    }

//sort
    for(int i = 0; i < n - 1; ++i)
    {
        int min = p[i];
        int minInd = i; //Ind - Index
        for(int j = i + 1; j < n; ++j)
        {
            if (p[j] < min)
            {
                min = p[j];
                minInd = j;
            }
        }
        p[minInd] = p[i];
        p[i] = min;    
    }


//output
    for(int i = 0; i < n; ++i)
    {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;   

//clean
    delete[] p;
}
