
#include "std_lib_facilities.h"
#include "array2D.h"
#include "Animal.h"

int main()
{
	Dog dog("Jake", 28, "orange");
    Human human("Finn", 12);
    cout << dog.toString() << endl;
    cout << human.toString() << endl;
    dog.addFriend(&human);
    human.addFriend(&dog);
    for (auto a : dog.getFriends()) {
        cout << dog << " and " << *a << " are friends" << endl;
    }

	keep_window_open();
}


