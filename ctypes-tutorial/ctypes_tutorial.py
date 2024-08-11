import ctypes

clibrary = ctypes.CDLL("/workspaces/exercise/ctypes-tutorial/clibrary.so")

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

########################################
# pointers
########################################

alloc_func = clibrary.alloc_memory
alloc_func.restype = ctypes.POINTER(ctypes.c_char_p)

free_func = clibrary.free_memory
free_func.argtypes = [ctypes.POINTER(ctypes.c_char_p)]

cstring_pointer = alloc_func()

cstring = ctypes.c_char_p.from_buffer(cstring_pointer)
print(f"{cstring.value=}")

free_func(cstring_pointer)

print("\n\n")

num = ctypes.c_int(100)
ptr = ctypes.pointer(num)
print(f"{ptr.contents=}")

# ptr2 = ctypes.POINTER(ctypes.c_int)  # faster than ctypes.pointer
# ptr2.contents = num
# print(f"{ptr2.contents=}")

ptr2 = ctypes.POINTER(ctypes.c_int)(num)
print(f"{ptr2.contents=}")

########################################
# arrays
########################################

values = (ctypes.c_int * 10)()

for i in range(len(values)):
    values[i] = i

csum = clibrary.sumArray
csum.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
csum.restype = ctypes.c_int

result = csum(values, len(values))
print(f"{result=}")

cinc = clibrary.incArray
cinc.argtypes = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
cinc.restype = ctypes.POINTER(ctypes.c_int)
res = cinc(values, len(values))

print(f"{res=}")
for i in range(len(values)):
    print(res[i])

########################################
# malloc and free
########################################

print("malloc and free")
get_array = clibrary.getArray
get_array.restype = ctypes.POINTER(ctypes.c_int)
array = get_array()

for i in range(5):
    print(array[i])

free_array = clibrary.freeArray
free_array.argtypes = [ctypes.POINTER(ctypes.c_int)]
free_array(array)

########################################
# structs
########################################


print("\nstructs\n")


class Point(ctypes.Structure):
    _fields_ = [("x", ctypes.c_int), ("y", ctypes.c_int)]


# p = Point(1, 2)
# print(f"{p=}")
# print(f"{p.x=}, {p.y=}")
# clibrary.printPoint(p)

clibrary.getPoint.restype = ctypes.POINTER(Point)
p = clibrary.getPoint()
print(f"{p=}")
print(f"{p.contents.x=}, {p.contents.y=}")


# char pointer
class Student(ctypes.Structure):
    _fields_ = [("name", ctypes.c_char_p)]


name = "CodersLegacy"
s = Student(bytes(name, "utf-8"))
clibrary.printStudentDetails(s)
