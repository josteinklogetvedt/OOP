#include "utilities.h"
#include "Graph.h"
//Opg. 1
//a) Private - kun klassens egne medlemsfunksjoner, Protected - egne medlemsjunksjoner og 'derived class's members'
//   Public - alle kan nå de

string Animal::toString(){
    string s = "Animal: " + name + ", " + to_string(age);
    return s; 
}
string Dog::toString(){
    string s = "Dog: " + name + ", " + to_string(age);
    return s;
}
string Cat::toString(){
    string s = "Cat: " + name + ", " + to_string(age);
    return s;
}

void testAnimal(){
    Cat cat{"Arne", 25};
    Dog dog{"John", 40};
    //Animal ani{"Ani", 17};       //Animal er nå en abstakt klasse
    cout << cat.toString() << "\n" << dog.toString() << "\n" << endl; //ani.toString() << endl;

    using namespace Graph_lib;
    Vector_ref<Animal> vec;
    vec.push_back(cat);
    vec.push_back(dog);
    //vec.push_back(ani);
    for (int i=0; i<vec.size(); ++i){
        cout << vec[i].toString() << endl;     //Når jeg fjerner virtual i Animal klassen vil ikke toString() i Dog og Cat 
    }                                          // 'override' funksjonen i Animal så den skriver "Animal: osv."
}

