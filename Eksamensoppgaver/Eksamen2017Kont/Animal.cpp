#include "Animal.h"

std::ostream & operator<<(std::ostream & out, Animal &a) {
    return out << a.toString();
}

Animal* parseAnimal(string line){
    stringstream ss{line};
    Animal* ptr = nullptr;
    string name, the, type, is, age;
    ss >> name >> the >> type >> is >> age;
    if (type == "Human"){
        ptr = new Human{name, stoi(age)};
    }else if(type == "Dog"){
        string and, color;
        ss >> and >> color;
        ptr= new Dog{name, stoi(age), color};
    }
    return ptr;
}

void parseFriends(map<string, Animal*> &animals, string line){
    stringstream ss{line};
    string name1, and, name2;
    ss >> name1 >> and >> name2;
    if (animals.find(name1) == animals.end() || animals.find(name2) == animals.end()){
        cout << "Could not parse animals. Didn't find names in animals-map.";
        return;
    }else{
        animals[name1] -> addFriend(animals[name2]);
        animals[name2] -> addFriend(animals[name1]);
    }
}

map<string, Animal *> readAnimals(string filename){
    ifstream ist{filename};
    if (!ist){
        throw invalid_argument("Could not open file.");
    }
    string line;
    map<string, Animal*> animals;
    while (getline(ist,line)){
        stringstream ss{line};
        string name, word;
        ss >> name >> word;
        if (word == "the"){
            Animal* ani = parseAnimal(line);
            if (ani){
                animals[name] = ani;
            }
        }else if(word == "and"){
            parseFriends(animals,line);
        }
    }
    return animals;
}