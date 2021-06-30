//Ryan Howse
//6/30/2021
//finding the first duplicate value in a dataset

#include <vector>
using namespace std;

int firstDuplicateValue(vector<int> array){ 
	//we're gonna do this with a hash table
	unordered_map<int, int> usedInts;
	
	//goes through each element of the array
	for(int i = 0; i < array.size(); i++){
		//I believe this just initializes a count when it finds a new value
    if(usedInts.find(array[i]) == usedInts.end()){
			usedInts[array[i]] = 0;
		}
		//increments the count of the next element value
		usedInts[array[i]]++;
		
		//if the incremented value is 2, we have encountered that value once already
		if(usedInts[array[i]] == 2){
			return array[i];
		}
	}
	
	//if we reach this point there are no duplicate values
	return -1; 
}
