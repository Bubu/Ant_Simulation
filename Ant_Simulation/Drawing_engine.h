// This file is part of Ant_Simulation by Guillaume Martinet and Lucas Tittmann
// Check out the latest version at Github: https://github.com/Andarin/Ant_Simulation

// observer of the simulation; class to handle all render and display
// aspects
#pragma once
// libraries
#ifdef _WIN32
	#include "windows.h"
	#include <SDL.h>
	#include <SDL_image.h>
#else
	#include <SDL/SDL.h>
	#include <SDL/SDL_image.h>
#endif
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include "glfont2.h"
#include <cmath>
#include <iostream>
#include <sstream>
#include <time.h>
#include "glext.h"
#include "OBJlib.h"

// self-created external depencies
#include "Camera.h"
#include "loadpng_functions.h"
#include "skybox.h"
#include "models.h"
#include "general_constants.h"

class Ant_Sim;

class Drawing_engine
{
public:
	Drawing_engine(void);
	~Drawing_engine(void);
	void init(void);
	void switch_fog_no_fog(void);
	void switch_good_bad_graphics(void);
	void display(Ant_Sim*, Uint32, int);
	void clean_up(void);
	void start_countdown(void);
	void print_cam_pos(void);
	void left_mouse_click(void);
	void left_mouse_unclick(void);

private:
	int _cam_velocity;
	int _recent_cam_velocity;
	Camera _camera;

	bool _mousein;
	bool _countdown_on;
	bool _high_quality_on;
	bool _switch_fog_on;

	SDL_Surface *_prescreen;
	SDL_Surface *_screen;
	SDL_Surface *_logo;
	unsigned int _tex_board;
	unsigned int _tex_border;
	unsigned int _tex_colony;
	unsigned int _tex_box;
	unsigned int _tex_apple_side;
	unsigned int _tex_apple_top;
	unsigned int _tex_logo;
	unsigned int _tex_result;
	unsigned int _tex_result_pointer;
	glfont::GLFont _screen_text;
	MeshObj* _ant_hq_array[8];
	MeshObj* _apple_hq_array[5];
	Uint8 *_keystates;

	// methods
	// set initial statements
	void set_window(void);
	void set_openGL(void);
	void load_textures(void);
	void load_hq_models(void);

	// declare fog which can be enabled
	void init_fog(void);

	// switch between differents perspectives for scene and HUD
	void switch_to_normal_perspective(int);
	void switch_to_ortho_perspective(void);

	// draw things to the screen
	void draw_text(std::string, float, float);
	void draw_text_with_number(std::string, int, float, float);
	void draw_text_with_number(std::string, double, float, float);
	void draw_countdown(int);
	void draw_hud(Uint32, Ant_Sim*);
	void draw_test_ants(Ant_Sim*,int,int);
	void draw_ants(Ant_Sim*,int);
	void draw_food(Ant_Sim*);
	void draw_obstacles(Ant_Sim*);
	void draw_colonies(Ant_Sim*);
	void draw_location_selected_on_board(void);
	void draw_result(double);

	// help functions for the result drawing
	double get_food_starting_value(void);
	double calc_result(Ant_Sim*);
};