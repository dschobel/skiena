import sys

def mystery(n):
    r = 0
    for i in range(1,n):
        for j in range(i+1,n+1):
            for k in range(1,j+1):
                r = r+1
    return r

n = int(sys.argv[1])
print "myster(" + str(n)+  ") = " + str(mystery(n))
