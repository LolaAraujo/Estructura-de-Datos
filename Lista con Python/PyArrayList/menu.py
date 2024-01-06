from .name import Name
from .date import Date
from .student import Student
from .list import List

class Menu:
    def __init__(self, l: List):
        myStudent = Student()
        myDate = Date()
        myName = Name()

        cont = True

        while cont:
            myStudent.code = input("Codigo: ")

            myName.last = input("Apellido(s): ")
            myName.first = input("Nombre(s): ")

            myStudent.name = myName

            myString = input("Fecha de nacimieto (AAAA/MM/DD): ")
            myDate.year, myDate.month, myDate.day = map(int,  myString.split('/'))
            
            myStudent.birthDate = myDate

            myStudent.career = input("Carrera: ")

            myString = input("Fecha de nacimieto (AAAA/MM/DD): ")
            myDate.year, myDate.month, myDate.day = map(int,  myString.split('/'))
            
            myStudent.startDate = myDate

            myStudent.grade = input("Promedio: ")
            
            l.insertData(l.getLastPos(), myStudent)

            print("Elemento insertado:\n" + str(myStudent) + "\n")

            op = input("Insertar otro? (s/n): ")

            if op == "n":
                cont = False

        print("\n\nContenido de la lista: \n")
        print (l)

        print("\n\nOrdenando...: \n")
        l.mergeSort()

        print("\n\nContenido de la lista: \n")
        print(l)


