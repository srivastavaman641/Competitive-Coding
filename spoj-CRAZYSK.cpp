t=int(raw_input());
for i in range(t):
	inp=raw_input();
	n,k=inp.split();
	n=long(n);
	k=long(k);
	ans=n;
	while n>0:
		if(n<k):
			break;
		y=n%k;
		ans=ans+(n/k);
		n=(n/k);
		n=n+y;
	print ans;