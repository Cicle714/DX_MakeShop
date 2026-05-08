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

private:
	bool Fire;
	bool Push;

	int ObjectSize;

	int mugi;
	int Bread1;
	int Bread2;
};