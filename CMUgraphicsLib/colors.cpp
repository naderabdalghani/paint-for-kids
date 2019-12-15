/*
See "version.h" for version info and copyright information
This file was last modified on 05.16.1999
*/

#include "colors.h"

bool operator==(color a, color b) {

	return ((a.ucRed == b.ucRed) && (a.ucGreen == b.ucGreen) && (a.ucBlue == b.ucBlue));

}

bool operator!=(color a, color b) {

	return !(a == b);

}

string color::Color2String() const
{
	if (*this == RED) return "RED";
	if (*this == BLUE) return "BLUE";
	if (*this == BLACK) return "BLACK";
	if (*this == WHITE) return "WHITE";
	if (*this == GREEN) return "GREEN";
	if (*this == DARKRED) return "DARKRED";
	if (*this == LIGHTBLUE) return "LIGHTBLUE";
	if (*this == PINK) return "PINK";
	if (*this == ORANGE) return "ORANGE";
	if (*this == YELLOW) return "YELLOW";
	return "InValid";
}

void color::String2Color(string s) 
{
	if (s == "RED") *this=RED;
	if (s == "BLUE") *this = BLUE;
	if (s == "BLACK") *this = BLACK;
	if (s == "WHITE") *this = WHITE;
	if (s == "GREEN") *this = GREEN;
	if (s == "DARKRED") *this = DARKRED;
	if (s == "LIGHTBLUE") *this = LIGHTBLUE;
	if (s == "PINK") *this = PINK;
	if (s == "ORANGE") *this = ORANGE;
	if (s == "YELLOW") *this = YELLOW;
}
