#include "LinkedListTemplate.h"

void testLinkedListTemplate(){
    using namespace LinkedListTemplate; 
    LinkedList<int> link;
    
    auto ptr42 = link.insert(link.end(),42);
    link.insert(link.end(),43);     
    link.insert(link.begin(),1);    
    link.insert(ptr42,2);             

    std::cout << link << std::endl;
    
    auto ptr43 = link.remove(ptr42);    //Gir peker på elementet bak det som blir fjernet
    std::cout << *ptr43 << std::endl;
    ptr43 = link.remove(ptr43);         //Gir peker på tail med null som verdi
    std::cout << *ptr43 << std::endl;
    ptr43 = link.insert(ptr43, 43);     //peker igjen på 43, bakerst i listen
    std::cout << link << std::endl;
 
    link.remove(2);
    std::cout << link << std::endl;   
}
