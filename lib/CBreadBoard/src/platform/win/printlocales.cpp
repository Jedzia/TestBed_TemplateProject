//
// Created by Jedzia on 22.11.2019.
//


#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ostream>
#include <iterator>


using namespace std;

vector<wstring> locals;

BOOL CALLBACK MyFuncLocaleEx(LPWSTR pStr, DWORD dwFlags, LPARAM lparam) {
    locals.push_back(pStr);
    return TRUE;
}

int printLocales() {
    EnumSystemLocalesEx(MyFuncLocaleEx, LOCALE_ALL, NULL, NULL);

    for (vector<wstring>::const_iterator str = locals.begin(); str != locals.end(); ++str)
        wcout << *str << endl;

    wcout << "Total " << locals.size() << " locals found." << endl;

    return 0;
}
