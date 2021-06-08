//Ryan Howse
//6/7/2021
//Determining if vectors are monotonic (exclusively increase or decrease)

using namespace std;

bool isMonotonic(vector<int> array) {
	//lets have an index
	int checkIndex = 0;
	
	//make sure array is at least 2 values long, anything smaller is
	//automatically monotonic
	if(array.size() > 1){
		//the beginning check determines if we're checking for increasing or decreasing values
		//once it's locked into one of those sections...
		if(array[checkIndex] >= array[array.size()-1]){
			while (checkIndex < array.size()-1){
				if(array[checkIndex] >= array[checkIndex + 1]){
					checkIndex++;
				}
				else {
					//..a failed check will result in an automatic return false
					return false;
				}
			}
		}
		else{
			while (checkIndex < array.size()-1){
				if(array[checkIndex] <= array[checkIndex + 1]){
					checkIndex++;
				}
				else {
					return false;
				}
			}
		}
	}
	//if every check passes the loop will exit and the program will end up here,
	//returning true because we have determined that the data set is monotonic
	return true;
}
