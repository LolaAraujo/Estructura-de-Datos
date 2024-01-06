from .date import Date
from .name import Name

class Student:
    def __init__(self, orig: 'Student' = None) -> None:

        self.__code = str()
        self.__name = Name()
        self.__birthDate = Date()
        self.__career = str()
        self.__startDate = Date()
        self.__grade = float()

        if orig is not None:
            self.__code = orig.__code
            self.__name = orig.__name
            self.__birthDate = orig.__birthDate
            self.__career = orig.__career
            self.__startDate = orig.__startDate
            self.__grade = orig.__grade
    
    def __str__(self) -> str:
        r = ""

        r+= self.__code + " | "
        r+= str(self.__name) + " | "
        r+= str(self.__birthDate) + " | "
        r+= self.__career + " | "
        r+= str(self.__startDate) + " | "
        r+= "{:0.2f}".format(float(self.__grade))

        return r
    
    def __eq__(self, other: 'Student') -> bool:
        return self.__code == other.__code

    def __lt__(self, other: 'Student') -> bool:
        return self.__code < other.__code

    def __ne__(self, o: object) -> bool:
        return not self == o
    def __le__(self, o: object) -> bool:
        return self < o or self == o
    def __gt__(self, o: object) -> bool:
        return not self <= o
    def __ge__(self, o: object) -> bool:    
        return not self < o

    @property
    def code(self) -> str:
        return self.__code

    @property
    def name(self) -> Name:
        return self.__name

    @property
    def birthDate(self) -> Date:
        return self.__birthDate

    @property
    def career(self) -> str:
        return self.__career

    @property
    def startDate(self) -> Date:
        return self.__startDate

    @property
    def grade(self) -> float:
        return self.__grade

    @code.setter
    def code(self, e: str) -> None:
        self.__code = e

    @name.setter
    def name(self, e: Name) -> None:
         self.__name = e

    @birthDate.setter
    def birthDate(self, e: Date) -> None:
         self.__birthDate = e

    @career.setter
    def career(self, e: str) -> None:
         self.__career = e

    @startDate.setter
    def startDate(self, e: Date) -> None:
         self.__startDate = e

    @grade.setter
    def grade(self, e: float) -> None:
         self.__grade = e
