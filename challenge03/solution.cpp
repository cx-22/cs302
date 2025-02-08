/* Challenge 03: Palindrome Permutation
 *
 * Elias Tessema NETID: CKL422
 *
 * This program will determine whether a phrase is a palindrome or not
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>

int main(int argc, char *argv[]) {
	// This map will have key value pairs of a letter, and the number of its
	// occurrences
	std::unordered_map<char, int> myMap;
	std::unordered_map<char, int>::iterator itr;
	std::string phrase;
	std::string copy;
	int badOdd = 0;

	while (std::getline(std::cin, phrase)){
		myMap.clear();
		badOdd = 0;

		copy = phrase;
		
		// Make sure all the letters are lowercase
		for (long unsigned int i = 0; i < phrase.size(); i++){
			phrase[i] = std::tolower(phrase[i]);
		}

		// For every letter in the phrase, add it to the map, if already there
		// add 1 to its number of occurrences
		for (long unsigned int i = 0; i < phrase.size(); i++){
			if (phrase[i] > 96 && phrase[i] < 123){
				if (myMap.find(phrase[i]) == myMap.end()){
					myMap[phrase[i]] = 1;
				} else {
					myMap.at(phrase[i])++;
				}
			}

		}

		// A palindrome can have a max of 1 letter with an odd number of
		// occurances, if more than that then it fails
		for (itr = myMap.begin(); itr != myMap.end(); itr++){
			int count = itr->second;
			if (count % 2 == 1){
				badOdd++;

				if (badOdd > 1){
					break;
				}
			}
		}

		std::cout << "\"" << copy << "\"";

		if (badOdd < 2){
			std::cout << " is a palindrome permutation" << std::endl;
		} else {
			std::cout << " is not a palindrome permutation" << std::endl;
		}
	}

	return (0);
}

