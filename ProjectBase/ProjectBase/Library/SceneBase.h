#pragma once

/// <summary>
/// シーンの基底クラス
/// </summary>
/// <author>N.Hanai</author>

#include <list>
#include "SceneManager.h"
#include "GameObject.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class SceneBase
{
public:
	SceneBase();
	virtual ~SceneBase();

	virtual void Update() {}
	virtual void Draw() {}
    std::vector<std::vector<std::string>> LoadCSV(const std::string& filename) {
        std::vector<std::vector<std::string>> data;
        std::ifstream file(filename);

        std::string line;
        while (std::getline(file, line)) {
            std::vector<std::string> row;
            std::stringstream ss(line);
            std::string cell;

            while (std::getline(ss, cell, ',')) {
                row.push_back(cell);
            }

            data.push_back(row);
        }

        return data;
    }
};
