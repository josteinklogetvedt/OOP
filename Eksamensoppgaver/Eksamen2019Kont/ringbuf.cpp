#include "ringbuf.h"

RingBuf::RingBuf(int capacity){
    this->capacity = capacity;
    start = 0;
    size = 0;
    buf = new char[capacity];
}

RingBuf::RingBuf(const RingBuf &other){   //copy
    buf = new char[other.capacity];
    start = other.start;
    size = other.size;
    capacity = other.capacity;
    for (int i=0; i<capacity; i++){
        buf[i] = other.buf[i];
    }
}

RingBuf::~RingBuf(){
    delete[] buf;
}

RingBuf::RingBuf(RingBuf &&other)
    :buf{other.buf},capacity{other.capacity},start{other.start},size{other.size}{
        other.buf = nullptr;
        other.capacity = 0;
        other.start = 0;
        other.size = 0;
}

RingBuf& RingBuf::operator=(RingBuf rhs){   //Copy assignment
    char* b = new char[rhs.capacity];
    for (int i=0; i<rhs.capacity; i++){
        b[i] = rhs.buf[i];
    }
    delete[] buf;
    start = rhs.start;
    size = rhs.size;
    capacity = rhs.capacity;
    buf = b;
    return *this;
}

void RingBuf::write(char c){
    if (size == capacity) { // Overskriver starten
        buf[start++] = c;
        if (start == capacity) {
            start = 0;
        }
    }
    else{
        buf[(start + size) % capacity] = c;
        size++;
    }
}

char RingBuf::read(){
    if (size <= 0){
        throw "Empty buffer";
    }
    char c = buf[start];
    if (start == capacity){
        start = 0;
    }else{
        start += 1;
    } 
    size -= 1;   
    return c;
}

void RingBuf::write(string s){
    for (int i=0; i<s.size(); ++i){
        write(s[i]);
    }
}

string RingBuf::read(int count){
    string s;
    if (count == -1 || count > size){
        count = size;
    }
    for (int i=0; i<count; i++){
       s += read();           
    }
    return s;
}

string RingBuf::peek(){
    string s;
    for (int i=start; i<start+size; i++){
        s += buf[i % capacity];
    }
    return s;
}
 
void testRingBuf(){
    RingBuf rb = RingBuf(5);
    cout << "Capacity: " << rb.capacity << endl;
    cout << "Elements: " << rb.peek() << " start=" << rb.start << ", size=" << rb.size << endl;
    rb.write("ABC");
    cout << "Elements: " << rb.peek() << " start=" << rb.start << ", size=" << rb.size << endl;
    rb.write("DEF");
    cout << "Elements: " << rb.peek() << " start=" << rb.start << ", size=" << rb.size << endl;
    string s = rb.read(3);
    cout << s << endl;
    cout << "Elements: " << rb.peek() << " start=" << rb.start << ", size=" << rb.size << endl;
    s = rb.read(-1);
    cout << s << endl;
    cout << "Elements: " << rb.peek() << " start=" << rb.start << ", size=" << rb.size << endl;
}


