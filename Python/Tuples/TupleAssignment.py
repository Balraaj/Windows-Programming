"""This program demonstrates how tuple assignment works and how two variables can be swapped using
   tuple assignment, same results can be achieved by using list [ ]"""


b=("Balraj","MCA","USICT") #Tuple packing, three values are packed into one variable b

(name,course,collage)=b    #Tuple unpacking, b is unpacked and than its three values are assigned to
                           #three variables on the left

print(name)
print(course)
print(collage)

a=10
b=20

a,b=b,a #Swapping is done by the means of tuple assignment,right hand side is evaluted before
        #assignment

print(a)
print(b)