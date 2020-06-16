#include "./utility/io.h"

#include "./algorithms/binarysearch.h"
#include "./algorithms/linearsearch.h"

int main()
{
    utility::outputResult("Binary Search", bs::testBinary(1));

    utility::outputResult("Binary Search (Recursive)", bs::testBinaryRecursive(2));

    utility::outputResult("Linear Search", ls::testLinear(3));

    return 0;
}