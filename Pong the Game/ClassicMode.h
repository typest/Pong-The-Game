#include <gl/freeglut.h>
#include <time.h>
#include <Windows.h>
#include <math.h>
#include <stdlib.h>
#include "Ball.h"
#include "Reflector.h"
#include "PauseMenu.h"
Reflector reflector1(-60, -560, 0.9, 20);
Reflector reflector2(60, 560, 0.9, 20);
Ball ball(8, 0.8);
Pause pause(10, 10);

class ClassicMode
{
public:
	float FieldSizeX;
	float FieldSizeY;
	float BorderT;
	float MLineT;
	float TextPosX;
	float TextPosY;
	char * win;
	char * player_ID = "Player_ID";
	int score_player1;
	int score_player2;
	ClassicMode()
	{
		FieldSizeX = 500.0;
		FieldSizeY = 600.0;
		BorderT = 8.0;
		MLineT = 4.0;
		TextPosX = 550.0;
		TextPosY = 10.0;
		win = "Winner";
	}
	bool game_start;
	void draw();
	void drawScore();
	void move();
	void point_cnt();
};

void ClassicMode::draw()
{
	glColor3f(1,1,1);
	glVertex2f(-FieldSizeX - BorderT, -FieldSizeY - BorderT);
	glVertex2f(FieldSizeX + BorderT, -FieldSizeY - BorderT);
	glVertex2f(FieldSizeX + BorderT, -FieldSizeY);
	glVertex2f(-FieldSizeX - BorderT, -FieldSizeY);

	glVertex2f(-FieldSizeX - BorderT, FieldSizeY + BorderT);
	glVertex2f(FieldSizeX + BorderT, FieldSizeY + BorderT);
	glVertex2f(FieldSizeX + BorderT, FieldSizeY);
	glVertex2f(-FieldSizeX - BorderT, FieldSizeY);

	glVertex2f(-FieldSizeX - BorderT, -FieldSizeY - BorderT);
	glVertex2f(-FieldSizeX, -FieldSizeY - BorderT);
	glVertex2f(-FieldSizeX, FieldSizeY + BorderT);
	glVertex2f(-FieldSizeX - BorderT, FieldSizeY + BorderT);

	glVertex2f(FieldSizeX, -FieldSizeY - BorderT);
	glVertex2f(FieldSizeX + BorderT, -FieldSizeY - BorderT);
	glVertex2f(FieldSizeX + BorderT, FieldSizeY + BorderT);
	glVertex2f(FieldSizeX, FieldSizeY + BorderT);
	for (float i = -FieldSizeX; i <= FieldSizeX; i += 8 * MLineT){
		glVertex2f(i - MLineT, MLineT);
		glVertex2f(i + MLineT, MLineT);
		glVertex2f(i + MLineT, -MLineT);
		glVertex2f(i - MLineT, -MLineT);
	}
}

void ClassicMode::drawScore()
{
	glColor3f(1, 1, 1);
	glRasterPos2f(TextPosX, TextPosY);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0' + score_player1);
	glRasterPos2f(TextPosX , TextPosY -50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0' + score_player2);
	if (score_player1 == 9){
		glRasterPos2f(TextPosX, TextPosY+70);
		for (int n = 0; n <= sizeof(win)+1; n++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, win[n]);
	}
	if (score_player2 == 9){
		glRasterPos2f(TextPosX, TextPosY-120);
		for (int n = 0; n <= sizeof(win)+1;n++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, win[n]);
	}
	glRasterPos2f(TextPosX, TextPosY + 520);
	for (int n = 0; n <= 9; n++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, player_ID[n]);
	glRasterPos2f(TextPosX, TextPosY - 540);
	for (int n = 0; n <= 9; n++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, player_ID[n]);
}

void ClassicMode::point_cnt()
{
	if (reflector1.reflector_y - reflector1.reflector_depth / 2>= ball.ball_vy)
	{
		{
			ball.ball_vx = 0;
			ball.ball_vy = 0;
			ball.ball_direc_y = ball.ball_speed;
			reflector1.reflector_vx = 0;
			reflector2.reflector_vx = 0;
			score_player1++;
			Sleep(300);
		}
	}

	if (reflector2.reflector_y + reflector2.reflector_depth / 2 <= ball.ball_vy)
	{
		ball.ball_vx = 0;
		ball.ball_vy = 0; 
		ball.ball_direc_y = -ball.ball_speed;
		reflector2.reflector_vx = 0;
		reflector1.reflector_vx = 0;
		score_player2++;
		Sleep(300);
	}
	if (score_player1 == 9 || score_player2 == 9){
		reflector1.reflector_vx = 0;
		reflector2.reflector_vx = 0;
		game_start = false;
		pause.pause_state = true;
	}
}