//Ryan Howse
//6/7/2021
//Moving all instances of a target value
//to the end of the vector

#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
	//let's have a right and left index
	int rightIndex = array.size()-1;
	int leftIndex = 0;
	
	while(true){
		//if the left index catches up to the right one then
		//all of the toMove's are on the right side
		if(leftIndex >= rightIndex){
			break;
		}
		if(array[leftIndex] == toMove){
			//we can't switch values if the right index also
			//contains a toMove value, so progress the rightIndex
			if(array[rightIndex] == toMove){
				rightIndex--;
			}
			else{
				//swap the indexes if the leftIndex is a toMove value,
				//but the rightIndex value isn't
				array[leftIndex] = array[rightIndex];
				array[rightIndex] = toMove;
				leftIndex++;
			}
		}
		//progresses the leftIndex if the current leftIndex
		//is not a toMove value
		else{
			leftIndex++;
		}
	}
  return array;
}
