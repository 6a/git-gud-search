#pragma once

#include <vector>
#include <algorithm>
#include "..\utility\io.h"
#include ".\binarysearch.h"
#include "testcase.h"

namespace es
{
    // Search through a sorted vector and return the index of the key, or -1 if not found.
    // Will not provide accurate results for an unsorted array.
    int exponential(const std::vector<int> &inVector, int key)
    {
        // Start with the default value, returned when the key is not found.
        int out = -1;

        // Early exit with the default value if the input vector is empty.
        if (inVector.size() == 0) return out;

        // Early exit by returning the only value in the input vector if its of size 1.
        if (inVector.size() == 1) 
        {
            if (inVector[0] == key)
            {
                return 0;
            }
            else
            {
                return out;
            }
        }

        // Early exit if the first element matches the key
        if (inVector[0] == key) return 0; 

        // Find the range for the binary search by doubling until we exceed the key value.
        size_t index = 1;
        while (index < inVector.size() && inVector[index] <= key)
        {
            index *= 2;
        }

        // Create an iterator that will serve as the low value.
        std::vector<int>::const_iterator low = inVector.begin();

        // Set the low iterator to start of the previous range
        std::advance(low, index / 2);

        // Create an iterator that will serve as the high value.
        std::vector<int>::const_iterator high = inVector.begin();

        // Set the high iterator to start of the current range, or the last value - whichever is lowest.
        // The min check prevents overflow.
        std::advance(high, std::min(index, inVector.size() - 1));

        // Make use of the recursive binary search to search through the range.
        return bs::binaryRecursive(inVector, low, high, key);
    }

    // Runs binary search test functions. 
    // Returns -1 if all tests pass, else returns the index of the failed test.
    int test(int testID)
    {
        std::cout << "\n" << testID << ". Exponential Search:\n" << std::endl;

        int result = -1;
        size_t caseNumber = 0;

        std::vector<search::testCase<int>> cases
        {
            search::testCase<int>{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 1, 0},
            search::testCase<int>{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 2, 1},
            search::testCase<int>{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 2},
            search::testCase<int>{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 4, 3},
            search::testCase<int>{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 4, 3},
            search::testCase<int>{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 5, 4},
            search::testCase<int>{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 6, 5},
            search::testCase<int>{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 7, 6},
            search::testCase<int>{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 8, 7},
            search::testCase<int>{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 9, 8},

            search::testCase<int>{std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 3, 2},

            search::testCase<int>{std::vector<int>{2, 44, 76, 231, 2454, 22214, 240129}, 44, 1},
            search::testCase<int>{std::vector<int>{2, 44, 76, 231, 2454, 22214, 240129}, 2454, 4},
        };

        for (auto iter = cases.begin(); iter != cases.end(); ++iter)
        {
            int output = exponential((*iter).collection, (*iter).key);
            bool pass = output == (*iter).expectedIndex;

            if (!pass)
            {
                result = caseNumber;
                utility::reportFailure((*iter).collection, (*iter).expectedIndex, output);

                break;
            }

            ++caseNumber;
        }
        
        return result;
    }
}
