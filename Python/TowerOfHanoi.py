
def Tower(num,frompeg,topeg,auxpeg):
    Tower.count+=1

    if(num==1):
        print("Moved disk 1 from %s to %s"%(frompeg,topeg))
        return
    else:
        Tower(num-1,frompeg,auxpeg,topeg)
        print("Moved disk %s from %s to %s"%(num,frompeg,topeg))
        Tower(num-1,auxpeg,topeg,frompeg)
        return

Tower.count=0
Tower(10,'A','C','B')
print("Total moves : %s"%(Tower.count))