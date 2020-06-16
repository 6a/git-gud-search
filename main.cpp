#include "./utility/io.h"

#include "./algorithms/binarysearch.h"
#include "./algorithms/linearsearch.h"
#include "./algorithms/jumpsearch.h"

int main()
{
    utility::outputResult("Binary Search", bs::test(1));

    utility::outputResult("Binary Search (Recursive)", bs::testRecursive(2));

    utility::outputResult("Linear Search", ls::test(3));
    
    utility::outputResult("Jump Search", js::test(4));

    return 0;
}