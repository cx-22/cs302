// Challenge 01: Rotating Arrays; null solution

#include <iostream>

int main(int argc, char *argv[]) {
    int numVals = 0, numRotations = 0;
    char dir = 'X';
    int i = 0, index = 0;

    while(std::cin >> numVals >> numRotations >> dir){
        int nums[numVals];
        int newNums[numVals];

        for (i = 0; i < numVals; i++){
            std::cin >> nums[i];
        }

        if (dir == 'L'){
            for (i = 0; i < numVals; i++){
                index = i - numRotations;
                while (index < 0){
                    index = numVals + index;
                }
                newNums[index] = nums[i];
            }
        }

        if (dir == 'R'){
            for (i = 0; i < numVals; i++){
                index = i + numRotations;
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
