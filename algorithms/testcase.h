#include <vector>

namespace search
{
    template<class T>
    struct testCase
    {
        std::vector<T> collection;
        int targetValue;
        int expectedIndex;
    };  
} 
