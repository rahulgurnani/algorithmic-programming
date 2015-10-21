#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::string;

int main() {
	// c style string input with spaces in words 
    char c[100];
	scanf("%[^\n]s", c);
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        cout << "Input String: " << s << "\n";
    }
    return 0;
}