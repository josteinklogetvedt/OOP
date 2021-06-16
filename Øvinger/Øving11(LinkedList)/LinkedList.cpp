#include "LinkedList.h"

namespace LinkedList{

std::ostream& operator<<(std::ostream & os, const Node& node){
    os << node.value;
    return os;
}

Node* LinkedList::insert(Node* pos, const std::string& value){
    Node* temp;
    if (pos == begin()){
        head = std::make_unique<Node>(value, std::move(head), nullptr);
        pos->prev = begin();
        temp = head.get();
    }else{
        std::unique_ptr<Node> newNode = std::make_unique<Node>(value, std::move(pos->prev->next), pos->prev);
        temp = newNode.get();
        pos->prev->next = std::move(newNode);
        //pos->prev = std::move(newNode->getNext());  //Kanskje bedre; pos->prev = newNode.get()?
        pos->prev = temp;
    }
    return temp;     //return newNode.get();
}

Node* LinkedList::find(const std::string& value){
    Node* p = begin(); 
    while(value != p->getValue() && p != end()){
        p = p->getNext();
    }
    return p;
}

Node* LinkedList::remove(Node* pos){
    pos->next->prev = pos->prev;
    Node* p = (pos->next).get();
    pos->prev->next = std::move(pos->next);
    pos->prev = nullptr;
    pos = nullptr;
    return p;
}

void LinkedList::remove(const std::string& value){
    Node* p = find(value);
    if (p != end()){
        p = remove(p);
    }
    p = nullptr;
    return;
}

std::ostream & operator<<(std::ostream & os, const LinkedList& list){
    Node* p = list.begin();
    while(p != list.end()){
        os << *p << " ";
        p = p->getNext();
    }
    return os;
}
}

void testLinkedList(){
    LinkedList::LinkedList link;
    LinkedList::Node* hei;
    //LinkedList::Node node{"Hei", end(), link.begin()};
    hei = link.insert(link.end(),"Hei");
    link.insert(link.end(),"Hello");  //Legger til bakerst
    link.insert(link.begin(),"First");  //Legger til først
    link.insert(hei,"Second");       //Legger til foran pekeren (foran hei)
    std::cout << link << std::endl;

    LinkedList::Node* hello = link.remove(hei);  //Returnerer peker til elementet bak
    link.remove(hello);
    std::cout << link << std::endl;

    link.remove("Second");
    std::cout << link << std::endl;
}