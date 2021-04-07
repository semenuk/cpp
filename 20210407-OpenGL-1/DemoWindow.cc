/*
 * DemoWindow.cc
 *
 *  Created on: 7 апр. 2021 г.
 *      Author: unyuu
 */

#include "DemoWindow.h"

DemoWindow::DemoWindow(int width, int height)
: Window(width, height)
{
	SDL_SetWindowTitle(_window.get(), "OpenGL Demo Window");
}

void DemoWindow::setup_gl()
{
	glClearColor(0.2f, 0.4f, 0.7f, 1.0f);
	glPointSize(16.0f);
	glLineWidth(12.0f);
}

void DemoWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT); // Очистка

	glBegin(GL_QUADS);

	glColor3d(1.0, 1.0, 0.0);
	glVertex2d(-0.8, 0.8);
	glColor3d(0.0, 1.0, 0.0);
	glVertex2d(0.8, 0.8);
	glColor3d(1.0, 0.0, 1.0);
	glVertex2d(0.8, -0.8);
	glColor3d(0.0, 1.0, 1.0);
	glVertex2d(-0.8, -0.8);

	glEnd();
}
