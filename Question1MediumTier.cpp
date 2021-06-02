//Ryan Howse
//6/2/2021
//Finding out if 3 numbers within a data set can hit a target sum
//I consulted the hint, but not the answer, for this problem

#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  //in order to do this we're going to first sort the array
	//that way we have ordered data that is easier to work with
	//then for each value, we're going to add the next value as well as the
	//final value
	//if the sum is greater than the target, we go lower on the last value
	//which gives us a lower sum, and if it's less than the target we go higher
	//on the next value which will give us a higher sum
	//we converge the two values until we know that the current value
	//cannot be used to reach the target sum and then move on
	
	//first let's sort for more friendly data
	sort(array.begin(), array.end());
	
	//let's have a flag for our internal loop
	bool keepSearching = true;
	
	//and a return vector
	vector<vector<int>> valueTriplets = {};
	
	//and let's have a condition to cut down on checking things we don't have to
	//if((array[i]+array[least]+(array[least+1])) > targetSum || (array[i]+array[greatest]+(array[greatest-1])) < targetSum)
	//keepSearching = false; because if either of these conditions are true
	//then the target is unreachable and no further checks need to be done
	for(int i = 0; i < array.size(); i++){
		//the least greater index that might be used in our triplet
		int least = i + 1;
		//the greatest greater index that might be used in our triplet
		int greatest = array.size() - 1;
		//only look while keepSearching is true to avoid using up extra calcs
		keepSearching = true;
		while(keepSearching){
			if((array[i]+array[least]+(array[least+1])) > targetSum || (array[i]+array[greatest]+(array[greatest-1])) < targetSum){
				keepSearching = false;
			}
			//this happens when the current index pushes far enough right,
			//at this point move onto the next index
			else if(least > greatest){
				keepSearching = false;
			}
			else{
				//reduce sum to get closer to target sum
				if(array[i]+array[least]+array[greatest] > targetSum){
					greatest--;
				}
				//increase sum to get closer to target sum
				else if(array[i]+array[least]+array[greatest] < targetSum){
					least++;
				}
				else{
					//we have found the target, add the values to the vector
					valueTriplets.push_back({array[i], array[least], array[greatest]});
					//keep checking to make sure there aren't other combination with the current index
					least++;
					greatest = array.size()-1;
				}
			}
		}
	}
	
  return valueTriplets;
}
