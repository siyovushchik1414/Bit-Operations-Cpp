#include <iostream>
using namespace std;

int sum(int x, int y)
{
	int c, d;
	while (y != 0) {
		c = x ^ y;
		d = (x & y) << 1;
		x = c;
		y = d;
	}
	cout << x;
	return 0;
}
int subt(int x, int y){
    while(y!=0){
        int borrow = (~x) & y;
        x = x ^ y;
        y = borrow << 1;
    }
    cout << x << " ";
    return x;
}
int mult(int x, int y) {
	int result = 0;
	int sign = 1;
	if ((x < 0 && y>0) || (x > 0 && y < 0)) sign = -1;
	x = abs(x);
	y = abs(y);
	while (y != 0) {
		if (y & 1) result += x;
		x = x << 1;
		y = y >> 1;
	}
    cout << result << " ";
	return sign * result;
}
int division(int x, int y) {
    int sign = 1;
    if ((x < 0 && y>0) || (x > 0 && y < 0)) sign = -1;
    x = abs(x);
    y = abs(y);
    int n = 0;
    while (x >= y) {
        int save = y;
        while (y != 0) {
            int borrow = (~x) & y;
            x = x ^ y;
            y = borrow << 1;
        }
        y = save;
        n++;
    }
    cout << division(x,y) << " ";
    return sign * n;
}
int power(int x, int y, int n) {
    int sign = 1;
    if (y < 0 && n % 2 == 1) sign = -1;
    y = abs(y);
    int result = 0;
    while (y != 0) {
        if (y & 1) result += x;
        x = x << 1;
        y = y >> 1;
    }
    return sign * result;
}

int main()
{
    int a, b, n, p;
    cout << "Enter Your Elements: A = ";
    cin >> a;
    cout << "and B = ";
    cin >> b;
    int h;
    cout << "Choose Your Option: 1(+), 2(-), 3(*), 4(/), 5(^): ";
    cin >> h;
    switch (h)
    {
    case 1: sum(a, b); break;
    case 2: subt(a, b); break;
    case 3: mult(a, b); break;
    case 4: division(a, b); break;
    case 5: p = 1; for (int i = 0; i < b; i++) { p = power(p, a, b); } cout << "A Times B = " << p << "\n"; break;
    }
}
