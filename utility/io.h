#pragma once

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

        std::cout << resultStringStream.str() << std::endl;
    }
}
