#include <iostream>
#include<cstdlib>
#include<ctime>
//random number generator
using namespace std;

int main() {
	int l=2,h=8;
	srand(time(0));
	cout<<(l+(rand()%(h-l+1)));
	return 0;
}
