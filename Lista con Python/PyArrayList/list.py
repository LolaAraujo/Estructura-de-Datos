import copy

class List:
    def __init__(self, orig: 'List' = None) -> None:
        if orig is None:
            self.__data = []
            self.__last = -1
        else:
            self.__copyAll(orig)

    def __isValidPos(self, p: int) -> bool:
        return p >= 0 and p <= self.__last

    def __copyAll(self, l: 'List') -> None:
        i = 0
        while i <= l.__last:
            self.__data[i] = l.__data[i]
            i+= 1

        self.__last = l.last

    def __swapData(self, a: int, b: int) -> None:
        aux = self.__data[a]
        self.__data[a] = self.__data[b]
        self.__data[b] = aux
    
    def __mergeSort(self, left: int, right: int, temp: object) -> None:
        print ("left: " + str(left) + " right: " + str(right) + "\n")
        if left >= right:
            return
        
        m = int((left + right) / 2)

        self.__mergeSort(left, m, temp)
        self.__mergeSort(m + 1, right, temp)

        x = left
        while x <= right:
            temp[x] = self.__data[x]
            
            x+=1

        i = x = left
        j = m + 1

        while i <= m and j <= right:
            while i<= m and temp[i] <= temp[j]:
                self.__data[x] = temp[i]
                i+= 1
                x+= 1
            
            if i <= m:
                while j <= right and temp[j] <= temp[i]:
                    self.__data[x] = temp[j]
                    j+= 1
                    x+= 1
        
        while i<= m:
            self.__data[x] = temp[i]
            i+= 1
            x+= 1
            
        while j <= right:
            self.__data[x] = temp[j]
            j+= 1
            x+= 1

    def __quickSort(self, left: int, right: int) -> None:
        if left >= right:
            return
        
        i = left
        j = right

        while i < j:
            while i < j and self.__data[i] <= self.__data[right]:
                i+= 1

            while i < j and self.__data[j] >= self.__data[right]:
                j-= 1

            if(i != j):
                self.__swapData(i, j)

        if i != right:
            self.__swapData(i, right)

        self.__quickSort(left, i - 1)
        self.__quickSort(i + 1, right)

    def __str__(self) -> str:
        r = ""
        i = 0

        while i <= self.__last:
            r+= str(self.__data[i]) + "\n"

            i+= 1

        return r

    def isEmpty(self) -> bool:
        return self.__last == -1

    def insertData(self, p: int, e: object) -> None:
        if p != -1 and not self.__isValidPos(p):
            raise Exception("Invalid position: {:d}".format(p))
        
        self.__data.append(None)

        i = self.__last
        while i < p:
            self.__data[i + 1] = self.__data[i]
            i+= 1
        
        self.__data[p + 1] = copy.deepcopy(e)
        self.__last+= 1

    def deleteData(self, p: int) -> None:
        if self.__isValidPos(p):
            raise Exception("Invalid position: {:d}".format(p))

        i = p
        while p < self.__last:
            self.__data[p] = self.__data[p + 1]
            i-= 1
        
        self.__data.pop(self.__last)
        self.__last-= 1

    def getFirstPos(self) -> int:
        if self.isEmpty():
            return -1

        return 0

    def getLastPos(self) -> int:
        return self.__last

    def getPrevPos(self, p: int) -> int:
        if p == 0 or not self.__isValidPos(p):
            return -1

        return p - 1

    def getNextPos(self, p: int) -> int:
        if p == self.__last or not self._isValidPos(p):
            return -1
        
        return p + 1
    
    def retrieve(self, p: int) -> object:
        if not self.__isValidPos(p):
            raise Exception("Invalid position: {:d}".format(p))
        
        return self.__data[p]

    def linearSearch(self, e: object) -> int:
        i = 0

        while i <= self.__last:
            if self.__data[i] == e:
                return i

            i+= 1
        
        return -1
    
    def binarySearch(self, e: object) -> int:
        i = 0
        j = self.__last

        while i <= j:
            m = (i + j) / 2

            if self.__data[m] == e:
                return m

            if e < self.__data[m]:
                j = m - 1
            else:
                i = m + 1
        
        return -1

    def bubbleSort(self) -> None:
        i = self.__last
        cont = True

        while cont:
            flag = False
            j = 0

            while j < i:
                if self.__data[j] > self.__data[j + 1]:
                    self.__swapData(j, j + 1)
                    flag =  True
                
                j+= 1
            
            i-= 1

            cont = flag

    def shellSort(self) -> None:
        gapSeries = [510774,227011,100894,44842,19930,8858,3937,1750,701,301,132,57,23,10,4,1,0]
        gapPos = 0
        gap = gapSeries[gapPos]

        while gap > 0:
            i = gap

            while i <= self.__last:
                j = i

                while j >= gap and self.__data[j - gap] > self.__data[j]:
                    self.__swapData(j - gap, j)

                    j-= gap

                i+= 1

            gapPos+= 1
            gap = gapSeries[gapPos]

    def mergeSort(self) -> None:
        temp = [None] * (self.__last + 1)
        self.__mergeSort(0, self.__last, temp)
    
    def quickSort(self) -> None:
        self.__quickSort(0, self.__last)

    def deleteAll(self) -> None:
        self.__data=None

        self.__last = -1
