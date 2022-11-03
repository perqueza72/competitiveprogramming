#include <bits/stdc++.h>

using namespace std;

int grafo[40][40][40];
int dx, dy, dz;
int BLOCK = -1;

struct Point
{
	int x;
	int y;
	int z;
	int dist;

	Point(const int &x, const int &y, const int &z, const int &dist = 0)
	{
		this->Set(x, y, z, dist);
	}

	void Set(const int &x, const int &y, const int &z, const int &dist = 0)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->dist = dist;
	}

	Point() {}

	void operator()(const int &x, const int &y, const int &z, const int &dist = 0)
	{
		this->Set(x, y, z, dist);
	}

	void operator=(const Point &p)
	{
		x = p.x;
		y = p.y;
		z = p.z;
		dist = p.dist;
	}

	bool operator==(const Point &p)
	{
		if (x != p.x)
			return false;
		if (y != p.y)
			return false;
		if (z != p.z)
			return false;
		return true;
	}

	int *Value()
	{
		if (x < 0 || y < 0 || z < 0)
			return &BLOCK;
		if (x >= dx || y >= dy || z >= dz)
			return &BLOCK;
		return &grafo[x][y][z];
	}

	void Print()
	{
		printf("x: %d, y: %d, z: %d, dist: %d\n", x, y, z, dist);
	}
};

Point finish, ini;

const int equis[6] = {1, 0, 0, -1, 0, 0};
const int yes[6] = {0, 1, 0, 0, -1, 0};
const int zeta[6] = {0, 0, 1, 0, 0, -1};

void solve()
{
	deque<Point> q;
	Point p, *aux;
	q.push_back(ini);
	int *value;
	while (q.size())
	{
		p = q.front();
		q.pop_front();
		if (p == finish)
		{
			break;
		}
		value = p.Value();
		if (*value == BLOCK)
		{
			continue;
		}
		*value = BLOCK;

		for (int i = 0; i < 6; i++)
		{
			aux = new Point(p.x + equis[i], p.y + yes[i], p.z + zeta[i], 1 + p.dist);
			value = aux->Value();
			if (*value != BLOCK)
			{
				q.push_back(*aux);
			}
		}
	}

	if (p == finish)
	{
		printf("Escaped in %d minute(s).\n", p.dist);
		return;
	}
	printf("Trapped!\n");
}

int main()
{
	int val;
	string s;
	char c;
	while (cin >> dz >> dx >> dy, dx + dy + dz)
	{
		for (int k = 0; k < dz; k++)
		{
			for (int i = 0; i < dx; i++)
			{
				cin >> s;
				for (int j = 0; j < dy; j++)
				{
					val = 0;
					c = s[j];
					if (c == '#')
					{
						val = BLOCK;
					}
					if (c == 'S')
					{
						ini(i, j, k);
					}
					if (c == 'E')
					{
						finish(i, j, k);
					}

					grafo[i][j][k] = val;
				}
			}
		}

		solve();
	}

	return 0;
}