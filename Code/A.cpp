#include <bits/stdc++.h>

using i64 = long long;

class Solve
{
public:
	Solve(std::string t) : t(t) {}
	std::string decode()
	{
		for (int i = 0; i < t.size(); i++)
			t[i] = t[i] - '!' + ' ';
		return t;
	}
	std::string encryption()
	{
		std::string res;
		std::reverse(t.begin(), t.end());
		for (int i = 0; i < t.size(); i++)
			t[i] = t[i] - ' ' + '!';
		return t;
	}
	
private:
	std::string t;
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::string s;
	std::cin >> s;
	
	Solve solve(s);
	std::cout << solve.decode() << '\n';
	std::cout << solve.encryption() << '\n';
	
	return 0;
}
