#include "pch.h"
#include "Table.h"

Table::Table(string newName)
{
    name = newName;
}

void Table::addOrder(string itemName, int itemPrice)
{
    tableOrder.push_back(make_pair(itemName, itemPrice));
}

vector<pair<string, int>> Table::getOrder()
{
    return tableOrder;
}

void Table::deleteOrder()
{
    tableOrder.clear();
}

int Table::getOrderSum()
{
    int orderSum = 0;
    vector<pair<string, int>>::iterator iterTempTableOrder, endTempTableOrder;
    for (iterTempTableOrder = tableOrder.begin(), endTempTableOrder = tableOrder.end();
         iterTempTableOrder != endTempTableOrder; ++iterTempTableOrder)
    {
        orderSum += iterTempTableOrder->second;
    }
    return orderSum;
}

string Table::getTableName() const
{
    return name;
}
