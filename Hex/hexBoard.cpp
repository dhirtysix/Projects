#include <iostream>
#include <vector>
using namespace std;

class HexBoard
{
public:
	HexBoard(int numPerSide);
	void printBoard(void);
	void drawHex(void);

	enum Color
	{
		GRAY,
		BLUE,
		RED
	};
	
private:
	int x;
	int y;
	Color whos_turn;

	void printBoardRow(int row);
	
	vector< vector <bool> > hexGraph;
	vector< vector <Color> > colorGraph;
};

void
HexBoard::printBoard(void)
{
	for ( int i = 0; i < x; i++ )
	{
		printBoardRow(i);
	}

	return;
}

void
HexBoard::printBoardRow(int row)
{
	if ( row == 0 )
	{
		// Draw the top

		// Draw the tip
		for ( int i = 0; i < x; i++)
		{
			cout << "  ^ ";
		}
		cout << endl;
		// Draw top slide
		for ( int i = 0; i < x; i++)
		{
			if ( i == 0 && x > 1 )
			{
				cout << "/   V";
			}else if ( i != 0 && i != x-1 )
			{
				cout << "   V";
			}else if ( i == x-1 )
			{
				cout << "   \\";
			}else
			{
				cout << "/   \\";
			}

		}
		cout << endl;

	}

	// Draw middle

	for ( int i = 0; i < row; i++ )
	{
		cout << "  ";
	}

	cout << "|";
	for ( int i = 0; i < x; i++)
	{
		cout << " " << row*x+i << " |";
	}
	cout << endl;

	// Draw down slide
	for ( int i = 0; i < row; i++ )
	{
		cout << "  ";
	}
	cout << "\\";
	for ( int i = 0; i < x; i++)
	{
		cout << "   ";
		if ( i == x-1 && row == x-1 )
		{
			cout << "/";
		}else
		{
			cout << "^";
		}
	}
	cout << endl;

	// draw bottom
	for ( int i = 0; i < row; i++ )
	{
		cout << "  ";
	}
	for ( int i = 0; i < x; i++)
	{
		if ( row != x-1 && i == x -1 )
		{
			cout << "  V   \\";
		}else
		{
			cout << "  V " ;
		}
	}
	cout << endl;

	return;
}

HexBoard::HexBoard(int numPerSide)
{
	int i_x, i_y, j_x, j_y;
	y = numPerSide;
	x = numPerSide;
	whos_turn = BLUE;

	vector < vector < bool > > hexGraph(x*y, vector<bool>(x*y, 1));
	vector < vector < int > > colorGraph(x, vector<int>(y, 1));

	for ( int i = 0; i < x; i++ )
	{
		for ( int j = 0; j < y; j++ )
		{
			colorGraph[i][j] = GRAY;
		}
	}

	// Initialize all of the inside nodes
	for ( int i = 0; i < x*y ; i++ )
	{
		for ( int j = 0; j < x*y; j++ )
		{
			
			i_x = i % x;
			i_y = i / x;
			j_x = j % x;
			j_y = j / x;

			if ( (i_x == j_x && (	(i_y == j_y + 1) || 	// Directly to Above
						(i_y == j_y - 1))) || 	// Directly to Below
			     (i_y == j_y && (	(i_x == j_x + 1) ||	// Directly to the right
						(i_x == j_x - 1))) ||	// Directly to the left
			     (i_x == j_x+1 && i_y == j_y + 1) ||	// Up Right
			     (i_x == j_x-1 && i_y == j_y - 1))		// Back to the left
			{
				hexGraph[i][j] = true;
			}else
			{
				hexGraph[i][j] = false;
			}
			cout << hexGraph[i][j] << " ";
		}
		cout << endl;
	}
}

class Node
{
public:
	Node():connected(false){};

private:
	int x;
	int y;
	bool connected;
};

int
main()
{
	cout << "Start" << endl;

	HexBoard newBoard(3);

	newBoard.printBoard();

	cout << "End" << endl;

	return 0;
}
