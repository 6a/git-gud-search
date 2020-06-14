#include "./utility/io.h"

#include "./algorithms/binarysearch.h"

int main()
{
    utility::outputResult("Binary Search", bs::testBinarySearch(1));

    utility::outputResult("Binary Search", bs::testResursiveBinarySearch(2));

    return 0;
}