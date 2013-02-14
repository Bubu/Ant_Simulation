//Ant Simulation is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.

// Authors: Guillaume Martinet, Lucas Tittmann
// Date: 01/2013

// Some code is based on the tutorials from:
//http://www.youtube.com/user/thecplusplusguy
// If so it is stated in the header. The original files are distributed under LPGL.
//
//The source files are also GPL v3.0 with 1 exception:
//grass.bmp is taken from
//http://www.public-domain-image.com/full-image/textures-and-patterns-public-domain-images-pictures/grass-texture-public-domain-images-pictures/buffalo-grass-texture.jpg-copyright-friendly-photo.html
//by Titus Tscharntke

#pragma once

// libraries
#include <windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>
#include <iostream>
#include <time.h>
#include "glext.h"
#include "OBJlib.h"

// self-created external depencies
#include "camera.h"
#include "skybox.h"
#include "loadpng_functions.h"
#include "models.h"
#include "general_constants.h"

class Ant_Sim
{
public:
	Ant_Sim(int, int, int);
	~Ant_Sim(void);
	void start(void);

private:
	int _FPS;
	int _cam_velocity;
	int _ant_number;
	bool _high_quality_on;
	bool _switch_fog_on;

	// system variables
	SDL_Surface *_prescreen;
	SDL_Surface *_screen;
	int _round_cnt;
	bool _mousein;
	unsigned int _tex_board;
	unsigned int _tex_border;
	unsigned int _tex_logo;
	Uint8 *_keystates;
	int _ant_model;

	// just for testing / not important
	float *_ant_posx;
	float *_ant_posz;
	//float _ant_posx[_ant_number];
	//float _ant_posz[_ant_number];
	float _ant_posy;
	float _ant_size;
	float _ant_angley;

	// methods
	void move_ants(void);
	void set_window(void);
	void set_openGL(void);
	void set_fog(void);
	void init(void);
	void display(VirtualAnim*, AnimMesh*);
};