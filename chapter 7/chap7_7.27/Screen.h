//Exercise 7.27: Add the move, set, and display operations to your
//version of Screen.Test your class by executing the following code :
//Click here to view code image
//Screen myScreen(5, 5, 'X');
//myScreen.move(4, 0).set('#').display(cout);
//cout << "\n";
//myScreen.display(cout);
//cout << "\n";

//Output:
//
//XXXXXXXXXXXXXXXXXXXX#XXXX
//XXXXXXXXXXXXXXXXXXXX#XXXX
#pragma once
#include<string>
class Screen {
public:
	typedef std::string::size_type pos;
	//constructors
	Screen() = default;
	Screen(pos ht, pos wd) :height(ht), width(wd),contents(ht*wd,' ') {}
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht* wd, c) {}
	//functions
	Screen &display(std::ostream& os) { do_display(os); return *this; }
	const Screen &display(std::ostream& os) const { do_display(os); return *this;}
	Screen& set(char);
	Screen& set(pos, pos, char);
	char get()const { return contents[cursor]; }
	inline char get(pos ht, pos wd)const;
	Screen& move(pos r, pos c);

private:
	void do_display(std::ostream& os) const { os << contents; }
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};
inline Screen& Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}
inline Screen& Screen::set(pos r, pos col, char ch) {
	contents[r * width + col] = ch;
	return *this;
}
inline Screen& Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}
char Screen::get(pos r, pos c) const {
	pos row = r * width;
	return contents[row + c];
}