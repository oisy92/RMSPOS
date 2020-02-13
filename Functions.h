#pragma once
#include "pch.h"
using namespace System;
using namespace msclr::interop;

String ^ toManaged(string inputString);

string toUnmannged(String ^ inputString);
