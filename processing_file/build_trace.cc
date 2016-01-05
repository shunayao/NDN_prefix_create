#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;



const int LEN = 37; // 26 + 10 + 1
char g_arrCharElem[LEN] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                           'a', 'b', 'c', 'd', 'e', 'f', 'g',
                           'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                           's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '-'
                          };

int main(int argc, char const *argv[])
{
	srand((unsigned)time(0));
	ifstream infile;
	const char *in_name = argv[1];

	ofstream outfile;
	const char *out_file = argv[2];
	outfile.open(out_file);
	char *buf = new char[256];
	int round = atoi(argv[3]);
	while (round)
	{
		infile.open(in_name);
		while (infile.getline(buf, 256))
		{
			outfile << buf;
			int iMax = 0;
			iMax = rand() % 3 + 1; //the number of components
			for (int i = 0; i < iMax; i++) {
				int iLen = 0;
				iLen = rand() % 10 + 1; //the string's length of every component

				char* szStr = new char[iLen + 1];
				szStr[iLen] = '\0';
				int iRand = 0;
				for (int i = 0; i < iLen; ++i)
				{
					iRand = rand() % LEN;            // iRand = 0 - 36
					szStr[i] = g_arrCharElem[iRand];
				}
				outfile << "/" << szStr;
				delete[] szStr;
			}
			outfile << endl;
		}
		round--;
		infile.close();
	}
	
	delete[] buf;
	outfile.close();
	return 0;
}