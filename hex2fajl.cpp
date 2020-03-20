#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>	  		   
using namespace std;

#include "fajl.cpp"

int main() {

	ofstream kopija("kopija.png", ios::out | ios::binary);

	for (int i = 0; i < fsize; i++)
		kopija << file[i];

	kopija.close();

	return 0;
}
