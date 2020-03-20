#pragma warning( disable: 6385 )
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>	  		   
using namespace std;

int main(int argc, char* argv[]) {
	if (argc == 1)
	{
		int i;
		char FILE_IN[50];
		char FILE_OUT[50];

		printf("File name (with extension): ");
		if (scanf_s("%s", FILE_IN, sizeof FILE_IN) != 1) {
			printf("Scanf error!");
			return -1;
		}

		FILE* fin;
		if (fopen_s(&fin, FILE_IN, "rb")) {
			printf("File with given name doesn't exist!");
			return -1;
		}

		fseek(fin, 0, SEEK_END);
		const int fsize = ftell(fin);
		fseek(fin, 0, SEEK_SET);
		unsigned char* fcontent = (unsigned char*)malloc(fsize);
		fread(fcontent, 1, fsize, fin);

		for (i = 0; i < 50 && FILE_IN[i] != '\0' && FILE_IN[i] != '.'; i++)
			FILE_OUT[i] = FILE_IN[i];

		FILE_OUT[i++] = '.';
		FILE_OUT[i++] = 'c';
		FILE_OUT[i] = '\0';

		ofstream fout;
		fout.open(FILE_OUT);
		fout << "/* Embedded file: " << FILE_IN << " */" << endl;
		fout << "const int fsize = " << fsize << endl;
		fout << "const unsigned char *file = {" << endl;

		for (int i = 0; i < fsize; ++i) {
			char buffer[100];
			sprintf_s(buffer, sizeof buffer, "0X%02X%s", fcontent[i], i == fsize - 1 ? "" : ((i + 1) % 16 == 0 ? ",\n" : ","));
			fout << buffer;
		}

		fout << endl << "};" << endl;
		fout.close();
		fclose(fin);
		free(fcontent);
	}
	else if (argc == 2) {
		int i;
		char FILE_IN[50];
		char FILE_OUT[50];

		strcpy_s(FILE_IN, sizeof FILE_IN, argv[1]);

		FILE* fin;
		if (fopen_s(&fin, FILE_IN, "rb")) {
			printf("File with given name doesn't exist!");
			return -1;
		}

		fseek(fin, 0, SEEK_END);
		const int fsize = ftell(fin);
		fseek(fin, 0, SEEK_SET);
		unsigned char* fcontent = (unsigned char*)malloc(fsize);
		fread(fcontent, 1, fsize, fin);

		for (i = 0; i < 50 && FILE_IN[i] != '\0' && FILE_IN[i] != '.'; i++)
			FILE_OUT[i] = FILE_IN[i];

		FILE_OUT[i++] = '.';
		FILE_OUT[i++] = 'c';
		FILE_OUT[i] = '\0';

		ofstream fout;
		fout.open(FILE_OUT);
		fout << "/* Embedded file: " << FILE_IN << " */" << endl;
		fout << "const int fsize = " << fsize << endl;
		fout << "const unsigned char *file = {" << endl;

		for (int i = 0; i < fsize; ++i) {
			char buffer[100];
			sprintf_s(buffer, sizeof buffer, "0X%02X%s", fcontent[i], i == fsize - 1 ? "" : ((i + 1) % 16 == 0 ? ",\n" : ","));
			fout << buffer;
		}

		fout << endl << "};" << endl;
		fout.close();
		fclose(fin);
		free(fcontent);
	}
	else if (argc == 3) {
		char FILE_IN[50];
		char FILE_OUT[50];

		strcpy_s(FILE_IN, sizeof FILE_IN, argv[1]);
		strcpy_s(FILE_OUT, sizeof FILE_OUT, argv[2]);

		FILE* fin;
		if (fopen_s(&fin, FILE_IN, "rb")) {
			printf("File with given name doesn't exist!");
			return -1;
		}

		fseek(fin, 0, SEEK_END);
		const int fsize = ftell(fin);
		fseek(fin, 0, SEEK_SET);
		unsigned char* fcontent = (unsigned char*)malloc(fsize);
		if (!fcontent) {
			printf("Memory allocation error!");
			return -1;
		}
		else
			fread(fcontent, 1, fsize, fin);

		ofstream fout;
		fout.open(FILE_OUT);
		fout << "/* Embedded file: " << FILE_IN << " */" << endl;
		fout << "const int fsize = " << fsize << endl;
		fout << "const unsigned char *file = {" << endl;

		for (int i = 0; i < fsize; ++i) {
			char buffer[40];
			sprintf_s(buffer, sizeof buffer, "0X%02X%s", fcontent[i], i == fsize - 1 ? "" : ((i + 1) % 16 == 0 ? ",\n" : ","));
			fout << buffer;
		}
		fout << "\n};\n";
		fout.close();
		fclose(fin);
		free(fcontent);
	}
	else
	{
		printf("Invalid number of arguments!");
	}

	return 0;
}
