#include <iostream>
using namespace std;

#define M 3
#define N 3

int A[M][N];
int colorOf(int i, int j);

class Drawer {
public:
	static void drawPixel(int x, int y, int color);
};

int main() {
	int color = 0;

	for(int i = 0; i < M; ++i) {     //Go through the rows, y
		for(int j = 0; j < N; ++j) { //Go through the columns, x
			color = colorOf(j, i);
			Drawer::drawPixel(j, i, color);
		}
	}

	/**********************************
	 * Progresses through, like this: *
	 *                                *
	 *           7  8  9 End          *
	 *           4  5  6              *
	 *    Start  1  2  3              *
	 *                                *
	 **********************************/

	return 0;
}

int colorOf(int i, int j) {
	return A[i][j];
}

void Drawer::drawPixel(int x, int y, int color) {
	cout << "Col: " << x << " Row: " << y << " Color: " << color << endl;
}