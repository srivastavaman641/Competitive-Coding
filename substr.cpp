#include <bits/stdc++.h>
#include <string>
 
using namespace std;
 
typedef unsigned long long ull;
ull far[100001];
ull sumfar[100001];
 
void precompute(const char *const S, int K, int N)
{
	int answer = 0;
	int j = 1;
	int count0, count1;
	count0 = count1 = 0;
 
	if ('1' == S[j])
		count1++;
	else
		count0++;
 
	for (int i = 1; i <= N; i++)
	{
		while (j <= N && count0 <= K && count1 <= K)
		{
			j++;
			if (j > N)
				break;
			if ('1' == S[j])
				count1++;
			else
				count0++;
		}
 
		far[i] = j;
 
		// before starting the next iteration adjust values of counts
		// range will be S[i+1..N]
		if ('1' == S[i])
			count1--;
		else
			count0--;
	}
 
	// pre-compute sumfar
	sumfar[0] = 0;
	for (int i = 1; i <= N; i++)
		sumfar[i] = sumfar[i - 1] + far[i];
 
}
 
ull process_query(ull L, ull R)
{
	int k1 = L - 1;
	int k2 = R + 1;
 
	while (k2 - k1 > 1)
	{
		int km = (k1 + k2) / 2;
		if (far[km] <= R)
			k1 = km;
		else
			k2 = km;
	}
	int k = k1;
 	//cout<<k<<" is low"<<endl;
	return sumfar[k] - sumfar[L - 1] + (R - k)*(R + 1) - (R*(R + 1) / 2 - L*(L - 1) / 2);
}
 
int main()
{
	int T;
	int N, K, Q;
	char S[100001];
	string s;
	ull L, R;
	int i;  // index for S
 
	cin >> T;
	while (T--)
	{
		cin >> N >> K >> Q;
		getchar();
		getline(cin, s);
		// string is indexed starting 1
		for (i = 1; i <= N; i++)
			S[i] = s[i - 1];
 
		S[i] = '\0';
 
		// precompute some important stuff
		precompute(S, K, N);
		while (Q--)
		{
			cin >> L >> R;
			cout << process_query(L, R) << "\n";
		}
	}
 
	return 0;
} 