from ctypes import *

# Load the shared library
lib = CDLL("./libwriteFile.so")

# Define the argument types and return type of the function
lib.writeFile.argtypes = [c_void_p, c_char_p]
lib.writeFile.restype = None

file_pointer = c_void_p(0)

# Call the function
lib.writeFile(file_pointer, b"faesfsef, Worlfasdfd!")
