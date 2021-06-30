//Ryan Howse
//6/30/2021
//Merging overlapping intervals
//takes in an array of intervals given as x,y points
//and merges ones that overlap in order to return a list with no overlaps

#include <vector>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
  //in order to do this we must first sort the input array
	//based on the x value
	sort(intervals.begin(), intervals.end());
	
	//now we can go through and see if the proceeding index is either
	//within or overlapping the current index
	//if it's completely within, the procedding index will be absorbed
	//by the current one, if it overlaps then the proceeding index's y value
	//will overwrite the current index's, and the x value will be absorbed
	for(int i = 0; i < intervals.size()-1; i++){
		if(intervals[i+1][0] <= intervals[i][1]){
			//overlap
			if(intervals[i+1][1] > intervals[i][1]){
				//the outer limit of the next index becomes
				//the outer limit of the current index, and the next index
				//is absorbed
				intervals[i][1] = intervals[i+1][1];
				intervals.erase(intervals.begin()+i+1);
				//set the counter back to have it check the new interval
				i--;
			}
			else{
				//next index is within current index, next index is absorbed
				intervals.erase(intervals.begin()+i+1);
				//set the counter back to have it check the new interval
				i--;
			}
		}
	}
	
  return intervals;
}
