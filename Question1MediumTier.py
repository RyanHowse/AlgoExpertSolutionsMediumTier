#Ryan Howse
#6/2/2021
#Finding out if 3 numbers within a data set can hit a target sum
#I consulted the hint, but not the answer, for this problem

def threeNumberSum(array, targetSum):
  	#in order to do this we're going to first sort the array
	#that way we have ordered data that is easier to work with
	#then for each value, we're going to add the next value as well as the
	#final value
	#if the sum is greater than the target, we go lower on the last value
	#which gives us a lower sum, and if it's less than the target we go higher
	#on the next value which will give us a higher sum
	#we converge the two values until we know that the current value
	#cannot be used to reach the target sum and then move on
	
	#first let's sort for more friendly data
	array.sort()
	
	#let's have a flag for our internal loop
	keepSearching = True
	
	#and a return list
	valueTriplets = []
	
	#and let's have a condition to cut down on checking things we don't have to
	#if((array[i]+array[least]+(array[least+1])) > targetSum || (array[i]+array[greatest]+(array[greatest-1])) < targetSum)
	#keepSearching = false; because if either of these conditions are true
	#then the target is unreachable and no further checks need to be done
	for i in range(len(array)):
		#the least greater index that might be used in our triplet
		least = i + 1
		#the greatest greater index that might be used in our triplet
		greatest = len(array) - 1
		#only look while keepSearching is true to avoid using up extra calcs
		keepSearching = True
		while keepSearching:
			if least < (len(array)-1): 
				if((array[i]+array[least]+(array[least+1])) > targetSum or (array[i]+array[greatest]+(array[greatest-1])) < targetSum):
					keepSearching = False
			#this happens when the current index pushes far enough right,
			#at this point move onto the next index
			if least > greatest:
				keepSearching = False
			else:
				#reduce sum to get closer to target sum
				if array[i]+array[least]+array[greatest] > targetSum:
					greatest = greatest - 1
				#increase sum to get closer to target sum
				elif array[i]+array[least]+array[greatest] < targetSum:
					least = least + 1
				else:
					#we have found the target, add the values to the vector
					valueTriplets.append([array[i], array[least], array[greatest]])
					#keep checking to make sure there aren't other combination with the current index
					least = least + 1
					greatest = len(array) - 1
	return valueTriplets
