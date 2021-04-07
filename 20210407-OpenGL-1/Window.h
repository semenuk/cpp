/*
 * Window.h
 *
 *  Created on: 7 апр. 2021 г.
 *      Author: unyuu
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <memory>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Window
{
public:
	constexpr int DEFAULT_WIDTH = 1920;
	constexpr int DEFAULT_HEIGHT = 1080;
	constexpr int DEFAULT_X = SDL_WINDOWPOS_CENTERED_DISPLAY(1);
	constexpr int DEFAULT_Y = SDL_WINDOWPOS_CENTERED_DISPLAY(1);

protected:
	std::shared_ptr<SDL_Window> _window; // Окно
	std::shared_ptr<void> _gl_context; // Контекст OpenGL
	int _width, _height; // Ширина и высота окна

public:
	Window(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
	virtual ~Window() = default;

	int height() const { return _height; }
	int width() const  { return _width;  }
};

#endif /* WINDOW_H_ */
