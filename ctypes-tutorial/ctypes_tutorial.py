import ctypes

clibrary = ctypes.CDLL("./clibrary.so")

# string should be bytes
# clibrary.display(b"John", 18)

# prepare the function signature
func = clibrary.display

# set ctypes argtypes
func.argtypes = [ctypes.c_char_p, ctypes.c_int]
func.restype = ctypes.c_char_p


name_string = ctypes.c_char_p(b"John")
print(f"{name_string=}")  # memory address / pointer -> file path

a = func(name_string, 18)
print(f"{a=}")
