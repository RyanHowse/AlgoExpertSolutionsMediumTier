//Ryan Howse
//6/2/2021
//Finding the smallest difference between 2 values in 2 seperate arrays

#include <cstdlib>
#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  //lets sort the arrays so that we have some friendlier data
	//as well it'll help us stop checking early to save calcs
	sort(arrayOne.begin(), arrayOne.end());
	sort(arrayTwo.begin(), arrayTwo.end());
	
	//we'll also need a return vector, a variable to store
	//the current smallest difference, and one to store the previous difference
	vector<int> returnVector = {0,0};
	int smallestDiff = INT_MAX;
	int previousDiff;
	
	for(int i = 0; i < arrayOne.size(); i++){
		previousDiff = INT_MAX;
		for(int j = 0; j < arrayTwo.size(); j++){
			//for each ij pair, get the absolute difference
			int currentDiff = std::abs(arrayOne[i]-arrayTwo[j]);
			//if we have a new smallest difference, update the return vector and saved value
			if(currentDiff < smallestDiff){
				smallestDiff = currentDiff;
				returnVector[0] = arrayOne[i];
				returnVector[1] = arrayTwo[j];
			}
			//if the currentDiff is greater than the previous diff, then all
			//other comparisons will be greater since the arrays are sorted,
			//so stop checking to save calcs
			if(currentDiff > previousDiff){
				break;
			}
			else{
				previousDiff = currentDiff;
			}
		}
	}
	
  return returnVector;
}
