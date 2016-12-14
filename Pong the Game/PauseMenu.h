#include <gl/freeglut.h>
#include <iostream>

class Pause{
public:
	float field_x=150;
	float field_y=150;
	float pos_x;
	float pos_y;
	char * main = "Main Menu";
	char * play = "Play Again";
	short int selector=0;
	bool pause_state = false;
	Pause(float x, float y) :pos_x(x), pos_y(y){}
	void draw();
	void select();
	void text();
};

void Pause::draw()
{
	glBegin(GL_QUADS);
	glColor3f(0,0,0);
	glVertex2f(pos_x + field_x-10, pos_y + field_y);
	glVertex2f(pos_x + field_x-10, pos_y - field_y);
	glVertex2f(pos_x - field_x-10, pos_y - field_y);
	glVertex2f(pos_x - field_x-10, pos_y + field_y);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2f(field_x, field_y);
	glVertex2f(field_x, -field_y);
	glVertex2f(-field_x, -field_y);
	glVertex2f(-field_x, field_y);
	glEnd();
	glBegin(GL_LINE_LOOP);
	if (selector == 0)
	{
		glColor3f(1, 1, 1);
		glVertex2f(pos_x - field_x + 40, pos_y + field_y / 3-20);
		glVertex2f(pos_x - field_x + 250, pos_y + field_y / 3-20);
		glVertex2f(pos_x - field_x + 250, pos_y + field_y / 3+50);
		glVertex2f(pos_x - field_x + 40, pos_y + field_y / 3+50);
	}
	else if (selector == 1)
	{
		glColor3f(1, 1, 1);
		glVertex2f(pos_x - field_x + 30, pos_y - field_y / 3 - 50);
		glVertex2f(pos_x - field_x + 260, pos_y - field_y / 3 - 50);
		glVertex2f(pos_x - field_x + 260, pos_y - field_y / 3 + 10);
		glVertex2f(pos_x - field_x + 30, pos_y - field_y / 3 +10);
	}
	glEnd();
	text();
}

void Pause::text()
{
	glColor3f(1, 1, 1);
	glRasterPos2f(pos_x-field_x+50 , pos_y+field_y/3 );
	for (int n = 0; n < 11; n++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, play[n]);
	glRasterPos2f(pos_x-field_x+40, pos_y-field_y/3-30);
	for (int n = 0; n < 10; n++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, main[n]);
}