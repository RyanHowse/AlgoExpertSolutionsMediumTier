#Ryan Howse
#6/7/2021
#Determining if vectors are monotonic (exclusively increase or decrease)

def isMonotonic(array):
	#lets have an index
	checkIndex = 0
	
	#make sure array is at least 2 values long, anything smaller is
	#automatically monotonic
	if len(array) > 1:
		#the beginning check determines if we're checking for increasing or decreasing values
		#once it's locked into one of those sections...
		if array[checkIndex] >= array[len(array)-1]:
			while checkIndex < len(array)-1:
				if array[checkIndex] >= array[checkIndex + 1]:
					checkIndex = checkIndex + 1
				else:
					#..a failed check will result in an automatic return false
					return False
		else:
			while checkIndex < len(array)-1:
				if array[checkIndex] <= array[checkIndex + 1]:
					checkIndex = checkIndex + 1
				else:
					return False
				
	#if every check passes the loop will exit and the program will end up here,
	#returning true because we have determined that the data set is monotonic
	return True
