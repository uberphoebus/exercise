import logging

logging.basicConfig(
    level=logging.DEBUG,
    format="[%(levelname)s] %(message)s",
    # filename="test.log",
    # filemode="w",
)

# logger = logging.getLogger("name")
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)

handler = logging.FileHandler("test.log")
# formatter = logging.Formatter(
#     "[%(levelname)s] - %(name)s - %(message)s (line: %(lineno)d"
# )
# formatter = logging.Formatter(fmt="[$(levelname) - $(name)s - $(message)s", style="{")
formatter = logging.Formatter(fmt="[{levelname:10s}] - {name} - {message}", style="{")
# formatter = logging.Formatter(fmt=f"{levelname}", style="$")
handler.setFormatter(formatter)
logger.addHandler(handler)

logger.info("test custom logger")


def add(x, y):
    return x + y


def subtract(x, y):
    return x - y


def multiply(x, y):
    return x * y


def divide(x, y):
    return x / y


num_1 = 10
num_2 = 0

add_result = add(num_1, num_2)
logger.debug(f"Add     : {num_1} + {num_2} = {add_result}")

subtract_result = subtract(num_1, num_2)
logger.debug(f"Subtract: {num_1} - {num_2} = {subtract_result}")

multiply_result = multiply(num_1, num_2)
logger.warning(f"Multiply: {num_1} * {num_2} = {multiply_result}")

try:
    divide_result = divide(num_1, num_2)
except ZeroDivisionError as e:
    logger.critical(f"zero div")
    # logger.exception(f"zero div")
# logger.warning(f"Divide  : {num_1} / {num_2} = {divide_result}")
