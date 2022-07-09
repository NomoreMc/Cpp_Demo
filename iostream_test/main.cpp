#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
	string line, word;
	vector<string> words;
	while (getline(cin, line)) {
		istringstream is(line);
		while (is >> word) {
			words.push_back(word);
		}
		for (int i=0; i<words.size(); ++i) {
			cout<<words[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
