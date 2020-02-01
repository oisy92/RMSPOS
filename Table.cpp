#include "pch.h"
#include "Table.h"


Table::Table(string newName) { name = newName; }

void Table::addOrder(string itemName, int itemPrice) {
  tableOrder.push_back(make_pair(itemName, itemPrice));
}

vector<pair<string, int>> Table::getOrder() { return tableOrder; }

void Table::deleteOrder() { tableOrder.clear(); }

string Table::getTableName() const { return name; }
