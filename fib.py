t1, t2, n = map(int, input().split())
fib=[]

fib.append(int(t1))
fib.append(int(t2))
for i in range(3,n+1):
	x=int(fib[i-1])*int(fib[i-1])+int(fib[i-2])
	fib.append(int(x))
print("%d" %fib[n])