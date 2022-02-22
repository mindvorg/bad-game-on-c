#include <stdio.h>

#include <conio.h>

#include <dos.h>

#include <graphics.h>

#define ESC 27

char maze[27][68] = {

"+-------------------------------+--------------------------------+" ,

"| | |",

"| . . +--------- | --------------------+ |",

"| | | | | | |",

"| | +----+----------------+ +-------------------. | |",

"| | | | | |",

"| |--------------.--------------+---- +---------| | |",

"| | | | | | |",

"| |-------- | +-------- | | +----|",

"| | | | | | | | | |",

"| | -----------+ | |---- | | | | . |",

"| | | | | | | | | |",

"| +-------------------+ | ----+ | | | | |",

"| | | | | | |",

"|--------------+---------+ |--------------+ | |----+ |",

"| | | | | | |",

"| | | | | | | +--------------| |",

"| | | | | | | | | |",

"| | | + | | | | ---------+---------+ |",

"| | | | | | | | |",

"| | +---------+----+ | | +---------+ + | |",

"| | | | | | | | |",

"|----|------------------------|-@@-|----|----+----|----|----|----|", };

int getchar1()

{

	union REGS reg;

	reg.h.ah = 0x08;

	int86(0x21, &reg, &reg);

	return reg.h.al;

}

main()

{

	int cord, x = 4, y = 20, tmp_x = x, tmp_y = y, j, i;

	textbackground(0);

	clrscr();

	window(5, 0, 78, 25);

	textbackground(0);

	for (i = 0; i < 23; i++)

	{

		for (j = 0; j < 73; j++)

		{

			gotoxy(j + 1, i + 1);

			printf("%c", maze[i][j]);

		}

	}

	/*textcolor(0);*/

	while (cord != ESC)

	{

		cord = getch();

		if ((cord == 72) || (cord == 75) || (cord == 77) || (cord == 80))

		{

			if (cord == 75)

				if (maze[y - 1][x - 2] == ' ') { x--; }

			if (cord == 77)

				if (maze[y - 1][x] == ' ') { x++; }

			if (cord == 72)

				if (maze[y - 2][x - 1] == ' ') { y--; }

			if (cord == 80)

				if (maze[y][x - 1] == ' ') { y++; }

			gotoxy(tmp_x, tmp_y);

			printf(" ");

			gotoxy(x, y);

			printf("~");

			tmp_x = x;

			tmp_y = y;

		}

		if (maze[y][x] == '@') { cord = ESC; }

	}

	/* textcolor(DARKGREY);*/

	if (maze[y][x] == '@') { clrscr(); gotoxy(30, 30); cprintf("\n VI molodzi das ist WIN"); }

	/* textbackground(0); textcolor(DARKGREY);*/

	cprintf("\n this is the end...");

}