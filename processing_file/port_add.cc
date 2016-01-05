/*
Usage: ./port_add in_name out_name
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

int main(int argc, char const *argv[])
{
	srand((unsigned)time(0));
	ifstream infile;
	const char *in_name = argv[1];
	infile.open(in_name);
	ofstream outfile;
	const char *out_file = argv[2];
	outfile.open(out_file);
	char* buf = new char[256];
	while (infile.getline(buf, 256)) {
		outfile << buf << "," << rand() % 5999 + 1 << endl;

	}
	delete[] buf;
	infile.close();
	outfile.close();
	return 0;
}