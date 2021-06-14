#Ryan Howse
#6/14/2021
#Returning a list of products
#for example, output[i] = products of input list except input[i]
#doing this as a bubble sort kind of method would be easy but costly
#consulted help to make a much more optimal solution
#I will provide output examples for the input list [0,1,2,3,4,5,6,7,8,9]

def arrayOfProducts(array):
	#we need a return list
	returnList = [1 for _ in range(len(array))]
	#we need a vector for products to the left of the current index 
	leftP = [1 for _ in range(len(array))]
	#and one for products to the right of the current index 
	rightP = [1 for _ in range(len(array))]
	
  	#first let's get the products to the left
	#example list output is [1,0,0,0,0,0,0,0,0]
	#because everything is multiplied by the first index 0
	#the first index however is multiplied by nothing, and the running
	#total starts at 1
	leftRunningP = 1
	for i in range(len(array)):
		leftP[i] = leftRunningP
		leftRunningP *= array[i]
	
	#and to the right
	#example array output is [362880, 362880, 181440, 60480, 15120, 3024, 504, 72, 9, 1]
	#this array gets loaded backwards due to the decrementing i, which is why we have
	#362880 twice, as the last value it gets multiplied by is 1 (it never reaches the 0)
	rightRunningP = 1
	for i in reversed(range(len(array))):
		rightP[i] = rightRunningP
		rightRunningP *= array[i]
	
	#and now lets populate our return vector
	#example array output is [362880,0,0,0,0,0,0,0,0,0]
	for i in range(len(array)):
		returnList[i] = leftP[i] * rightP[i]

	return returnList
