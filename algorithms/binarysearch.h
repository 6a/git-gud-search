#pragma once

#include <vector>

namespace bs
{
    struct binarySearchTest
    {
        std::vector<int> collection;
        int targetValue;
        int expectedIndex;
    };

    // Search through a sorted vector and return the index of the target, or -1 if not found.
    // Will not provide accurate results for an unsorted array.
    //
    // This could be modified so that, instead of returning -1 when not found, it returns a boolean
    // and the actual index is returned as an out variable - this variable would contain the index
    // of the target when found, or the rank of the element (the index of the closest element).
    int binarySearch(const std::vector<int> &inVector, int target)
    {
        // Start with the default value, returned when the target is not found.
        int out = -1;

        // Early exit with the default value if the input vector is empty.
        if (inVector.size() == 0) return out;

        // Early exit by returning the only value in the input vector if its of size 1.
        if (inVector.size() == 1) return inVector[0];

        // Initial values.
        std::vector<int>::const_iterator low = inVector.begin();
        std::vector<int>::const_iterator mid = inVector.begin();
        std::vector<int>::const_iterator high = inVector.end();

        while (low <= high)
        {
            // Determine the middle element of the vector.
            mid = low + (high - low) / 2;

            if (target == *mid)
            {
                out = mid - inVector.begin();
                break;
            }
            else if (target < *mid)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return out;
    }

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

}
