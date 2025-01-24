// Challenge 01: Rotating Arrays; null solution

#include <iostream>

int main(int argc, char *argv[]) {
	int numVals = 0, numRotations = 0;
	char dir = 'X';

	int i = 0;
	while(std::cin >> numVals >> numRotations >> dir){
		int* nums = new int[numVals];
		for (int i = 0; i < numVals; i++){
			std::cin >> nums[i];
		}

		for (int i = 0; i < numVals; i++){
			std::cout >> nums[i];
		}

	}

	return 0;
}

