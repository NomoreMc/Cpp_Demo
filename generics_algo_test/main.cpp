#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main(int argc, char **argv) {
	vector<int> arr = { 1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6 };
	vector<int> newArr;

	// lower_bound从数组的begin到end-1位置二分查找第一个大于或等于num的数字，找到返回对应位置的迭代器，不存在则返回end
	auto lower = lower_bound(arr.begin(), arr.end(), 4);
	// upper_bound从数组的begin到end-1位置二分查找第一个大于num的数字，找到返回对应位置的迭代器，不存在则返回end
	auto upper = upper_bound(arr.begin(), arr.end(), 4);

	copy(lower, upper, ostream_iterator<int>(cout, " "));
	cout<<endl;
	copy(lower, upper, back_inserter(newArr));
	for (int &num: newArr) {
		cout<<num<<" ";
	}
	cout<<endl;
	return 0;
}
