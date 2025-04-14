// Challenge 08: sequence alignment

#include <iostream>
#include <iomanip>
#include <vector>

int main(int argc, char *argv[]) {
	std::string seq1;
	std::string seq2;

	int match = 1;
	int mismatch = -1;
	int gap = -1;
	
	std::cin >> seq1;
	std::cin >> seq2;

	std::vector<std::vector<int>> matrix(seq1.size() + 1, std::vector<int>(seq2.size() + 1));

	for (unsigned long i = 0; i < seq1.size() + 1; ++i){
		for (unsigned long j = 0; j < seq2.size() + 1; ++j){

			// If we are looking at the first row or column, the answer is predictable
			if (i == 0){
				matrix[i][j] = gap * j;
				continue;
			} else if (j == 0){
				matrix[i][j] = gap * i;
				continue;
			}

			// If there is a match, add to the top left
			if (seq1[i - 1] == seq2[j - 1]){
				matrix[i][j] = matrix[i - 1][j - 1] + match;
			} 
			
			// If no match, find which of a mismatch, gap up, or gap left gives the best score
			else {
				int top = matrix[i - 1][j] + gap;
				int left = matrix[i][j - 1] + gap;
				int tleft = matrix[i - 1][j - 1] + mismatch;

				if (top >= left && top >= tleft){ matrix[i][j] = top; }
				else if (left >= top && left >= tleft){ matrix[i][j] = left; }
				else if (tleft >= top && tleft >= left){ matrix[i][j] = tleft; }
			}
		}
	}

	std::cout << matrix[seq1.size()][seq2.size()] << "\n";

	return 0;
}


