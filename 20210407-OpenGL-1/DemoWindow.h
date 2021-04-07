/*
 * DemoWindow.h
 *
 *  Created on: 7 апр. 2021 г.
 *      Author: unyuu
 */

#ifndef DEMOWINDOW_H_
#define DEMOWINDOW_H_

#include "Window.h"

class DemoWindow final : public Window
{
public:
	DemoWindow(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
	virtual ~DemoWindow() = default;

	virtual void setup_gl() override;
	virtual void render() override;
};

#endif /* DEMOWINDOW_H_ */
