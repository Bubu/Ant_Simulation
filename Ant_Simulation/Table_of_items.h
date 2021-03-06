// This file is part of Ant_Simulation by Guillaume Martinet and Lucas Tittmann
// Check out the latest version at Github: https://github.com/Andarin/Ant_Simulation
#pragma once
#include "Ant.h"
#include "Colony.h"
#include "Food.h"
#include "Pheromone.h"
#include "Obstacle.h"
#include <list>
#include <vector>
#include <algorithm>
#include <map>

class Table_of_items					// This table regroup all the objects of the game
{								// It is created at the beginning and updated during the game
public:									// We use smart pointers to identify the objects
	Table_of_items(int,int);//The second int input is the size of the board and the first is
	~Table_of_items(void);	//number of sudivisions of the matrix M representing the map, 
	Table_of_items();				//i.e. dim M = n*n

	//Add functions :
	void add_ant (std::shared_ptr<Ant>);
	void add_colony (std::shared_ptr<Colony>);
	void add_food (std::shared_ptr<Food>);
	void add_pheromone (std::shared_ptr<Pheromone>);
	void add_obstacle (std::shared_ptr<Obstacle>);

	//Delete functions :
	void delete_ant (std::shared_ptr<Ant>);
	void delete_colony (std::shared_ptr<Colony>);
	void delete_food (std::shared_ptr<Food>);
	void delete_pheromone (std::shared_ptr<Pheromone>);
	void delete_obstacle (std::shared_ptr<Obstacle>);

	//Lists :
	std::list<std::shared_ptr<Ant>> _ant_list;
	std::list<std::shared_ptr<Colony>> _colony_list;
	std::list<std::shared_ptr<Food>> _food_list;
	//std::list<std::shared_ptr<Pheromone>> _pheromone_list; //working but too slow
	std::list<std::shared_ptr<Obstacle>> _obstacle_list;

	//Pheromone matrix :
	std::vector<std::vector<std::shared_ptr<Pheromone>>> _pheromone_matrix ;

	//Update functions :
	void update_passive(Uint32,Uint32) ; // for all the passive objects, i.e. colonies, pheromones and food

	// speed optimized functions
	void add_pheromone_opt(std::shared_ptr<Pheromone>);
	void update_passive_opt(Uint32,Uint32) ;
	std::map<int,std::shared_ptr<Pheromone>> _phero_map;

private:

	// Variables :

	int _board_size;	//Size of the board
	int _nbr_sub ;		//Number of subdivisions for the pheromone matrix
};
