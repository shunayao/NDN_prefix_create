#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

int main(int argc, char const *argv[])
{
	srand((unsigned)time(0));
	const char* read_file = argv[1];
	const char* read_file1 = argv[2];
	const char* combined_file = argv[3];
	ifstream infile;
	infile.open(read_file);
	ifstream infile1;
	infile1.open(read_file1);
	ofstream outfile;
	outfile.open(combined_file);
	char* buf = new char[256];

	while (infile.getline(buf, 256)) {
		outfile << buf <<  endl;
	}

	infile.close();

	while (infile1.getline(buf, 256)) {
		outfile << buf <<  endl;
	}

	infile1.close();
	delete[] buf;
	outfile.close();
	return 0;
}