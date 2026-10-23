#NUMPY ARRAYS
import numpy as np

#np.array() takes a sequence as input and converts it into a numpy array

#list
A = np.array([1, 2, 3, 4])
print("A" = A, A.dtype, "\n\n")

B = np.array(range(10)) #range object

#nested array (multidimensional)
C = np.array([(range(j,j+3)) for j in [2,4,6]]) #range object

#np.full(shape, element, dtype) 
D = np.full((2,3,4), 3.14, dtype = int)

#np.zeros(shape, dtype) and np.ones(shape, dtype)
E = np.zeros(100) 
F = np.ones((2,3,4), dtype = int) 

print(A, B, C, D, E, F, sep = "\n\n")

#python infers the dtype automatically if not mentioned
print("Datatype of A: ", A.dtype)
print("Datatype of B: ", B.dtype)
print("Datatype of C: ", C.dtype)
print("Datatype of D: ", D.dtype)
print("Datatype of E: ", E.dtype)
print("Datatype of F: ", F.dtype)

#np.arange(start, stop, step)
print(np.arange())