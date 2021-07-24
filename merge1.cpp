#include <iostream>

void Merge(int* arr, int s, int m, int e) // Start Midle End
{
//create
    int n1 = m - s + 1;         // s ...  m - 1 
    int n2 = e - m;        // m   ...  e - 1 
    std::cout << n1 << " " << n2 << std::endl;
    int* l = new int[n1];
    int* r = new int[n2];
//init
    for (int i = 0; i < n1; ++i)
    {
        l[i] = arr[s + i];
    }    
    for (int j = 0; j < n2; ++j)
    {
        r[j] = arr[m + 1 + j];
    } 

   
//merge

    int i = 0, j = 0, k = s;
    while (i < n1 && j < n2)
    {
        if (l[i] <= r[j])
        { 
            arr[k] = l[i];
            i++;
        }
        else
        {
            arr[k] = r[j];
            j++;
        } 
        k++;
    } 
    
    while (i < n1)
    {
        arr[k] = l[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = r[j];
        i++;
        k++;
    }


//clear
    delete [] l;
    delete [] r;

}

void MergeSort(int* arr, int s, int e)
{
    if (s < e)
    {
        int m = (s + e ) / 2;
        MergeSort(arr, s, m);
        MergeSort(arr, m + 1 , e);
        Merge(arr, s, m, e);
    }
}
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
    for (int i = 0; i < n; ++i)
    {
        std::cin >> p[i];
    }
//sort
    MergeSort(p, 0, n - 1);  

//output
    for (int i = 0; i < n; ++i)
    {
        std::cout << p[i] << ' ';
    }
    
    delete[] p;
    return 0;
}
