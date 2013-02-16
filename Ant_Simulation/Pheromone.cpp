#include "Pheromone.h"

Pheromone::~Pheromone(void)
{
}

double Pheromone::calc_size_by_energy (double energy)
{
	return 300*energy/(energy+1);
}

void Pheromone::merge_pheromone(Pheromone other_phero)
{
	_energy += other_phero._energy;
	other_phero.destroy();
}

void Pheromone::update(Uint32 time, Uint32 time_step)
{
	_energy = std::max<double>(0, _energy - _energy_consumption_per_m*time_step/60000);
	_size = calc_size_by_energy(_energy);
	if (_energy == 0)
	{
		destroy();
	}
}