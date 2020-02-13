#include "pch.h"
#include "Functions.h"

String ^
    toManaged(string inputString) {
        String ^ outputString = gcnew String(inputString.c_str());
        return outputString;
    }

    string toUnmannged(String ^ inputString)
{
    string outputString = marshal_as<std::string>(inputString);
    return outputString;
}
