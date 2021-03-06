#!/usr/bin/env python
#-*- coding:utf-8 -*-

import sys, math, random, operator
from string import ascii_lowercase, ascii_uppercase
from fractions import Fraction, gcd
#from decimal import Decimal, getcontext
from itertools import product, permutations, combinations
from Queue import Queue, PriorityQueue
from collections import deque, defaultdict, Counter
#getcontext().prec = 100

MOD = 10**9 + 7
INF = float("+inf")

if sys.subversion[0] == "PyPy":
    import io, atexit
    sys.stdout = io.BytesIO()
    atexit.register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))
    sys.stdin = io.BytesIO(sys.stdin.read())
    raw_input = lambda: sys.stdin.readline().rstrip()
pr = lambda *args: sys.stdout.write(" ".join(str(x) for x in args) + "\n")
epr = lambda *args: sys.stderr.write(" ".join(str(x) for x in args) + "\n")
die = lambda *args: pr(*args) ^ exit(0)

read_str = raw_input
read_strs = lambda: raw_input().split()
read_int = lambda: int(raw_input())
read_ints = lambda: map(int, raw_input().split())
read_float = lambda: float(raw_input())
read_floats = lambda: map(float, raw_input().split())

"---------------------------------------------------------------"


def rec(cur, cnts, p):
    key = (cur, tuple(cnts), p)
    if key not in cache:
        ans = 0
        for rem in xrange(1, p):
            if cnts[rem]:
                cur2 = (cur + rem) % p
                curans = int(cur2 == 0)
                cnts2 = cnts[::]
                cnts2[rem] -= 1
                curans += rec(cur2, cnts2, p)
                ans = max(ans, curans)
        if max(cnts[1:]) == 0 and cur != 0:
            ans = 1
        cache[key] = ans
    return cache[key]

def solve(n, p, arr):
    arr = sorted(x % p for x in arr)
    ans = arr.count(0)
    arr = [x for x in arr if x]
    cnts = [None] + [arr.count(i) for i in xrange(1, p)]
    # epr(ans, cnts, p)
    return ans + rec(0, cnts, p)

t = read_int()
for j in xrange(t):
    cache = {}
    n, p = read_ints()
    arr = read_ints()
    ans = solve(n, p, arr)
    print "Case #%d: %s" % (j+1, ans)
