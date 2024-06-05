# from ctypes import *

# # Load the libc library
# libc = CDLL("libc.so.6")

# # Define FILE pointer type
# FILE_p = POINTER(c_void_p)

# # Define fopen function
# libc.fopen.argtypes = [c_char_p, c_char_p]
# libc.fopen.restype = FILE_p

# # Define fclose function
# libc.fclose.argtypes = [FILE_p]
# libc.fclose.restype = c_int

# # Define fgets function
# libc.fgets.argtypes = [c_char_p, c_int, FILE_p]
# libc.fgets.restype = c_char_p

# # Define a buffer for the line
# buffer = create_string_buffer(4096)

# # Use the functions
# fp = libc.fopen(b"./text.txt", b"r")
# if fp:
#     print("File opened successfully")

#     # Read and print each line
#     while True:
#         result = libc.fgets(buffer, sizeof(buffer), fp)
#         if result:
#             print(buffer.value)
#             print(buffer.value.decode())
#         else:
#             break

#     libc.fclose(fp)
# else:
#     print("Failed to open file")

from ctypes import *

# Load the shared library
lib = CDLL("./libwriteFile.so")

# Define the argument types and return type of the function
lib.writeFile.argtypes = [c_void_p, c_char_p]
lib.writeFile.restype = None

# Call the function
lib.writeFile(None, b"Hello, World!")
