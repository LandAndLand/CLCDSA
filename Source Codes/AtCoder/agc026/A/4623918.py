#AGC026 A
'''
??
?????????????10000???
???i??????????ai
?????N?1????????N?2??100??
???????????????????????????????????????????????????????

??
?????????2??????1?
?????????3??????1?
?????????4??????2?
????????????n???????n//2???
?????????????
'''

N = int(input())
A = list(map(int,input().split(' ')))
ans = 0
chain = 1

for i in range(N):
	if i==0:
		continue
	elif A[i]==A[i-1]:
		chain += 1
	elif A[i]!=A[i-1]:
		ans += (chain//2)
		chain = 1
	if i==N-1:
		ans += (chain//2)
		chain = 1		
		
print(ans)