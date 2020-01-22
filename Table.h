#pragma once
class Table {
public:
  Table(string newName);
  void addOrder(string itemName, int itemPrice);
  vector<pair<string, int>> getOrder();
  void deleteOrder();

  static vector<Table> tablesVector;
  static vector<pair<string, int>> tempTableOrder;
  string getTableName();

private:
  vector<pair<string, int>> tableOrder;
  string name;
};
