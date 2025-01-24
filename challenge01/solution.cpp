/* Challenge 01: Rotating Arrays; null solution
 *
 * Elias Tessema NETID: CKL422
 *
 * This program will rotate a given list of numbers by the given direction and 
 * number of rotations
*/

#include <iostream>

int main(int argc, char *argv[]) {
    
	// Input variables
	int numVals = 0, numRotations = 0;
    char dir = 'X';

	// Iterator and new index variables
    int i = 0, index = 0;

	// For every set of inputs in the cin stream
    while(std::cin >> numVals >> numRotations >> dir){
        int nums[numVals];
        int newNums[numVals];

        for (i = 0; i < numVals; i++){
            std::cin >> nums[i];
        }

        if (dir == 'L'){
            for (i = 0; i < numVals; i++){
				index = i - numRotations;
				
				// Until index is greater than 0, add the numbers of values
				while (index < 0){
                    index = numVals + index;
                }
                newNums[index] = nums[i];
            }
        }

        if (dir == 'R'){
            for (i = 0; i < numVals; i++){
                index = i + numRotations;
				
				// Until index is less than or equal to the max index, subtract the numbers of values
                while (index >= numVals){
                    index = index - numVals;
                }

                newNums[index] = nums[i];
            }
        }

        for (int i = 0; i < numVals; i++){
            std::cout << newNums[i];
            if (i < (numVals - 1)){
                std::cout << " ";
            }
        }

        std::cout << std::endl;
    }


    return 0;
}
