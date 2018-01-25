#include <fstream>
#include "Aho-Croasick.h"
int main(int argc, char* argv[])
{
	std::ifstream fin(argv[1]);
	std::vector<std::string> strs;
	std::string pat, text;
	while (!fin.eof())
	{
		fin >> pat >> text;
	}
	AhoCroasick aho;
	aho.Build(pat);
	aho.Build("cd");
	aho.construct_fail();
	aho.Recognize(text);
	int c = aho.GetCount();
	return 0;
}
