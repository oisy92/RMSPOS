#include "pch.h"
#include "Functions.h"

String ^ toManaged(string inputString) {
    String ^ tableName = gcnew String(inputString.c_str());
    return tableName;
}
