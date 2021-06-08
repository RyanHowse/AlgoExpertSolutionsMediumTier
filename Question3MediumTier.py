#Ryan Howse
#6/7/2021
#Moving all instances of a target value
#to the end of the list

def moveElementToEnd(array, toMove):
	#let's have a right and left index
	rightIndex = len(array) - 1
	leftIndex = 0
	
	#if the left index catches up to the right one then
	#all of the toMove's are on the right side
	while leftIndex < rightIndex:
		if array[leftIndex] == toMove:
			#we can't switch values if the right index also
			#contains a toMove value, so progress the rightIndex
			if array[rightIndex] == toMove:
				rightIndex = rightIndex - 1
			else:
				#swap the indexes if the leftIndex is a toMove value,
				#but the rightIndex value isn't
				array[leftIndex] = array[rightIndex]
				array[rightIndex] = toMove
				leftIndex = leftIndex + 1
		#progresses the leftIndex if the current leftIndex
		#is not a toMove value
		else:
			leftIndex = leftIndex + 1
	return array
