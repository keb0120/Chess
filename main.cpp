#include <iostream>
#include <Windows.h>

#define color_W setcolor(0,15)
#define color_B setcolor(15,0)
using namespace std;
//좌표이동 함수
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//색상변경함수
void setcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}
class W_pieces {
protected:
	int m_x;
	int m_y;
public:
	W_pieces() { };
	void location(int x, int y) {
		color_W;
		m_x = x;
		m_y = y;
		gotoxy(m_x, m_y);
	};//constructor location공통
	void move(int num_x,int num_y) {
		
		m_x += num_x*4;
		m_y += num_y*2;
		location(num_x, num_y);
	};
	bool kill() {};

};
class B_pieces {
protected:
	int m_x;
	int m_y;
public:
	B_pieces() {
		
	};
	void location(int x, int y) {
		color_B;
		m_x = x;
		m_y = y;
		gotoxy(m_x, m_y);
	};//constructor location공통
	void move(int num_x, int num_y) {
		///////////////////////////////윗진영 아랫진영 나중에 설정해야함
		gotoxy(m_x, m_y);
		cout << " ";
		m_x -= num_x*4;
		m_y += num_y*2;
		location(m_x,m_y);
	};
};
//여기부터 백색말
class W_pawn : public W_pieces {
public:
	void location(int x, int y) {
		W_pieces::location(x,y);
		cout << "p";
	};
	//void move() {};
	//승진
	bool promotion() {};
};
class W_horse : public W_pieces {
public:
	void location(int x, int y) {
		W_pieces::location(x, y);
		cout << "H";
	};
};
class W_bishop : public W_pieces {
public:
	void location(int x, int y) {
		W_pieces::location(x, y);
		cout << "B";
	};
};
class W_rook : public W_pieces {
public:
	void location(int x, int y) {
		W_pieces::location(x, y);
		cout << "R";
	};
};
class W_queen : public W_pieces {
public:
	void location(int x, int y) {
		W_pieces::location(x, y);
		cout << "Q";
	};
};
class W_king : public W_pieces{
public:
	void location(int x, int y) {
		W_pieces::location(x, y);
		cout << "K";
	};
};
//여기부터 흑색말
class B_pawn : public B_pieces {
public:
	void location(int x, int y) {
		B_pieces::location(x, y);
		cout << "p";
	};
	void move(int num_x, int num_y) {
		///////////////////////////////윗진영 아랫진영 나중에 설정해야함
		gotoxy(m_x, m_y);
		cout << " ";
		m_x -= num_x * 4;
		m_y += num_y * 2;
		location(m_x, m_y);
	};
};
class B_horse : public B_pieces {
public:
	void location(int x, int y) {
		B_pieces::location(x, y);
		cout << "H";
	};
};
class B_bishop : public B_pieces {
public:
	void location(int x, int y) {
		B_pieces::location(x, y);
		cout << "B";
	};
};
class B_rook : public B_pieces {
public:
	void location(int x, int y) {
		B_pieces::location(x, y);
		cout << "R";
	};
};
class B_queen : public B_pieces {
public:
	void location(int x, int y) {
		B_pieces::location(x, y);
		cout << "Q";
	};
};
class B_king : public B_pieces {
public:
	void location(int x, int y) {
		B_pieces::location(x, y);
		cout << "K";
	};
};

int main(int argc, char* argv[]) {
	//커서 숨기기
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	//가로 4칸씩
	for (int a = 3; a < 32; a+=4) {
		gotoxy(a, 2);
		cout << 1+(a-1)/4;
	}
	//세로 2칸씩
	for (int b = 3; b < 19; b += 2) {
		gotoxy(2, b);
		cout << b / 2;
	}
	W_pawn W_pawn[8];
	W_rook W_rook[2];
	W_bishop W_bishop[2];
	W_horse W_horse[2];
	W_queen W_queen[1];
	W_king W_king[1];

	B_pawn B_pawn[8];
	B_rook B_rook[2];
	B_bishop B_bishop[2];
	B_horse B_horse[2];
	B_queen B_queen[1];
	B_king B_king[1];
	//말 생성
	for (int i = 0; i < 8; i++) {
		W_pawn[i].location(7, 3 + i * 2);
		B_pawn[i].location(27, 3 + i * 2);
	}
	for (int i = 0; i < 2; i++) {
		W_rook[i].location(3, 3 + 14 * i);
		B_rook[i].location(31, 3 + 14 * i);
	}
	for (int i = 0; i < 2; i++) {
		W_horse[i].location(3, 5 + 10 * i);
		B_horse[i].location(31, 5 + 10 * i);
	}
	for (int i = 0; i < 2; i++) {
		W_bishop[i].location(3, 7 + 6* i);
		B_bishop[i].location(31, 7 + 6 * i);
	}
		W_queen[0].location(3, 9);
		B_queen[0].location(31, 9);

		W_king[0].location(3, 11);
		B_king[0].location(31,11);

		B_pawn[0].move(1,0);

	getchar();
	return 0;
}