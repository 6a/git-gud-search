#include "./utility/io.h"

#include "./algorithms/binarysearch.h"

int main()
{
    int binarySearchTestResult = bs::testBinarySearch(1);
    utility::outputResult("Binary Search", binarySearchTestResult);

    return 0;
}