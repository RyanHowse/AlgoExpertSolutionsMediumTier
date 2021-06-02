#Ryan Howse
#6/2/2021
#Finding the smallest difference between 2 values in 2 seperate arrays

def smallestDifference(arrayOne, arrayTwo):
  	#lets sort the arrays so that we have some friendlier data
	#as well it'll help us stop checking early to save calcs
	arrayOne.sort()
	arrayTwo.sort()
	
	#we'll also need a return vector, a variable to store
	#the current smallest difference, and one to store the previous difference
	returnVector = [0,0]
	smallestDiff = 99999999999
	previousDiff = 99999999999
	
	for i in range(len(arrayOne)):
		previousDiff = 99999999999
		for j in range(len(arrayTwo)):
			#for each ij pair, get the absolute difference
			currentDiff = abs(arrayOne[i]-arrayTwo[j])
			#if we have a new smallest difference, update the return vector and saved value
			if currentDiff < smallestDiff:
				smallestDiff = currentDiff
				returnVector[0] = arrayOne[i]
				returnVector[1] = arrayTwo[j]
			#if the currentDiff is greater than the previous diff, then all
			#other comparisons will be greater since the arrays are sorted,
			#so stop checking to save calcs
			if currentDiff > previousDiff:
				break
			else:
				previousDiff = currentDiff
				
	return returnVector
