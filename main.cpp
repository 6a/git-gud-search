#include "./utility/io.h"

#include "./algorithms/binarysearch.h"

// Runs binary search test functions. 
// Returns -1 if all tests pass, else returns the index of the failed test.
int testBinarySearch()
{
    int result = -1;
    size_t caseNumber = 0;

    std::vector<bs::binarySearchTest> cases
    {
        bs::binarySearchTest{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 4, 3},
    };

    for (auto iter = cases.begin(); iter != cases.end(); ++iter)
    {
        bool pass = bs::binarySearch((*iter).collection, (*iter).targetValue) == (*iter).expectedIndex;

        if (!pass)
        {
            result = caseNumber;
            
            break;
        }

        ++caseNumber;
    }
    

    return result;
}

int main()
{
    int binarySearchTestResult = testBinarySearch();
    utility::outputResult("Binary Search", binarySearchTestResult);

    return 0;
}