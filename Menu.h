#pragma once
#include "pch.h"
class Menu {
public:
  string getName();
  int getPrice();
  bool getvisible();
  static vector<pair<string, int>> menuVector;

protected:
  string name;
  int price;
  bool visible;
};
