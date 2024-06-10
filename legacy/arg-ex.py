from argparse import ArgumentParser, Namespace


parser = ArgumentParser(description="Write a message to a file")

parser.add_argument("message", type=str, help="The message to write to the file")
parser.add_argument("-n", "--numbers", nargs="*", type=int, help="Two numbers")

parser.add_argument(
    "-f",
    "--file",
    type=str,
    help="The file to write the message to",
    default="message.txt",
)


parser.add_argument(
    "-a", "--append", action="store_true", help="Append the message to the file"
)
parser.add_argument(
    "-v", "--verbose", action="store_true", help="Print the message to the console"
)

# parser.add_argument(
#     "-v",
#     "--verbose",
#     action="store_true",
#     help="Print the message to the console",
#     choices=["INFO", "DEBUG"],
# )

parser.usage = "arg-ex.py [-h] [-f FILE] [-a] [-v] message"

parser.print_usage()

args: Namespace = parser.parse_args()

print(args.message)


from pathlib import Path


# file_path = Path(args.file)
# if not file_path.exists():
#     raise FileNotFoundError(f"File not found: {file_path}")
#     file_path.touch()

# else:
#     if args.append:
#         with open(file_path, "a") as file:
#             file.write(args.message + "\n")
#     else:
#         with open(file_path, "w") as file:
#             file.write(args.message + "\n")
