#pragma once
#include "std_lib_facilities.h"

struct Food{
    string name;
    double price;
    string where;
};

bool operator<(const Food& rhs, const Food& lhs);
void addPrice(map<string, set<Food>>& db, Food fp);
void printAllPrices(const map<string, set<Food>>& db);
void bestPrice(const map<string, set<Food>>& db, string name);