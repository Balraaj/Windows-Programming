#This program solves the maximum subarray problem

def find_max_crossing_subarray(a,low,mid,high):
    left_sum = -10000
    sum = 0
    max_left = mid
    for i in range(mid,low-1,-1):
        sum = sum+a[i]
        if(sum > left_sum):
            left_sum = sum
            max_left = i


    right_sum = -10000
    sum = 0
    max_right = mid+1
    for j in range(mid+1,high+1):
        sum = sum + a[j]
        if(sum > right_sum):
            right_sum = sum
            max_right = j

    return (max_left,max_right,left_sum+right_sum)


def find_max_subarray(a,low,high):
    if(low==high):
        return(low,high,a[low])
    else:
        mid = (low+high)//2
        (left_low,left_high,left_sum) = find_max_subarray(a,low,mid)
        (right_low,right_high,right_sum)=find_max_subarray(a,mid+1,high)
        (cross_low,cross_high,cross_sum)=find_max_crossing_subarray(a,low,mid,high)

        if((left_sum >= right_sum)and(left_sum >= cross_sum)):
            return (left_low,left_high,left_sum)
        elif((right_sum >= left_sum)and(right_sum >= cross_sum)):
            return(right_low,right_high,right_sum)
        else:
            return(cross_low,cross_high,cross_sum)


mylist = [8,-5,6,-5,-7,4,5,-3,9,9]
(low,high,sumsub)=find_max_subarray(mylist,0,9)

print("Low is : "+str(low))
print("\nHigh is : "+str(high))
print("\nSum is : "+str(sumsub))