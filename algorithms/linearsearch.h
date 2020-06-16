#pragma once

#include <vector>
#include "..\utility\io.h"
#include "testcase.h"

namespace ls
{
    // Search through a vector and return the index of the key, or -1 if not found.
    int linear(const std::vector<int> &inVector, int key)
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

        // Iterate and search. Early exit if found.
        for (std::vector<int>::const_iterator iter = inVector.begin(); iter != inVector.end(); ++iter)
        {
            if (*iter == key)
            {
                out = iter - inVector.begin();
                break;
            }
        }

        return out;
    }

    // Runs binary search test functions. 
    // Returns -1 if all tests pass, else returns the index of the failed test.
    int test(int testID)
    {
        std::cout << "\n" << testID << ". Linear Search:\n" << std::endl;

        int result = -1;
        size_t caseNumber = 0;

        std::vector<search::testCase<int>> cases
        {
            // Sorted set
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
            
            // Unsorted set
            search::testCase<int>{std::vector<int>{978, 948, 825, 646, 223, 266, 97, 667, 220, 239}, 266, 5},
            search::testCase<int>{std::vector<int>{149, 583, 304, 137, 317, 923, 72, 64, 245, 895}, 64, 7},
            search::testCase<int>{std::vector<int>{434, 531, 799, 65, 60, 941, 815, 58, 607, 949}, 949, 9},
            search::testCase<int>{std::vector<int>{989, 494, 58, 576, 14, 352, 310, 234, 533, 302}, 352, 5},
            search::testCase<int>{std::vector<int>{254, 26, 448, 248, 561, 670, 169, 614, 221, 129}, 254, 0},
            search::testCase<int>{std::vector<int>{576, 47, 903, 650, 873, 379, 441, 820, 265, 906}, 441, 6},
            search::testCase<int>{std::vector<int>{471, 916, 542, 197, 313, 85, 810, 430, 400, 186}, 400, 8},
            search::testCase<int>{std::vector<int>{97, 791, 660, 589, 691, 112, 737, 712, 165, 363}, 712, 7},
            search::testCase<int>{std::vector<int>{26, 984, 10, 972, 782, 121, 237, 545, 400, 436}, 10, 2},
            search::testCase<int>{std::vector<int>{993, 327, 301, 960, 283, 453, 655, 784, 707, 707}, 960, 3},

            search::testCase<int>{std::vector<int>{-26323, -32324, 40397, 82105, -36032, 50992, 71947, 7524, -2326, 14757}, -36032, 4},
            search::testCase<int>{std::vector<int>{84108, 98406, -94064, 49972, -27787, -40914, 6831, -18528, 99627, 10482}, 84108, 0},
            search::testCase<int>{std::vector<int>{-43137, 40261, 24503, -20990, -81615, 72851, -38058, 27929, 63189, -17241}, -17241, 9},
            search::testCase<int>{std::vector<int>{-22839, 97553, 65099, 63421, 20452, -2847, 23273, 13632, 5798, -89310}, 63421, 3},
            search::testCase<int>{std::vector<int>{-32581, -10921, -14156, -11665, 81165, -74811, 59691, 55805, -25478, -30413}, -74811, 5},
        };

        for (auto iter = cases.begin(); iter != cases.end(); ++iter)
        {
            int output = linear((*iter).collection, (*iter).key);
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
