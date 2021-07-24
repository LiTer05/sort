#include <iostream>

int main()
{
//input    

    int n;
    do
    {
        std::cout << "Զանգվածի տարրերի քանակը․ \n  n = ";
        std::cin >> n;
    }
    while(n <= 0);
    
    int *p = new int[n];
    for(int i = 0; i < n; ++i)
    {
        std::cout << i << ": ";
        std::cin >> p[i];
    }    
//sort
    for(int i = 1; i < n; i++)
    {
        
        int key = p[i];
        int j = i - 1;
        
        while ((p[j] > key) && (j > -1))
        {
                p[j + 1] = p[j];
                j = j - 1;
        }
     
       p[j + 1] = key;   
    }    

//output
    for(int i = 0; i < n; ++i)
    {
        std::cout << p[i] << ' ';
    }
    std::cout << std::endl;   
 
//clean
    delete[] p;

return 0;
}
