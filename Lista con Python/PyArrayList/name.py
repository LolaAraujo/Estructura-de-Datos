class Name:
    def __init__(self, orig: 'Name' = None) -> None:
        self.__first = str()
        self.__last = str()
        
        if orig is not None:
            self.__first = orig.__first
            self.__last = orig.__last

    def __str__(self) -> str:
        return self.__last + ", " + self.__first 

    def __eq__(self, other: 'Name') -> bool:
        return self.__str__() == other.__str()
    
    def __lt__(self, other: 'Name') -> bool:
        return self.__str__() < other.__str()

    def __ne__(self, o: object) -> bool:
        return not self == o
    def __le__(self, o: object) -> bool:
        return self < o or self == o
    def __gt__(self, o: object) -> bool:
        return not self <= o
    def __ge__(self, o: object) -> bool:    
        return not self < o
    
    @property
    def first(self) -> str:
        return self.__first

    @property
    def last(self) -> str:
        return self.__last
    
    @first.setter
    def first(self, e: str) -> None:
        self.__first = e

    @last.setter
    def last(self, e:str) -> None:
        self.__last = e
