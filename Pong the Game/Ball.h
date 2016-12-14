#include <gl/freeglut.h>

class Ball
{
public:
	float ball_size;
	float ball_vx;
	float ball_vy;
	float ball_direc_x;
	float ball_direc_y;
	float ball_speed;
	Ball(float size, float speed)
	{
		ball_size = size;
		ball_speed = speed;
		ball_direc_y = ball_speed;
		ball_direc_x = ball_speed / 2;
	}
	void ball_move();
	void draw_ball();
	int ball_care(float ref1_y, float ref2_y);
	void reflection(float x, float reflector1_x, float reflector1_y, float reflector1_vx, float reflector1_depth,int reflector1_level
		,float reflector2_x,float reflector2_y, float reflector2_vx, float reflector2_depth, int relflector2_level);
};

void Ball::draw_ball()
{
	glColor3f(1.0, 1.0, 1.0);
	//
	glVertex2f(ball_vx + ball_size, ball_vy + ball_size);
	glVertex2f(ball_vx + ball_size, ball_vy - ball_size);
	glVertex2f(ball_vx - ball_size, ball_vy - ball_size);
	glVertex2f(ball_vx - ball_size, ball_vy + ball_size);
}

void Ball::ball_move()
{
	ball_vx += ball_direc_x;
	ball_vy += ball_direc_y;
}
void Ball::reflection(float x,float reflector1_x,float reflector1_y,float reflector1_vx, float reflector1_depth,int reflector1_level
	, float reflector2_x, float reflector2_y, float reflector2_vx, float reflector2_depth,int reflector2_level)
{
	if (x <= ball_vx || -x >= ball_vx)
		ball_direc_x = -ball_direc_x;
	if (ball_vy >= reflector2_y&&ball_vx <= reflector2_x + reflector2_vx&&ball_vx >= -reflector2_x + reflector2_vx)
	{
		ball_direc_y = reflector2_level*0.3 + ball_speed;
		ball_direc_y = -ball_direc_y;
		if (ball_direc_x > 0)
			ball_direc_x = -ball_direc_y / 2;
		else
			ball_direc_x = ball_direc_y / 2;
	}
	if (ball_vy <= reflector1_y + reflector1_depth &&ball_vx >= reflector1_x + reflector1_vx&&ball_vx <= -reflector1_x + reflector1_vx)
	{	
		ball_direc_y = -(reflector1_level*0.3 + ball_speed);
		ball_direc_y = -ball_direc_y;
		if (ball_direc_x > 0)
			ball_direc_x = ball_direc_y / 2;
		else
			ball_direc_x = -ball_direc_y / 2;
	}
}