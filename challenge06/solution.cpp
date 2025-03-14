/* Challenge 06: Repeated DNA sequences
 *
 * Elias Tessema NETID: CKL422
 *
 * This program will return all repeating 9 character long strings in
 * a given DNA sequence
 *
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

	unordered_map <string, int> map;
	vector<string> sortedList;
	string sequence;
	string subStr;
	size_t size = 9;

	while(cin >> sequence){
	
		// If its less than (size + 1) chars long then there cant be a repeating
		// substring of of that size
		if (sequence.length() < (size + 1)){
			cout << "-1\n";
			continue;
		}

		map.clear();
		sortedList.clear();
		
		// Add every 9 long substring to the hash table, if its already there
		// add it to the vector
		for (size_t i = 0; i <= (sequence.length() - size); ++i){
			subStr = sequence.substr(i, size);
			unordered_map<string, int>::iterator search = map.find(subStr);

			if(search != map.end()){
				
				// Checking if its set to 0 ensures we only push back a string once
				if (map[subStr] == 0){
					map[subStr] = map[subStr] + 1;
					sortedList.push_back(subStr);
				}
			} else {
				map[subStr] = 0;
			}
		}

		sort(sortedList.begin(), sortedList.end());

		for (size_t i = 0; i < sortedList.size(); ++i){
			cout << sortedList[i] << "\n";
		}

		cout << "-1\n";
	}

	return 0;
}
