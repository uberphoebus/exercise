import ctypes

mylib = ctypes.cdll.LoadLibrary("./add.so")

result = mylib.add_int(12423, 3241235)

mylib.add_float.restype = ctypes.c_float
result2 = mylib.add_float(ctypes.c_float(124.23), ctypes.c_float(321.35))



print(result)
print(result2)