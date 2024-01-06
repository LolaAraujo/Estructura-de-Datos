class Date:
    def __init__(self, orig: 'Date' = None) -> None:
        self.__year = int()
        self.__month = int()
        self.__day = int()

        if orig is not None:
            self.__year = orig.__year
            self.__month = orig.__month
            self.__day = orig.__day
    
    def __str__(self) -> str:
        return "{:04d}/{:02d}/{:02d}".format(self.__year, self.__month, self.__day);

    def __toInt(self) -> int:
        return self.__year * 10000 + self.__month * 100 + self.__day

    def __eq__(self, other: 'Date') -> bool:
        return self.__toInt() == other.toInt()
    
    def __lt__(self, other: 'Date') -> None:
        return self.__toInt() < other.toInt()
    
    def __ne__(self, o: object) -> bool:
        return not self == o
    def __le__(self, o: object) -> bool:
        return self < o or self == o
    def __gt__(self, o: object) -> bool:
        return not self <= o
    def __ge__(self, o: object) -> bool:    
        return not self < o

    @property
    def year(self) -> int:
        return self.__year

    @property
    def month(self) -> int:
        return self.__month
    
    @property
    def day(self) -> int:
        return self.__day

    @year.setter
    def year(self, e:int) -> None:
        self.__year = e

    @month.setter
    def month(self, e: int) -> None:
        self.__month = e

    @day.setter
    def day(self, e: int) -> None:
        self.__day = e
