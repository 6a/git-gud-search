#include "./utility/io.h"

#include "./algorithms/binarysearch.h"

// Runs binary search test functions. 
// Returns -1 if all tests pass, else returns the index of the failed test.
int testBinarySearch(int testID)
{
    std::cout << "\n" << testID << ". Binary Search:\n" << std::endl;

    int result = -1;
    size_t caseNumber = 0;

    std::vector<bs::binarySearchTest> cases
    {
        bs::binarySearchTest{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 1, 0},
        bs::binarySearchTest{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 2, 1},
        bs::binarySearchTest{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 2},
        bs::binarySearchTest{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 4, 3},
        bs::binarySearchTest{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 4, 3},
        bs::binarySearchTest{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 5, 4},
        bs::binarySearchTest{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 6, 5},
        bs::binarySearchTest{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 7, 6},
        bs::binarySearchTest{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 8, 7},
        bs::binarySearchTest{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 9, 8},

        bs::binarySearchTest{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 3, 2},

        bs::binarySearchTest{std::vector<int>{2, 44, 76, 231, 2454, 22214, 240129}, 44, 1},
        bs::binarySearchTest{std::vector<int>{2, 44, 76, 231, 2454, 22214, 240129}, 2454, 4},
    };

    for (auto iter = cases.begin(); iter != cases.end(); ++iter)
    {
        int output = bs::binarySearch((*iter).collection, (*iter).targetValue);
        bool pass = output == (*iter).expectedIndex;

        if (!pass)
        {
            result = caseNumber;
            utility::reportFailure((*iter).expectedIndex, output);

            break;
        }

        ++caseNumber;
    }
    

    return result;
}

int main()
{
    int binarySearchTestResult = testBinarySearch(1);
    utility::outputResult("Binary Search", binarySearchTestResult);

    return 0;
}