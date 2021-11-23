# include "iGraphics.h"

int screen_height = 1200;
int screen_width = 800;

int red_x = screen_width / 2 - 250, red_y = screen_height;
int red_dx = 10, red_dy = 10;

int blue_x = screen_width / 2 + 100, blue_y = screen_height;
int blue_dx = 10, blue_dy = 10;

int  aim_x, aim_y;

bool red_shooted = true;
bool blue_shooted = false;

bool game = true;

bool blast;
int blast_x, blast_y;

int score = 0;
char score_string[100];

bool musicOn = 1;

void redBallonMovement();
void blueBallonMovement();
void blastTime();


/*
function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here	
	iClear();
	//iShowBMP(0, 0, "images\\background.bmp");
	if (!blue_shooted)
		iShowBMP2(blue_x, blue_y, "images\\blue.bmp", 0);

	if (!red_shooted)
		iShowBMP2(red_x, red_y, "images\\red.bmp", 0);
	if (blast)
		iShowBMP2(blast_x, blast_y, "images\\blast.bmp", 0);


	if (game == false)
	{

		iSetColor(255, 0, 0);
		iText(screen_width / 2 - 100, screen_height / 2, "GAME OVER!!!", GLUT_BITMAP_TIMES_ROMAN_24);

	}

	//score
	iSetColor(255, 255, 255);
	iText(10, 100, "PLAYER :", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(600, 100, "SCORE :", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(0, 255, 0);
	iText(130, 100, "Aminul", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(700, 100, score_string, GLUT_BITMAP_TIMES_ROMAN_24);

	iShowBMP2(aim_x, aim_y, "images\\aim.bmp", 0);

	if (score >= 480)
	{
		iPauseTimer(0);
		iText(screen_width / 2 - 100, screen_height / 2, "YOU WIN!!!", GLUT_BITMAP_TIMES_ROMAN_24);
	}

}

/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{

}

/*
function iPassiveMouse() is called when the user moves the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iPassiveMouse(int mx, int my)
{
	//printf("(x,y) : %d , %d\n", mx, my);

	aim_x = mx - 60;
	aim_y = my - 90;

}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (game = true)
		{
			if ((mx >= blue_x  && mx <= blue_x + 160) && (my >= blue_y && my <= blue_y + 220))
			{

				blast = true;
				PlaySound("Music\\ballon.wav", NULL, SND_FILENAME | SND_ASYNC);
				blue_shooted = true;
				red_shooted = false;
				blast_x = blue_x;
				blast_y = blue_y;
				itoa(score + 20, score_string, 10);
				score = score + 20;

			}

			else if ((mx >= red_x  && mx <= red_x + 160) && (my >= red_y && my <= red_y + 220))
			{
				blast = true;
				PlaySound("Music\\ballon.wav", NULL, SND_FILENAME | SND_ASYNC);
				red_shooted = true;
				blue_shooted = false;
				blast_x = red_x;
				blast_y = red_y;
				itoa(score + 30, score_string, 10);
				score = score + 30;

			}
		}
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key == 'p')
		iPauseTimer(0);
	if (key == 'r')
		iResumeTimer(0);
	if (key == 'a')
	{

	}
	else if (key == 'b')
	{

	}
	else if (key == 'c')
	{

	}
	if (key == 'm')
	{
		if (musicOn)
		{
			musicOn = false;
			PlaySound(0, 0, 0);
		}
		else
		{
			musicOn = true;
			PlaySound("Music\\bg.wav", NULL, SND_LOOP | SND_ASYNC);
		}
	}
	//place your codes for other keys here
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}

	if (key == GLUT_KEY_LEFT)
	{

	}

	if (key == GLUT_KEY_RIGHT)
	{

	}

	if (key == GLUT_KEY_INSERT)
	{

	}

	if (key == GLUT_KEY_HOME)
	{

	}
	//place your codes for other keys here
}
void redBallonMovement()
{
	if (game == true)
	{
		if (red_y <= 0)
			game = false;
	}
	if (red_shooted == false && blue_shooted == true)
	{
		red_y = red_y - red_dy;
		blue_y = screen_height;
	}
}

void blueBallonMovement()
{
	if (game == true)
	{
		if (blue_y <= 0)
			game = false;
	}
	if (red_shooted == true && blue_shooted == false)
	{
		blue_y = blue_y - blue_dy;
		red_y = screen_height;
	}
}

void blastTime()
{
	if (blast == true)
		blast = false;
}

int main()
{
	iSetTimer(20, redBallonMovement);
	iSetTimer(40, blueBallonMovement);
	iSetTimer(1000, blastTime);
	if (musicOn)
	{
		PlaySound("Music\\bg.wav", NULL, SND_LOOP || SND_ASYNC);
	}
	iInitialize(screen_width, screen_height, "ballon shooter demo");
	iStart();


	return 0;
}

