#include "ObjectManager.h"
#include "GameObject.h"
#include <algorithm>
#include <assert.h>

namespace
{
	std::list<ObjectManager::ObjectUpdate> updateObjects;
	std::list<GameObject*> drawObjects;
	bool needSortUpdate;
	bool needSortDraw;
	GameObject* running;
}

void ObjectManager::Start()
{
	updateObjects.clear();
	drawObjects.clear();
	needSortUpdate = false;
	needSortDraw = false;
	running = nullptr;
}

void deleteDrawObject(GameObject* obj)
{
	for (auto it = drawObjects.begin(); it != drawObjects.end(); )
	{
		if ((*it) == obj)
		{
			it = drawObjects.erase(it);
		}
		else
		{
			it++;
		}
	}
}

void ObjectManager::Update()
{
	if (needSortUpdate)
	{
		updateObjects.sort([](ObjectUpdate& a, ObjectUpdate& b) {return a.object->GetPriority() < b.object->GetPriority(); });
		needSortUpdate = false;
	}
	for (auto it = updateObjects.begin(); it != updateObjects.end(); )
	{
		ObjectUpdate& node = *it;
		GameObject* obj = node.object;
		if (!node.initialized)
		{
			obj->Start();
			node.initialized = true;
		}
		running = obj;
		obj->Update();
		running = nullptr;
		if (obj->DestroyRequested())
		{
			deleteDrawObject(obj);
			delete obj;
			it = updateObjects.erase(it);
		}
		else
		{
			it++;
		}
	}
}

void ObjectManager::Draw()
{
	if (needSortDraw)
	{
		drawObjects.sort([](GameObject* a, GameObject* b) {return a->GetDrawOrder() > b->GetDrawOrder(); });
		needSortDraw = false;
	}
	for (GameObject* node : drawObjects)
	{
		running = node;
		node->Draw();
		running = nullptr;
	}
}

void ObjectManager::Release()
{
	for (auto it = updateObjects.begin(); it != updateObjects.end(); it++)
	{
		ObjectUpdate& node = *it;
		delete node.object;
	}
	updateObjects.clear();
	drawObjects.clear();
}

void ObjectManager::Push(GameObject* obj)
{
	{
		ObjectUpdate node;
		node.object = obj;
		updateObjects.emplace_back(node);
		needSortUpdate = true;
	}
	{
		drawObjects.emplace_back(obj);
		needSortDraw = true;
	}
}

const std::list<ObjectManager::ObjectUpdate>& ObjectManager::GetAllObject()
{
	return updateObjects;
}

void ObjectManager::SortByPriority()
{
	needSortUpdate = true;
}

void ObjectManager::SortByDrawOrder()
{
	needSortDraw = true;
}


void ObjectManager::DeleteGameObject(GameObject* obj)
{
	assert(running != obj);

	delete obj;
	deleteDrawObject(obj);
	for (auto it = updateObjects.begin(); it != updateObjects.end(); )
	{
		ObjectUpdate& node = (*it);
		if (node.object == obj)
		{
			it = updateObjects.erase(it);
		}
		else
			it++;
	}
}

void ObjectManager::DeleteAllGameObject()
{
	assert(running == nullptr);

	for (auto it = updateObjects.begin(); it != updateObjects.end();)
	{
		ObjectUpdate& node = *it;
		if (!node.object->IsDontDestroy())
		{
			deleteDrawObject(node.object);
			delete node.object;
			it = updateObjects.erase(it);
		}
		else
			it++;
	}
}
