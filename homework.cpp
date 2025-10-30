•	#include <iostream>
•	using namespace std;
•
•	int countVowels(const char* p) {
	•	    int count = 0;
	•	    while (*p) {
		•	        char ch = tolower(*p);
		•	        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
			•	            count++;
			•
		}
		•	        p++;
		•
	}
	•	    return count;
	•
}
•
•	int main() {
	•	    string str;
	•	    getline(cin, str);
	•	    cout << "Number of vowels: " << countVowels(str.c_str()) << endl;
	•	    return 0;
	•
}
•	#include <iostream>
•	#include <iomanip>
•	using namespace std;
•
•	inline double square(double x) {
	•	    return x * x;
	•
}
•
•	double power(double base, int exponent = 2) {
	•	    double result = 1.0;
	•	    for (int i = 0; i < exponent; i++) {
		•	        result *= base;
		•
	}
	•	    return result;
	•
}
•
•	double calc(double a, double b, char op) {
	•	    switch (op) {
	•	        case '+': return a + b;
	•	        case '-': return a - b;
	•	        case '*': return a * b;
	•	        case '/':
		•	            if (b == 0) {
			•	                cout << "Error: divide by zero" << endl;
			•	                return 0;
			•
		}
		•	            return a / b;
	•	        default: return 0;
					   •
	}
	•
}
•
•	double calc(int a, int b, char op) {
	•	    return calc(static_cast<double>(a), static_cast<double>(b), op);
	•
}
•
•	int main() {
	•	    double a, b;
	•	    char op;
	•	    cin >> a >> b >> op;
	•
		•	    cout << fixed << setprecision(2);
	•	    cout << "square(" << a << ") = " << square(a) << endl;
	•	    cout << "power(" << a << ",3) = " << power(a, 3) << endl;
	•
		•	    if (op == '/' && b == 0) {
		•	        cout << "Error: divide by zero" << endl;
		•
	}
		else {
		•	        cout << a << " " << op << " " << b << " = " << calc(a, b, op) << endl;
		•
	}
	•
		•	    return 0;
	•
}
•	#include <iostream>
•	using namespace std;
•
•	void swap(int& x, int& y) {
	•	    int temp = x;
	•	    x = y;
	•	    y = temp;
	•
}
•
•	int main() {
	•	    int x, y;
	•	    cin >> x >> y;
	•
		•	    cout << "Before swap: x=" << x << ", y=" << y << endl;
	•	    swap(x, y);
	•	    cout << "After swap: x=" << x << ", y=" << y << endl;
	•
		•	    return 0;
	•
}
