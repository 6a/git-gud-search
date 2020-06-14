#include "./utility/io.h"

#include "./algorithms/binarysearch.h"

// Runs binary search test functions. 
// Returns -1 if all tests pass, else returns the index of the failed test.
int testBinarySearch()
{
    int result = -1;
    std::vector<std::vector<int>> cases
    {
        
    };

    return result;
}

int main()
{
    int binarySearchTestResult = testBinarySearch();
    utility::outputResult("Binary Search", binarySearchTestResult);

    return 0;
}