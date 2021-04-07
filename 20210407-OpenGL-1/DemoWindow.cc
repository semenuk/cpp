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
}

void DemoWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT);
}
