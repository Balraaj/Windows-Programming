class MatrixException(BaseException):
    def __init__(self,type):
        self.type=type


class Matrix:
    def __init__(self,rows,columns):
        self.ROWS=rows
        self.COLUMNS=columns
        self.list=[]
        for i in range(rows):
            self.list.append([])

    def getdata(self):
        for i in range(self.ROWS):
            for j in range(self.COLUMNS):
                self.list[i].append(input("Enter a value : "))

    def showdata(self):
        for i in range(self.ROWS):
            for j in range(self.COLUMNS):
                print("%3s"%(self.list[i][j]),end='')
            print()

    def __add__(self, other):
        temp = Matrix(self.ROWS, self.COLUMNS)
        if (self.ROWS==other.ROWS)and(self.COLUMNS==other.COLUMNS):
            for i in range(self.ROWS):
                for j in range(self.COLUMNS):
                    temp.list[i].append(str(int(self.list[i][j])+int(other.list[i][j])))

        else:
            pass

        return temp

    def __mul__(self, other):
        temp=Matrix(self.ROWS,other.COLUMNS)
        if(self.COLUMNS==other.ROWS):
            for i in range(self.ROWS):
                for j in range(other.COLUMNS):
                    sum=0
                    for k in range(self.COLUMNS):
                        sum+=int(self.list[i][k])*int(other.list[k][j])

                    temp.list[i].append(str(sum))
        else:
            raise MatrixException("Row Column mismatch")
        return temp

    def transpose(self):
        temp=Matrix(self.COLUMNS,self.ROWS)
        for i in range(self.COLUMNS):
            for j in range(self.ROWS):
                temp.list[i].append(str(self.list[j][i]))

        return temp

obj=Matrix(2,2)
obj.getdata()
obj1=Matrix(2,3)
obj1.getdata()
print()
print()
print("First matrix is : ")
obj.showdata()
print("\n\nSecond matrix is : ")
obj1.showdata()

obj3=obj*obj1
print("\n\nResult is : ")
obj3.showdata()





