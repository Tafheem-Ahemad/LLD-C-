#pragma once
#include <bits/stdc++.h>
using namespace std;

enum Symbol{
	X ,
	O ,
	EMPTY 
};

// when I write Symbol.toString(Symbol status) it will return the string representation of the enum value
inline std::ostream& operator<<(std::ostream& os, const Symbol& status) {
    return os << toString(status);
}
string toString(Symbol status) {
    switch (status) {
        case Symbol::X: return "X";
        case Symbol::O: return "O";
        case Symbol::EMPTY: return ".";
    }
    return "";
}