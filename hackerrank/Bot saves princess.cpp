#include <iostream>

using namespace std;

struct Vector2 {
	int x, y;

	Vector2() {
		x = 0;
		y = 0;
	}

	Vector2(int _x, int _y) {
		x = _x;
		y = _y;
	}

	Vector2 operator+(Vector2& other) {
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator-(Vector2& other) {
		return Vector2(x - other.x, y - other.y);
	}

	Vector2 operator+(const Vector2& other) {
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator-(const Vector2& other) {
		return Vector2(x - other.x, y - other.y);
	}
};

char matrix[100][100];
int n;
Vector2 m, p;

int main() {
	cin >> n;
	for (int j = 0; j < n; j++)
		for (int i = 0; i < n; i++) {
			cin >> matrix[i][j];
			if (matrix[i][j] == 'm') m = Vector2(i, j);
			else if (matrix[i][j] == 'p') p = Vector2(i, j);
		}


	Vector2 path = p - m;

	if (path.y < 0)
		for (int i = 0; i < abs(path.y); i++) cout << "TOP" << endl;
	else for (int i = 0; i < abs(path.y); i++) cout << "DOWN" << endl;

	if (path.x < 0)
		for (int i = 0; i < abs(path.x); i++) cout << "LEFT" << endl;
	else for (int i = 0; i < abs(path.x); i++) cout << "RIGHT" << endl;
	return 0;
}