import threading
from typing import Callable


class FizzBuzz:
    def hasFinished(self) -> bool:
        return self.cur > self.n

    def isFizz(self) -> bool:
        return (self.cur % 3 == 0) and (self.cur % 5 != 0)

    def isBuzz(self) -> bool:
        return (self.cur % 3 != 0) and (self.cur % 5 == 0)

    def isFizzBuzz(self) -> bool:
        return (self.cur % 3 == 0) and (self.cur % 5 == 0)

    def isNumber(self) -> bool:
        return (self.cur % 3 != 0) and (self.cur % 5 != 0)

    def __init__(self, n: int):
        self.n = n
        self.cur = 1
        self.condition = threading.Condition()

    # printFizz() outputs "fizz"
    def fizz(self, printFizz: "Callable[[], None]") -> None:
        while True:
            with self.condition:
                while not self.hasFinished() and not self.isFizz():
                    self.condition.wait()

                if self.hasFinished():
                    return

                printFizz()
                self.cur += 1

                self.condition.notify_all()

    # printBuzz() outputs "buzz"
    def buzz(self, printBuzz: "Callable[[], None]") -> None:
        while True:
            with self.condition:
                while not self.hasFinished() and not self.isBuzz():
                    self.condition.wait()

                if self.hasFinished():
                    return

                printBuzz()
                self.cur += 1

                self.condition.notify_all()

    # printFizzBuzz() outputs "fizzbuzz"
    def fizzbuzz(self, printFizzBuzz: "Callable[[], None]") -> None:
        while True:
            with self.condition:
                while not self.hasFinished() and not self.isFizzBuzz():
                    self.condition.wait()

                if self.hasFinished():
                    return

                printFizzBuzz()
                self.cur += 1

                self.condition.notify_all()

    # printNumber(x) outputs "x", where x is an integer.
    def number(self, printNumber: "Callable[[int], None]") -> None:
        while True:
            with self.condition:
                while not self.hasFinished() and not self.isNumber():
                    self.condition.wait()

                if self.hasFinished():
                    return

                printNumber(self.cur)
                self.cur += 1

                self.condition.notify_all()


class FizzBuzz:
    def hasFinished(self) -> bool:
        return self.cur > self.n

    def isFizz(self) -> bool:
        return (self.cur % 3 == 0) and (self.cur % 5 != 0)

    def isBuzz(self) -> bool:
        return (self.cur % 3 != 0) and (self.cur % 5 == 0)

    def isFizzBuzz(self) -> bool:
        return (self.cur % 3 == 0) and (self.cur % 5 == 0)

    def isNumber(self) -> bool:
        return (self.cur % 3 != 0) and (self.cur % 5 != 0)

    def __init__(self, n: int):
        self.n = n
        self.cur = 1
        self.lock = threading.RLock()

    # printFizz() outputs "fizz"
    def fizz(self, printFizz: "Callable[[], None]") -> None:
        while not self.hasFinished():
            with self.lock:
                if not self.hasFinished() and self.isFizz():
                    printFizz()
                    self.cur += 1

    # printBuzz() outputs "buzz"
    def buzz(self, printBuzz: "Callable[[], None]") -> None:
        while not self.hasFinished():
            with self.lock:
                if not self.hasFinished() and self.isBuzz():
                    printBuzz()
                    self.cur += 1

    # printFizzBuzz() outputs "fizzbuzz"
    def fizzbuzz(self, printFizzBuzz: "Callable[[], None]") -> None:
        while not self.hasFinished():
            with self.lock:
                if not self.hasFinished() and self.isFizzBuzz():
                    printFizzBuzz()
                    self.cur += 1

    # printNumber(x) outputs "x", where x is an integer.
    def number(self, printNumber: "Callable[[int], None]") -> None:
        while not self.hasFinished():
            with self.lock:
                if not self.hasFinished() and self.isNumber():
                    printNumber(self.cur)
                    self.cur += 1
