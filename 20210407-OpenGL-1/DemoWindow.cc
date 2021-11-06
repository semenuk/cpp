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
	set_title("OpenGL Demo Window");
}

void DemoWindow::setup_gl()
{
	glEnable(GL_DEPTH_TEST);

	glClearColor(0.2f, 0.4f, 0.7f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(
			45.0,								// Угол обзора по вертикали
			double(width()) / double(height()),	// Соотношение сторон
			0.1,								// Расстояние до ближней ПО
			20.0);								// Расстояние до дальней ПО
	glMatrixMode(GL_MODELVIEW);
}

void DemoWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Очистка

	glLoadIdentity(); // MV = единичная матрица

	gluLookAt(	6.0, 8.0, 4.0,		// Координаты камеры
				0.0, 0.0, 2.0,		// Координаты центра
				0.0, 0.0, 1.0);		// Направление вверх,	MV = C

	glRotated(_cube_angle, 0.0, 0.0, 1.0);



	glPushMatrix(); // Сохраняем текущую позицию

	// Рисуем 3 куба
	glTranslated(-2.5,0,0);

	render_cube();

	glTranslated(2.5,0,0);

	render_cube();

	glTranslated(2.5,0,0);

	render_cube();

	glPopMatrix(); // Возвращаемся на сохраненную позицию

	glPushMatrix(); // Сохраняем текущую позицию

	// Рисуем 2 куба

	glTranslated(-1.25,0,2);

	render_cube();

	glTranslated(2.5,0,0);

	render_cube();

	glPopMatrix(); // Возвращаемся на сохраненную позицию

	// Рисуем верхний куб

	glTranslated(0,0,4);

	render_cube();




	/* TODO: задание для самостоятельной работы
	 * - Добавить оставшиеся грани куба
	 * - Выяснить, почему куб в текущем виде отображается неправильно
	 * - Исправить программу, чтобы куб начал правильно отображаться
	 * - Разобраться с основными преобразованиями:
	 * 		~ параллельный перенос;
	 * 		~ поворот;
	 * 		~ масштабирование.
	 * - Разобраться с функциями glPushMatrix() и glPopMatrix()
	 * - Построить из кубиков пирамидку:
	 *          +-+
	 *          |X|
	 *        +-+ +-+
	 *        |X| |X|
	 *      +-+ +-+ +-+
	 *      |X| |X| |X|
	 *      +-+ +-+ +-+
	 */
}

void DemoWindow::render_cube()
{
	glBegin(GL_QUADS);

	glColor3d(1.0, 0.0, 0.0);		// Нижняя грань, красная
	glVertex3d(-1.0,  1.0, -1.0);
	glVertex3d( 1.0,  1.0, -1.0);
	glVertex3d( 1.0, -1.0, -1.0);
	glVertex3d(-1.0, -1.0, -1.0);

	glColor3d(0.0, 1.0, 1.0);		// Верхняя грань, бирюзовая
	glVertex3d(-1.0, -1.0,  1.0);
	glVertex3d( 1.0, -1.0,  1.0);
	glVertex3d( 1.0,  1.0,  1.0);
	glVertex3d(-1.0,  1.0,  1.0);

	glColor3d(0.0, 1.0, 0.0);		// Боковая грань, зеленая
	glVertex3d(-1.0,  1.0, -1.0);
	glVertex3d( 1.0,  1.0, -1.0);
	glVertex3d( 1.0,  1.0,  1.0);
	glVertex3d(-1.0,  1.0,  1.0);

	glColor3d(1.0, 0.0, 1.0);		// Боковая грань, фиолетовая
	glVertex3d( 1.0, -1.0, -1.0);
	glVertex3d(-1.0, -1.0, -1.0);
	glVertex3d(-1.0, -1.0,  1.0);
	glVertex3d( 1.0, -1.0,  1.0);

	glColor3d(0.0, 0.0, 1.0);		// Боковая грань, синяя
	glVertex3d( -1.0, 1.0, -1.0);
	glVertex3d(-1.0, -1.0, -1.0);
	glVertex3d(-1.0, -1.0,  1.0);
	glVertex3d(-1.0, 1.0,  1.0);

	glColor3d(1.0, 1.0, 0.0);		// Боковая грань, желтая
	glVertex3d(1.0, -1.0, -1.0);
	glVertex3d(1.0, 1.0, -1.0);
	glVertex3d(1.0, 1.0,  1.0);
	glVertex3d(1.0, -1.0,  1.0);

	glEnd();
}

void DemoWindow::update()
{
	_cube_angle += 0.1;
	if (_cube_angle >= 360.0)
		_cube_angle -= 360.0;
}
