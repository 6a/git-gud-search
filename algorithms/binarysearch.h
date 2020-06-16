#pragma once

#include <vector>
#include "..\utility\io.h"
#include "testcase.h"

namespace bs
{
    // Search through a sorted vector and return the index of the key, or -1 if not found.
    // Will not provide accurate results for an unsorted array.
    //
    // This could be modified so that, instead of returning -1 when not found, it returns a boolean
    // and the actual index is returned as an out variable - this variable would contain the index
    // of the key when found, or the rank of the element (the index of the closest element).
    int binary(const std::vector<int> &inVector, int key)
    {
        // Start with the default value, returned when the key is not found.
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

            if (key == *mid)
            {
                out = mid - inVector.begin();
                break;
            }
            else if (key < *mid)
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

    // Search through a sorted vector and return the index of the key, or -1 if not found.
    // Will not provide accurate results for an unsorted array.
    //
    // Recursive version of the standard binary search function.
    int binaryRecursive(const std::vector<int>& inVector, std::vector<int>::const_iterator& low, std::vector<int>::const_iterator& high, int key)
    {
        // Start with the default value, returned when the key is not found.
        int out = -1;

        if (low <= high)
        {
            std::vector<int>::const_iterator mid = low + (high - low) / 2;

            if (key == *mid)
            {
                out = mid - inVector.begin();
            }
            else if (key < *mid)
            {
                return binaryRecursive(inVector, low, mid - 1, key);
            }
            else
            {
                return binaryRecursive(inVector, mid + 1, high, key);
            }
        }

        return out;
    }

    // Runs binary search test functions. 
    // Returns -1 if all tests pass, else returns the index of the failed test.
    int testBinary(int testID)
    {
        std::cout << "\n" << testID << ". Binary Search:\n" << std::endl;

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
            int output = binary((*iter).collection, (*iter).key);
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

    // Runs recursive binary search test functions. 
    // Returns -1 if all tests pass, else returns the index of the failed test.
    int testBinaryRecursive(int testID)
    {
        std::cout << "\n" << testID << ". Binary Search:\n" << std::endl;

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
            search::testCase<int>{std::vector<int>{2, 44, 76, 231, 2454, 22214, 240129}, 240129, 6},

            search::testCase<int>{std::vector<int>{2, 44, 76, 111, 141, 175, 234, 554, 1022, 1224, 1245, 1341, 2999}, 1245, 10},
        };

        for (auto iter = cases.begin(); iter != cases.end(); ++iter)
        {
            int output = binaryRecursive((*iter).collection, (*iter).collection.begin(), (*iter).collection.end(), (*iter).key);
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
