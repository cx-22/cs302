/* Challenge 02: Closest Numbers
 *
 * Elias Tessema NETID: CKL422
 *
 * This program will find the pairs of numbers in a given list with the
 * smallest absolute difference.
*/

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

// Main Execution

int main(int argc, char *argv[]) {
	int size = 0;
	int solutionSize = 0;
	int minDiff = 2147483647;
	int tempDiff = 0;
	int i = 0;

	vector<int> list;
	vector<int> solutionList;

	while (cin >> size){

		// Reset variables each loop
		list.clear();
		list.resize(size);
		solutionList.clear();
		
		minDiff = 2147483646;

		for (i = 0; i < size; ++i){
			cin >> list[i];
		}

		sort(list.begin(), list.end());

		for (i = 0; i < size - 1; ++i){
			tempDiff = list[i + 1] - list[i];

			// If this difference is less than the record minDiff, clear the
			// solution vector, else just add the pair
			if (tempDiff < minDiff){

				minDiff = tempDiff;
				solutionList.clear();
				solutionList.push_back(list[i]);
				solutionList.push_back(list[i + 1]);

			} else if (tempDiff == minDiff){

				solutionList.push_back(list[i]);
				solutionList.push_back(list[i + 1]);

			}
		}

		solutionSize = int(solutionList.size());

		for (i = 0; i < solutionSize; ++i){
			cout << solutionList[i];

			if (i != solutionSize - 1){
				cout << " ";
			} else {
				cout << "\n";
			}
		}
	}


	return EXIT_SUCCESS;
}
