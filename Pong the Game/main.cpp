#include <iostream>
#include "MainMenu.h"
#include "ClassicMode.h"
#include "Tunning.h"


#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glu32.lib")
#pragma comment (lib, "glut32.lib")

using namespace std;
unsigned short int mode_controller = 0;

MainMenu main_menu;
ClassicMode classic_mode;
Tunning tun_RS[4] = { Tunning(-100, 0,0), Tunning(50, 0,70), Tunning(200, 0,140), Tunning(350, 0,210) };



int winWidth = 900;
int winHeight = 700;
int winPosX = 250;
int winPosY = 50;

void draw_MainMenu();
void draw_ClassicMode();
void Special_Keyboard(int key, int x, int y);
void Keyboard(unsigned char key, int x, int y);
void KeyboardUp(unsigned char key, int x, int y);
void Timer(int value);
void GameScore();

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(winWidth, winHeight);
	glutInitWindowPosition(winPosX, winPosY);
	glutCreateWindow("PONG THE GAME");
	glutTimerFunc(30, Timer, 1);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-700.0, 900.0, -700.0, 700.0);
	glutDisplayFunc(draw_MainMenu);
	glutKeyboardFunc(Keyboard);
	glutKeyboardUpFunc(KeyboardUp);
	glutMainLoop();
}

void draw_MainMenu()
{
	if (mode_controller == 0)//Start & Exit
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_QUADS);
		main_menu.draw_Tittle();
		glEnd();
		glBegin(GL_LINE_LOOP);
		main_menu.draw_field();
		glEnd();
		main_menu.draw_Menu();
		glutSwapBuffers();
	}
	else if (mode_controller== 1)//Classic Mode
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_QUADS);
		ball.draw_ball();
		classic_mode.draw();
		reflector1.ref_draw();
		reflector2.ref_draw();
		glEnd();
		classic_mode.drawScore();
		if (pause.pause_state)
			pause.draw();
		glutSwapBuffers();
	}
	else if (mode_controller == 2)//Classic Mode & Tunning Room
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_QUADS);
		main_menu.draw_Tittle();
		glEnd();
		glBegin(GL_LINE_LOOP);
		main_menu.draw_field3();
		glEnd();
		main_menu.draw_menu_tun();
		glutSwapBuffers();
	}
	else if (mode_controller == 3)//Racket Speed & Ball Reflectio Speed
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_QUADS);
		main_menu.draw_Tittle();
		glEnd();
		glBegin(GL_LINE_LOOP);
		main_menu.draw_field2();
		glEnd();
		main_menu.draw_Menu_in_Start();
		glutSwapBuffers();
	}
	else if (mode_controller == 4)//Racket Speed
	{
		glClear(GL_COLOR_BUFFER_BIT);
		if (reflector1.level == 0)//Level 0
		{
			for (int n = 0; n < 4; n++)
			{
				glBegin(GL_LINE_LOOP);
				tun_RS[n].draw_stick();
				glEnd();
			}
		}
		else if (reflector1.level == 1)//Level 1
		{
			for (int n = 1; n < 4; n++)
			{
				glBegin(GL_LINE_LOOP);
				tun_RS[n].draw_stick();
				glEnd();
			}
			glBegin(GL_QUADS);
			tun_RS[0].draw_stick();
			glEnd();
		}
		else if (reflector1.level == 2)//Level 2
		{
			
			for (int n = 2; n < 4; n++)
			{
				glBegin(GL_LINE_LOOP);
				tun_RS[n].draw_stick();
				glEnd();
			}
			
			glBegin(GL_QUADS);
			for (int n = 0; n < 2; n++)
			{
				tun_RS[n].draw_stick();
			}
			glEnd();
		}
		else if (reflector1.level == 3)//Level 3
		{
			glBegin(GL_LINE_LOOP);
			tun_RS[3].draw_stick();
			glEnd();
			glBegin(GL_QUADS);
			for (int n = 0; n < 3; n++)
			{
				tun_RS[n].draw_stick();
			}
			glEnd();
		}
		else if (reflector1.level == 4)//Level 4
		{
			glBegin(GL_QUADS);
			for (int n = 0; n < 4; n++)
			{
				tun_RS[n].draw_stick();
			}
			glEnd();
		}
		tun_RS[0].draw_field();
		tun_RS[0].draw_text_RS();
		glutSwapBuffers();
	}
	else if (mode_controller == 5)//Ball Reflection Speed
	{
		glClear(GL_COLOR_BUFFER_BIT);
		if (reflector1.b_level == 0)//Level 0
		{
			for (int n = 0; n < 4; n++)
			{
				glBegin(GL_LINE_LOOP);
				tun_RS[n].draw_stick();
				glEnd();
			}
		}
		else if (reflector1.b_level == 1)//Level 1
		{
			for (int n = 1; n < 4; n++)
			{
				glBegin(GL_LINE_LOOP);
				tun_RS[n].draw_stick();
				glEnd();
			}
			glBegin(GL_QUADS);
			tun_RS[0].draw_stick();
			glEnd();
		}
		else if (reflector1.b_level == 2)//Level 2
		{

			for (int n = 2; n < 4; n++)
			{
				glBegin(GL_LINE_LOOP);
				tun_RS[n].draw_stick();
				glEnd();
			}

			glBegin(GL_QUADS);
			for (int n = 0; n < 2; n++)
			{
				tun_RS[n].draw_stick();
			}
			glEnd();
		}
		else if (reflector1.b_level == 3)//Level 3
		{
			glBegin(GL_LINE_LOOP);
			tun_RS[3].draw_stick();
			glEnd();
			glBegin(GL_QUADS);
			for (int n = 0; n < 3; n++)
			{
				tun_RS[n].draw_stick();
			}
			glEnd();
		}
		else if (reflector1.b_level == 4)//Level 4
		{
			glBegin(GL_QUADS);
			for (int n = 0; n < 4; n++)
			{
				tun_RS[n].draw_stick();
			}
			glEnd();
		}
		tun_RS[0].draw_field_BS();
		tun_RS[0].draw_text_BS();
		glutSwapBuffers();
	}
}

