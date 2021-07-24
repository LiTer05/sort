#include <iostream>
#include <vector>
#include <algorithm>

void countSort(std::vector<unsigned>& v)
{
    std::vector<unsigned>::iterator max;
    max = std::max_element(v.begin(), v.end());

    std::vector<unsigned> cVec;
    unsigned cVecSize = *max + 1;
    cVec.reserve(cVecSize);
    
    for(unsigned i = 0; i < cVecSize; ++i)
    {
        cVec.push_back(0);
    } 

    for(unsigned i = 0; i < v.size(); ++i)
    {
        cVec[v[i]] += 1;
    } 

    std::cout << "\nCountVector: ";
    
    for(unsigned i = 0; i < cVecSize; ++i)
    {
        std::cout << cVec[i] << " ";
    } 
    
    unsigned j = 0;
    for(unsigned i = 0; i < cVecSize; ++i)
    {
        while(cVec[i] != 0)
        {
            v[j] = i;
            cVec[i] -= 1;
            j += 1;
        }
        
    }

}


int main()
{
    std::cout << "Size of vector: ";
    unsigned n;
    std::cin >> n;

    std::vector<unsigned> v;
    unsigned number;
    do   
    {
        std::cin >> number;
        v.push_back(number);
    }
    while(v.size() != n);
       
    std::cout << "\nMy Vector: "; 
    for(unsigned i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << ' '; 
    }
    
    countSort(v);
    std::cout << "\nMy Sorted Vector: ";
    for(unsigned i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << ' '; 
    }
    std::cout << std::endl;          
    
    return 0;
}
