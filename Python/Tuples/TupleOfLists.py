"""This program demonstrates how a lists and tuples can contain """

l1=[]
l2=[]
t1=(1,2,3,4,5)

mytuple=(l1,l2,t1) #creating a tuple of lists and tuple
mytuple=mytuple+("hari",) #adding a new element to tuple, in this case a new tuple is created with
                            #containts of old tuple and ("hari",)

mytuple[0].append(100)#although tuples are immutable, if they have lists as elements , those lists
                        #can be updated
mytuple[1].append(200)
print(mytuple)