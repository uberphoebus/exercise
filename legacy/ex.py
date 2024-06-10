num = 10
den = "Aesfsef"

try:
    result = num / den
    print(result)
except FileExistsError:
    print("File exists")
except FileNotFoundError:
    print("File not found")
except UnboundLocalError:
    print("Unbound local")
except NotADirectoryError:
    print("Not a directory")
except ZeroDivisionError as e:
    print(e)
    print("Division by zero")
except ValueError:
    print("Invalid value")
except TypeError:
    print("Invalid type")
except NameError:
    print("Name not defined")
except AttributeError:
    print("Attribute not found")
except KeyError:
    print("Key not found")
except IndexError:
    print("Index out of range")
except FileNotFoundError:
    print("File not found")
except IOError:
    print("I/O error")
except ImportError:
    print("Module not found")
except IndentationError:
    print("Indentation error")
except SyntaxError:
    print("Syntax error")

except MemoryError:
    print("Memory error")
except RecursionError:
    print("Recursion error")
except SystemError:
    print("System error")
except SystemExit:
    print("System exit")
except KeyboardInterrupt:
    print("Keyboard interrupt")
except FloatingPointError:
    print("Floating point error")
except OverflowError:
    print("Overflow error")

except StopIteration:
    print("Stop iteration")
except Exception:
    print("An error occurred")
