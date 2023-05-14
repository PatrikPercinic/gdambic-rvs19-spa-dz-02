#pragma once
#include <cmath>
#include <vector>
#include <random>

using namespace std;

class Life
{
private:
	std::default_random_engine generator{ static_cast<long unsigned int>(time(0)) };
	static const unsigned int STUPACA = 180;
	static const unsigned int REDAKA = 320;
	vector<vector<bool>> alive;
	vector<vector<bool>> Temp_alive;
	bool random_bool();
	bool is_alive(int x, int y);
	int brojcelija;
	
public:
	Life();
	void step();
	vector<vector<bool>> GetLife();
	int GetBrojCelija();
};

