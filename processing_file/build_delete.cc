#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	ifstream infile;
	const char* in_file_name = argv[1];
	const char* out_file_name = argv[2];
	infile.open(in_file_name);
	ofstream outfile;
	outfile.open(out_file_name);
	char* buf = new char[256];
	char* buf1 = new char[256];
	while (infile.getline(buf, 256)) {
		sscanf(buf, "%[^,]", buf1);
		outfile << buf1 << endl;

	}
	delete[] buf;
	delete[] buf1;
	infile.close();
	outfile.close();
	return 0;
}