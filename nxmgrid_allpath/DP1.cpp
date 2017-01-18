// DP1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm> 
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

struct Pos
{
	int x;
	int y;

	bool operator<(const Pos &p1) const
	{
		if (x < p1.x) return true;

		if (x == p1.x)
		{
			if (y < p1.y) return true;
		}

		return false;
	}


	string to_str()
	{
		stringstream ss;
		ss << "x = " << x << ", y = " << y;
		return ss.str();
	}
};

typedef vector<Pos> Path;
int rows = 3;
int cols = 4;

// 达到x,y， 当前的path值
void f(int x, int y, Path path)
{
	if (x >= cols || y >= rows)
	{
		return;
	}

	if ((x == (cols - 1)) && (y == (rows - 1)))
	{
		vector<Pos>::iterator  it;
		for (it = path.begin(); it != path.end(); it++)
		{
			std::cout << it->to_str() << "--->";
		}

		std::cout << std::endl;
	}

	Pos pt;

	if (x + 1 < cols)
	{
		Path tmpPath(path.begin(), path.end());
		pt.x = x + 1;
		pt.y = y;
		tmpPath.push_back(pt);
		f(x + 1, y, tmpPath);
	}

	if (y + 1 < rows)
	{
		Path tmpPath(path.begin(), path.end());
		pt.x = x;
		pt.y = y + 1;

		tmpPath.push_back(pt);
		f(x, y + 1, tmpPath);
	}
}

int main()
{
	Path path;
	Pos  pt;
	pt.x = 0;
	pt.y = 0;
	path.push_back(pt);
	f(0, 0, path);

    return 0;
}

