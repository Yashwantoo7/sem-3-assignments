import numpy as np
arr=np.arange(1,5)
print(arr)
print(id(arr),id(arr[0]),id(arr[1]),id(arr[2]))
print(arr.__array_interface__['data'][0],arr[0].__array_interface__['data'][0],arr[1].__array_interface__['data'][0],arr[2].__array_interface__['data'][0])