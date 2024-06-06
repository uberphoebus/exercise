from dataclasses import dataclass
from typing import List


@dataclass
class Rank:
    rank: int
    appid: int
    name: str
    score: int


@dataclass
class Response:
    last_updated: int
    ranks: List[Rank]

    def __post_init__(self):
        self.ranks = [Rank(**rank) for rank in self.ranks]


@dataclass
class Top:
    Response: Response

    def __post_init__(self):
        self.response = Response(**self.response)


top = Top(