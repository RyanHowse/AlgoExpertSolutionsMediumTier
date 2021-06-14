//Ryan Howse
//6/14/2021
//Finding the length of the largest peak in a dataset
//peak is defined as strictly increasing values,
//followed by strictly decreasing values

using namespace std;

int longestPeak(vector<int> array) {
  	//first let's have a return counter
	int highestPeak = 0;
	//and a counter for the current peak
	int currentPeak = 0;
	//and a flag for if we're going up or down
	bool goingUp = true;
	
	//we verify that the array.size() is greater than 0
	//because an array size of 0 - 1 is not -1, it underflows into a mess
	//and the computer seems to really not like it
	if(array.size() > 0){
		for(int i = 0; i < array.size()-1; i++){
			//if we are on the way up a peak
			if(goingUp){
				//peak gets higher, keep going
				if(array[i] < array[i+1]){
					currentPeak++;
				}
				//this is referenced below as the flag which requires us to increment
				//non-zero answers
				else if(array[i] > array[i+1] && currentPeak > 0){
					//we have reached a peak, but only if we have at least
					//one value going up
					goingUp = false;
					currentPeak++;
				}
				else if(array[i] == array[i+1]){
					//reset because the two values are equal and therefore there is no peak
					currentPeak = 0;
				}
			}
			//going down
			else{
				//peak is declining, keep going
				if(array[i] > array[i+1]){
					currentPeak++;
				}
				//the peak is over, flag to go up again
				else if(array[i] < array[i+1]){
					goingUp = true;
					//overwite the highestPeak if the current peak is higher
					if(highestPeak < currentPeak){
						highestPeak = currentPeak;
					}
					//start a new peak
					currentPeak = 1;
				}
				//we hit a plateau
				//flag to go up but don't start a new peak
				else if(array[i] == array[i+1]){
					goingUp = true;
					if(highestPeak < currentPeak){
						highestPeak = currentPeak;
					}
					currentPeak = 0;
				}
			}
		}
	}
	
	//over write the highest peak if we can,
	//but only if we are currently declining
	//a bunch of increasing values without a decline is not a peak
	if(highestPeak < currentPeak && goingUp==false){
		highestPeak = currentPeak;
	}
	
	//add 1 to non-zero peaks
	//we do this because we used a 0 peak as a flag during the loop,
	//but doing that sets the count behind by 1
	if(highestPeak!=0){
		highestPeak++;
	}
	
  return highestPeak;
}
