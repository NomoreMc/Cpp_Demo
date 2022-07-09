#include <iostream>
#include <memory>
#include <sharedPtr.h>
using namespace std;

void TestSharedPtrCreate() {
	shared_ptr<int> spi(new int(1));
	cout<<spi<<endl;
}
