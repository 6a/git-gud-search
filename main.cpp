#include "./utility/io.h"

#include "./algorithms/binarysearch.h"

int main()
{
    utility::outputResult("Binary Search", bs::testBinary(1));

    utility::outputResult("Binary Search", bs::testBinaryRecursive(2));

    return 0;
}