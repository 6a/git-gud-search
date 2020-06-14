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
}
