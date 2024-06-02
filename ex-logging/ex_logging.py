import logging

logging.basicConfig(
    level=logging.DEBUG, format="[%(levelname)s] %(message)s", filename="test.log"
)


def add(x, y):
    return x + y


def subtract(x, y):
    return x - y


def multiply(x, y):
    return x * y


def divide(x, y):
    return x / y


num_1 = 10
num_2 = 5

add_result = add(num_1, num_2)
logging.debug(f"Add     : {num_1} + {num_2} = {add_result}")

subtract_result = subtract(num_1, num_2)
logging.debug(f"Subtract: {num_1} - {num_2} = {subtract_result}")

multiply_result = multiply(num_1, num_2)
logging.warning(f"Multiply: {num_1} * {num_2} = {multiply_result}")

divide_result = divide(num_1, num_2)
logging.warning(f"Divide  : {num_1} / {num_2} = {divide_result}")
