#include "tp1.h"

void trace_pixel(int x, int y){
	glBegin(GL_QUADS);
	glVertex2f(x-0.5,y+0.5);
	glVertex2f(x+0.5,y+0.5);
	glVertex2f(x+0.5,y-0.5);
	glVertex2f(x-0.5,y-0.5);
	glEnd();
}

void trace_seg_diff(int x1, int y1, int x2, int y2){
	float delta_x = x2-x1;
	float delta_y = y2-y1;
	float pente = delta_y/delta_x;
	float x, y;
	if(delta_x>=delta_y){
		y=y1;
		for(x=x1; x<x2; x++){
			trace_pixel(x, y);
			y += pente;
		}
	}
	if(delta_y > delta_x){
		x=x1;
		for (y=y1; y<y2; y++){
			trace_pixel(x, y);
			x += 1/pente;
		}
	}
}

void trace_seg_bresenham_float(int x1, int y1, int x2, int y2){
	float delta_x = x2-x1;
	float delta_y = y2-y1;
	float pente = delta_y/delta_x;
	float erreur = -0.5;
	float x, y=y1;
	for(x=x1; x<x2; x++){
		if(erreur >= 0){
			y++;
			erreur--;
		}
	}
}

void trace_seg_bresenham_int(int x1, int y1, int x2, int y2){
	int delta_x = abs(x2-x1);
	int delta_y = abs(y2-y1);
	int erreur;
	int x, y;
	
	if(delta_x == 0){
		x= x1;
		if(y1< y2){
			for(y=y1; y<y2; y++) trace_pixel(x,y);
		}
		else for(y=y1; y>y2; y--) trace_pixel(x,y);
	}
	if(delta_y == 0){
		y=y1;
		if(x1<x2) for(x=x1; x<x2; x++) trace_pixel(x,y);
		else for(x=x1; x>x2; x--) trace_pixel(x,y);
	}

	if(delta_y<=delta_x && x2-x1 > 0 && y2-y1 > 0){
		y = y1;
		erreur = -delta_x;
		for(x=x1; x<x2; x++){
			trace_pixel(x, y);
			erreur += 2*delta_y;
			if(erreur >= 0){
				y++;
				erreur -= 2*delta_x;
			}
		}
	}
	if(delta_y>delta_x && x2-x1 > 0 && y2-y1 > 0){
		x = x1;
		erreur = -delta_y;
		for(y=y1; y<y2; y++){
			trace_pixel(x, y);
			erreur += 2*delta_x;
			if(erreur >= 0){
				x++;
				erreur -= 2*delta_y;
			}
		}
	}

	if(delta_y<=delta_x && x2-x1 < 0 && y2-y1 > 0){
		y = y1;
		erreur = -delta_x;
		for(x=x1; x>x2; x--){
			trace_pixel(x, y);
			erreur += 2*delta_y;
			if(erreur >= 0){
				y++;
				erreur -= 2*delta_x;
			}
		}
	}
	if(delta_y>delta_x && x2-x1 > 0 && y2-y1 > 0){
		x = x1;
		erreur = -delta_y;
		for(y=y1; y<y2; y++){
			trace_pixel(x, y);
			erreur += 2*delta_x;
			if(erreur >= 0){
				x--;
				erreur -= 2*delta_y;
			}
		}
	}

	if(delta_y<=delta_x && x2-x1 < 0 && y2-y1 < 0){
		y = y1;
		erreur = -delta_x;
		for(x=x1; x>x2; x--){
			trace_pixel(x, y);
			erreur += 2*delta_y;
			if(erreur >= 0){
				y--;
				erreur -= 2*delta_x;
			}
		}
	}
	if(delta_y>delta_x && x2-x1 < 0 && y2-y1 < 0){
		x = x1;
		erreur = -delta_y;
		for(y=y1; y>y2; y--){
			trace_pixel(x, y);
			erreur += 2*delta_x;
			if(erreur >= 0){
				x--;
				erreur -= 2*delta_y;
			}
		}
	}

	if(delta_y<=delta_x && x2-x1 > 0 && y2-y1 < 0){
		y = y1;
		erreur = -delta_x;
		for(x=x1; x<x2; x++){
			trace_pixel(x, y);
			erreur += 2*delta_y;
			if(erreur >= 0){
				y--;
				erreur -= 2*delta_x;
			}
		}
	}
	if(delta_y>delta_x && x2-x1 > 0 && y2-y1 < 0){
		x = x1;
		erreur = -delta_y;
		for(y=y1; y>y2; y--){
			trace_pixel(x, y);
			erreur += 2*delta_x;
			if(erreur >= 0){
				x++;
				erreur -= 2*delta_y;
			}
		}
	}
}