import sys
import random



n = int(sys.argv[1])
k = int(sys.argv[2])


print 'n is: ' + str(n)
print 'k is: ' + str(k)

if k > n:
    raise Exception('k cannot be greater than n')

s = [int(1000*random.random()) for i in xrange(n)]
orig = set(s)
p = float(k) / float(n)

r = set()
for x in range(0,k):
    el = random.choice(s)
    s.remove(el)
    r.add(el)

print "s is: " + str(orig)
print "r is: " + str(r)
