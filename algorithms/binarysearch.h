#pragma once

#include <vector>

// Search through a sorted vector and return the index of the target, or -1 if not found.
// Will not provide accurate results for an unsorted array.
int binarySearch(std::vector<int>& inVector, int target)
{
    // Start with the default value, returned when the target is not found.
    int out = -1;

    // Early exit with the default value if the input vector is empty.
    if (inVector.size() == 0) return out;

    // Early exit by returning the only value in the input vector if its of size 1.
    if (inVector.size() == 1) return inVector[0];

    // Initial values.
    std::vector<int>::iterator low = inVector.begin();
    std::vector<int>::iterator mid = inVector.begin();
    std::vector<int>::iterator high = inVector.end();

    // be
    while (low <= high)
    {
        // Determine the middle element of the vector.
        mid = low + (high - low) / 2;

        if (target == *mid)
        {
            out = *mid;
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