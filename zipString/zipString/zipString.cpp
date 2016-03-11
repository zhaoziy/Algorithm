// zipString.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
using namespace std;

class Zipper {
public:
	string zipString(string iniString) {
		// write code here
		int start = 0;
		int end = 0;
		int i = 0;
		int size = (int)iniString.size();
		string ret;
		while (i < size)
		{
			if (iniString[i] == iniString[start])
			{
				i++;
			}
			else
			{
				end = i - 1;
				ret += iniString[start];
				ret += to_string(end - start + 1);
				start = i;
				i++;
			}
		}
		end = i - 1;
		ret += iniString[start];
		ret += to_string(end - start + 1);
		int temp = (int)ret.size();
		if (temp > size)
		{
			return iniString;
		}
		else
		{
			return ret;
		}
	}
};

int main()
{
	string  a = "jjjjjjxxxxxxxooZLLLLLLLLQQQQQQQQQLLLLLLLLECXXXXXXXIIIIIIIIIhjjyyySSooooooooommmuuEEEEEEEEEnnnnnnnffffffAAAAAllllllllbbbbkkkkkkkkkkkkKKKKKKhhhhhhhhhooooooooooYCCCCCCOOOOOOOOOMMMMMMMMMMiiiiiivvvvvvvWWWWkkkkkkwwwwwwwMmmmmmmmmLLLwwwwwwwkkkjjjjjjttttQQQQQQQQQaaaaaaaFFFFFFFlllllllllggggggggggPPPPPPuuuuuuuuaYYYYYYwQQQFFFFFFFFFFaaaaapXXXXXXXxxxxxxQQQQQQQQQsssssGGGGfffffffddddddpppQQQQQQHHHTTTaaaaaaGGGGGGddyyyyyMhhllllllllllNNNNNNNNUUUWWWWWWLLLLLLLLLYYYYYYYYYYTTKKKKKKKKiiiiiiitttttttXXXXXXXXXLLLHZZZZZZZssssjjJJJEEEEEOOOOOttttttttttBBttttttTTTTTTTTTTrrrrttttRRRRRyyooooooaaaaaaaaarrrrrrrPPPPPPPjjPPPPddddddddddHHHHnnnnnnnnnnSSSSSSSSSSzzHHHHHHHHHddddddDDDzzzhhhhhfffffffffftttttteeeeeeeeEEEEEEEEEaaaaaaccccccccccFFFFFFFF";
	Zipper z;
	z.zipString(a);
    return 0;
}

