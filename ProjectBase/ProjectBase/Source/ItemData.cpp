#include "ItemData.h"

ItemData::ItemData()
{
	auto csv = LoadCSV("Items.csv");
    ItemDatas = new std::string[csv.size(),DataNum];

    for (int i = 0; i < csv.size(); i++) {
        ItemDatas[i] = std::stoi(csv[i][0]);
    }
}

ItemData::~ItemData()
{
}

void ItemData::Update()
{
}

void ItemData::Draw()
{
}
