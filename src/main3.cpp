#include <iostream>
#include <string>
#include "DateTime.h"

using namespace std;

int main() {
	DateTime bd(05, 02, 2000);
	DateTime td;
	cout << td.getToday() << endl;
	cout << td.getYesterday() << endl;
	cout << td.getTomorrow() << endl;
	cout << bd.getPast(9) << endl;
	cout << bd.getFuture(9) << endl;
	cout << bd.getDifference(td) << endl;
	return 0;
}