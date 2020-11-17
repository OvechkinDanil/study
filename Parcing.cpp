#include "Parcing.h"
void split(const string& str, vector<string>& tokens, const string& delimiters = " ")
{
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	string::size_type pos = str.find_first_of(delimiters, lastPos);
	tokens.push_back(str.substr(lastPos, pos - lastPos));
	lastPos = str.find_first_not_of(delimiters, pos);
	pos = str.size();
	tokens.push_back(str.substr(lastPos, pos));
}
void TextParcing(string filename)
{
	int i;
	string str;
	double x = 0, y = 3.8;
	vector<string> s, submenu;
	ifstream input(filename);
	while (!input.eof())
	{
		std::getline(input, str);
		split(str, submenu, " ");
		MenuItem it(NULL, x, y, submenu.front(), 0);
		if (submenu.back()[0] == '[')
			it.AddSubMenuItems(FindSubMenu(&it, submenu.back()));
		menu.AddNewMenuItem(it);
		y -= 0.6;
	}
}