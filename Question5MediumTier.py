#Ryan Howse
#6/10/2021
#Spiral traversal of a square-shaped 2D array
#Got incredibly close, ended up consulting help
#Solution was much simpler than I thought, comments explain

def spiralTraverse(array):
  	#the first thing we do is handle an edge case that will break things
	if len(array) == 0:
		return []
	
	#next we need a real return vector
	returnVector = []
	
	#and some array measurements to keep us in bounds
	startRow = 0
	endRow = len(array) - 1
	startCol = 0
	endCol = len(array[0]) - 1
	
	while startRow <= endRow and startCol <= endCol:
		#start by going right until you hit all columns
		for col in range(startCol, endCol + 1):
			returnVector.append(array[startRow][col])
		
		#then go down until youb reach the bottom
		for row in range(startRow + 1, endRow + 1):
			returnVector.append(array[row][endCol])
		
		#go left
		for col in reversed(range(startCol, endCol)):
			#handle the edge case of there only being 1 row
			if startRow == endRow:
				break
			returnVector.append(array[endRow][col])
		
		#go up
		for row in reversed(range(startRow + 1, endRow)):
			#handle the edge case of there only being 1 column
			if startCol == endCol:
				break
			returnVector.append(array[row][startCol])
		
		#shrink the box to acheive the spiral effect
		startRow += 1
		endRow -= 1
		startCol += 1
		endCol -= 1
		
	return returnVector
