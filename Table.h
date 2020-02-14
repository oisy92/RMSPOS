#pragma once
class Table
{
  public:
    Table(string newName);
    void addOrder(string itemName, int itemPrice);
    vector<pair<string, int>> getOrder();
    void deleteOrder();
    int getOrderSum();

    static vector<Table> tablesVector;
    static vector<pair<string, int>> tempTableOrder;
    static string activeTable;
    string getTableName() const;

  private:
    vector<pair<string, int>> tableOrder;
    string name;
};
