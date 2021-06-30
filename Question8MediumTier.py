#Ryan Howse
#6/30/2021
#finding the first duplicate value in a dataset
from collections import defaultdict

def firstDuplicateValue(array): 
	#we're gonna do this with a hash table
	usedInts = defaultdict(int)
	
	#goes through each element of the array
	for i in range(len(array)):
		if usedInts[str(array[i])] == 0:
			usedInts[str(array[i])] = 1
		elif usedInts[str(array[i])] == 1:
			#if we hit this point then we have seen the value already, so this is the first dupe
			return array[i]
	#if we reach this point there are no duplicate values
	return -1;
