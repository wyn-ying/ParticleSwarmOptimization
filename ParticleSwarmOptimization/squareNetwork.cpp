#include "squareNetwork.h"
//Ϊ�˽ṹ����ֻ��49�����ӣ�ע���������

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