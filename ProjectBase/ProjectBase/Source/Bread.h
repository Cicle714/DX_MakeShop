#include "../Library/GameObject.h"
#include "Screen.h"
#include <string>
#include <vector>

class Bread : public GameObject
{
public:
	Bread();
	~Bread();
	void Update() override;
	void Draw() override;


	VECTOR position;
	VECTOR centerPosition;

	bool Fire;
private:
	bool Push;

	int ObjectSize;

	int mugi;
	int Bread1;
	int Bread2;

	bool Hold;
};