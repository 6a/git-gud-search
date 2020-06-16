#pragma once

#include <vector>
#include <iostream>
#include <sstream>

namespace utility
{
    // Prints the formatted result of the test named "test" to the std output stream.
    void outputResult(std::string test, int result)
    {
        std::stringstream resultStringStream;

        std::cout << "Test \"" << test << "\": [ ";

        if (result == -1)
        {
            resultStringStream << "passed ]";
        }
        else
        {
            resultStringStream << "failed on test " << result << " ]";
        }

        std::cout << resultStringStream.str() << "\n" << std::endl;
    }

    // Reports a failure
    template<class T>
    void reportFailure(std::vector<T> collection, int expected, int actual)
    {
        std::stringstream collectionString;
        collectionString << "[ ";

        for (std::vector<T>::const_iterator iter = collection.begin(); iter != collection.end(); ++iter)
        {
            collectionString << *iter;

            if (std::next(iter) != collection.end())
            {
                collectionString << ", ";
            }
        }

        collectionString << " ]";

        std::cout << "Test failed for collection: " << collectionString.str() << "\nExpected: [ " << expected << " ]\nActual: [ " << actual << " ]\n" << std::endl;
    }
}
