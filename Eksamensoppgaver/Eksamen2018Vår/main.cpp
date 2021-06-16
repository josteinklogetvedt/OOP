#include "Calendar.h"
#include "std_lib_facilities.h"

int main(){

	cout << isLeapYear(2020) << endl;
	Date day{1,3,2020};
	cout << dayNo(day) << endl;


	Date date = stringToDate("1998-02-01");
	cout << dayNo(date) << endl;

	Date day2{13,10,1998};
	string s = dateToString(day2);
	cout << s << endl;

	Event eve{"John", 223, day2};
	cout << eve;
	keep_window_open();
}


