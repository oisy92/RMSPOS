#pragma once
#include "pch.h"
class Menu {
public:
  string getName() const;
  int getPrice() const;
  bool getvisible() const;
  static vector<pair<string, int>> menuVector;

protected:
  string name;
  int price;
  bool visible;
};