void Keyboard(unsigned char key, int x, int y)
{
	if (mode_controller == 0)//Main menu
	{
		switch (key)
		{
		case 's':
			main_menu.select = 1;
			break;
		case 'w':
			main_menu.select = 0;
			break;
		case 13:
			if (main_menu.select == 0)
				mode_controller = 3;
			else if (main_menu.select == 1)
				exit(100);
			break;
		default:
			break;
		}
	}
	else if (mode_controller == 3)//Mode menu
	{
		switch (key)
		{
		case 's':
			main_menu.mode_sel = 1;
			break;
		case 'w':
			main_menu.mode_sel = 0;
			break;
		case 13:
			if (main_menu.mode_sel == 0)
				mode_controller = 1;
			else if (main_menu.mode_sel == 1)
				mode_controller=2;
			break;
		default:
			break;
		}
	}
	else if (mode_controller == 2)//Tunning menu
	{
		switch (key)
		{
		case 's':
			main_menu.tun_sel = 1;
			break;
		case 'w':
			main_menu.tun_sel = 0;
			break;
		case 13:
			if (main_menu.tun_sel == 0)
				mode_controller = 4;
			else if (main_menu.tun_sel == 1)
				mode_controller = 5;
			break;
		default:
			break;
		}
	}
	else if (mode_controller == 4)//Racket Speed
	{
		switch (key)
		{
		case 's':
			tun_RS[0].RS_sel = 1;
			break;
		case 'w':
			tun_RS[0].RS_sel = 0;
			break;
		case 13:
			if (tun_RS[0].RS_sel == 0)
			{
				if (reflector1.level >= 0 && reflector1.level < 4){
					reflector1.level++;
					reflector1.ref_speed += 0.1*reflector1.level;
				}
			}
			else if (tun_RS[0].RS_sel == 1){
				mode_controller = 0;
				tun_RS[0].BS_sel = 0;
				tun_RS[0].RS_sel = 0;
				main_menu.tun_sel = 0;
				main_menu.mode_sel = 0;
				main_menu.select = 0;
			}
			break;
		default:
			break;
		}
	}
	else if (mode_controller == 5)//Ball Reflection Speed
	{
		switch (key)
		{
		case 's':
			tun_RS[0].BS_sel = 1;
			break;
		case 'w':
			tun_RS[0].BS_sel = 0;
			break;
		case 13:
			if (tun_RS[0].BS_sel == 0)
			{
				if (reflector1.b_level >= 0 && reflector1.b_level < 4){
					reflector1.b_level++;
					ball.ball_direc_y+= 0.1;
				}
			}
			else if (tun_RS[0].BS_sel == 1)
			{
				mode_controller = 0;
				tun_RS[0].BS_sel = 0;
				tun_RS[0].RS_sel = 0;
				main_menu.tun_sel = 0;
				main_menu.mode_sel = 0;
				main_menu.select = 0;
			}
			break;
		default:
			break;
		}
	}

	else if (mode_controller == 1)//Classic Mode
	{
		switch (key)
		{
		case's':
			classic_mode.game_start = true;
			break;
		case'k':
			classic_mode.game_start = true;
			break;
		}
		if (classic_mode.game_start)
		{
			switch (key)
			{
			case 'a':
				reflector1.ref_L = true;
				break;
			case 'd':
				reflector1.ref_R = true;
				break;
			case 'j':
				reflector2.ref_L = true;
				break;
			case 'l':
				reflector2.ref_R = true;
				break;
			case 27:
				pause.pause_state = true;
				classic_mode.game_start = false;
				break;
			default:
				break;
			}
		}
		if (pause.pause_state)//Pause Menu
		{
			switch (key)
			{
			case 'w':
				pause.selector = 0;//selector up
				classic_mode.game_start = false;
				break;
			case 's':
				pause.selector = 1;//selector down
				classic_mode.game_start = false;
				break;
			case 13:
				if (pause.selector == 0)//select Play Again
				{
					classic_mode.score_player1 = 0;
					classic_mode.score_player2 = 0;
					ball.ball_vx = 0;
					ball.ball_vy = 0;
					reflector1.reflector_vx = 0;
					reflector2.reflector_vx = 0;
					pause.pause_state = false;
					pause.selector = 0;
				}
				else if (pause.selector == 1)//select Main Menu
				{
					classic_mode.game_start = false;
					classic_mode.score_player1 = 0;
					classic_mode.score_player2 = 0;
					ball.ball_vx = 0;
					ball.ball_vy = 0;
					reflector1.reflector_vx = 0;
					reflector2.reflector_vx = 0;
					pause.pause_state = false;
					pause.selector = 0;
					mode_controller = 0;
					tun_RS[0].BS_sel = 0;
					tun_RS[0].RS_sel = 0;
					main_menu.tun_sel = 0;
					main_menu.mode_sel = 0;
					main_menu.select = 0;
				}
				
			}
		}
	}
}

void KeyboardUp(unsigned char key, int x, int y)
{
	if (mode_controller == 1)
	{
		switch (key)
		{
		case 'a':
			reflector1.ref_L = false;
			break;
		case 'd':
			reflector1.ref_R = false;
			break;
		case 'j':
			reflector2.ref_L = false;
			break;
		case 'l':
			reflector2.ref_R = false;
			break;
		}
	}
}


void Timer(int value)
{
	ball.reflection(classic_mode.FieldSizeX, reflector1.reflector_x, reflector1.reflector_y, reflector1.reflector_vx, reflector1.reflector_depth,reflector1.b_level
		,reflector2.reflector_x, reflector2.reflector_y,reflector2.reflector_vx,reflector2.reflector_depth,reflector2.b_level);
	if (classic_mode.game_start)
	{
		ball.ball_move();
		reflector1.ref_move(classic_mode.FieldSizeX);
		reflector2.ref_move(classic_mode.FieldSizeX);
		classic_mode.point_cnt();
	}
	glutPostRedisplay();
	glutTimerFunc(1, Timer, 1);
}