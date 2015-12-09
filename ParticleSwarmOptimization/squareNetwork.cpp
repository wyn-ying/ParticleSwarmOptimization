#include "squareNetwork.h"
//为了结构整齐只有49个粒子，注意改粒子数

network squareConstruct()
{
	network square;
	for (int i = 0;i < 49; i++) {
		square[i].neighborsID.push_back((i + 48) % 49);
		square[i].neighborsID.push_back((i + 1) % 49);
		square[i].neighborsID.push_back((i + 42) % 49);
		square[i].neighborsID.push_back((i + 7) % 49);
	}
	return square;
}