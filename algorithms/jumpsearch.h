#pragma once

#include <vector>
#include "..\utility\io.h"
#include "testcase.h"

namespace js
{
    // Search through a sorted vector and return the index of the key, or -1 if not found.
    // Will not provide accurate results for an unsorted array.
    int jump(const std::vector<int> &inVector, int key)
    {
        // Start with the default value, returned when the key is not found.
        int out = -1;

        // Early exit with the default value if the input vector is empty.
        if (inVector.size() == 0) return out;

        // Early exit by returning the only value in the input vector if its of size 1.
        if (inVector.size() == 1) return inVector[0];

        // Determine the block (jump) size.
        size_t step = std::sqrt(inVector.size());

        // Create an iterator that we will use for stepping, as well as linearly searching later.
        auto iter = inVector.begin();

        // Find the block in which which the key resides.
        while (*iter <= key && iter < inVector.end())
        {
            std::advance(iter, step);
        }

        // Store the last iter, that represents the start of the next block.
        auto last = iter;

        // Rewind the iterator by one step.
        std::advance(iter, -step);

        // Perform a linear search from the start of the previous block.
        for (iter; iter < last; iter = std::next(iter))
        {
            if (*iter == key)
            {
                out = std::distance(inVector.begin(), iter);
                break;
            }
        }

        return out;
    }

    // Runs binary search test functions. 
    // Returns -1 if all tests pass, else returns the index of the failed test.
    int test(int testID)
    {
        std::cout << "\n" << testID << ". Jump Search:\n" << std::endl;

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
            int output = jump((*iter).collection, (*iter).key);
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
