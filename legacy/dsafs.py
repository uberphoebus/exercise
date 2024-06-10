from dataclasses import dataclass


@dataclass
class User:
    name: str
    age: int


def do_something(user: User) -> None:
    user.age += 1
    print(user)


def main() -> None:
    user = User(name="Alice", age=30)
    do_something(user)

    user2 = User(name="Bob", age=25)
    do_something(user2)


if __name__ == "__main__":
    main()
