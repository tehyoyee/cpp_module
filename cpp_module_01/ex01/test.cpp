#include <iostream>
#include <sstream>
using namespace std;
int main(void)
{
	int num;
	string str = "123 456";
	stringstream stream; 
	stream.str(str);
	while(stream >> num ) cout << num << endl;
}
