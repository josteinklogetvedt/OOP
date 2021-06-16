#include "foodPrices.h"

bool operator<(const Food& lhs, const Food& rhs){
    return lhs.price < rhs.price;
}

void addPrice(map<string, set<Food>>& db, Food fp){
    db[fp.name].insert(fp);
}

void printAllPrices(const map<string,set<Food>>& db){
    for (auto p : db){
        cout << p.first << ":" << endl;
        for (auto f : p.second){
            cout << f.price << " " << f.where << endl;
        }
    }
}

void bestPrice(const map<string,set<Food>>& db, string name){
    auto it = db.find(name);
    if (it == db.end()){
        cout << "No price for " << name << endl;
    }else{
        cout << "Best price for " << name << " is " << it->second.begin()->price << " at " << it->second.begin()->where << endl;
    }
}