#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

int main(int argc, char const *argv[])
{
	srand((unsigned)time(0));
	const char*read_file = argv[1];
	const char*write_file = argv[2];
	const char*number = argv[3];
	int num = atoi(number);
	ifstream infile;
	infile.open(read_file);
	ofstream outfile;
	outfile.open(write_file);
	char* buf = new char[256];
	int line = 0;
	while (infile.getline(buf, 256) && line < num) {
		outfile << buf <<  endl;
		line++;
	}
	delete[] buf;
	infile.close();
	outfile.close();
	return 0;
}