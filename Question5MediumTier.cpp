//Ryan Howse
//6/10/2021
//Spiral traversal of a square-shaped 2D array
//Got incredibly close, ended up consulting help
//Solution was much simpler than I thought, comments explain

using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array) {
  //the first thing we do is handle an edge case that will break things
	if(array.size() == 0){
		return {};
	}
	
	//next we need a real return vector
	vector<int> returnVector = {};
	
	//and some array measurements to keep us in bounds
	int startRow = 0;
	int endRow = array.size() - 1;
	int startCol = 0;
	int endCol = array[0].size() - 1;
	
	while(startRow <= endRow && startCol <= endCol){
		//start by going right until you hit all columns
		for(int col = startCol; col <= endCol; col++){
			returnVector.push_back(array[startRow][col]);
		}
		
		//then go down until youb reach the bottom
		for(int row = startRow + 1; row <= endRow; row++){
			returnVector.push_back(array[row][endCol]);
		}
		
		//go left
		for(int col = endCol - 1; col >= startCol; col--){
			//handle the edge case of there only being 1 row
			if(startRow == endRow){
				break;
			}
			returnVector.push_back(array[endRow][col]);
		}
		
		//go up
		for(int row = endRow - 1; row > startRow; row--){
			//handle the edge case of there only being 1 column
			if(startCol == endCol){
				break;
			}
			returnVector.push_back(array[row][startCol]);
		}
		
		//shrink the box to acheive the spiral effect
		startRow++;
		endRow--;
		startCol++;
		endCol--;
	}
	return returnVector;
}
