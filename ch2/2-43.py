import sys
import random



n = int(sys.argv[1])
k = int(sys.argv[2])


print 'n is: ' + str(n)
print 'k is: ' + str(k)

if k > n:
    raise Exception('k cannot be greater than n')

s = [int(1000*random.random()) for i in xrange(n)]
p = float(k) / float(n)

r = set()
recur = True
while recur:
    for x in s:
        if random.random() < p:
            r.add(x)
            if(len(r) == k):
                recur = False
                break

print "s is: " + str(s)
print "r is: " + str(r)
