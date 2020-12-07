#include <stdio.h>
#include <string.h>

//����ü : �������� ������ ��� ���ο� ��������� ������ ����� ��.
//�÷��̾ ����ü�� ��� ǥ���ϸ� ����� ǥ���� �� �ڵ尡 ����������.
typedef struct {
	int nHP;
	int nATK;
}Player;

//Call by value
Player InitPlayerVal(Player player, int hp, int atk) {
	player.nHP = hp;
	player.nATK = atk;
	return player;
}
//Call by reference
void InitPlayerREF(Player *player, int hp, int atk) {
	player->nHP = hp;
	player->nATK = atk;
}
void StructFunctionTestMain() {
	Player sPlayer = { 100, 20 };
	printf("PlayerHP : %d\nPlayerATK : %d\n\n", sPlayer.nHP, sPlayer.nATK);
	sPlayer = InitPlayerVal(sPlayer, 200, 20);
	printf("PlayerHP : %d\nPlayerATK : %d\n\n", sPlayer.nHP, sPlayer.nATK);
	InitPlayerREF(&sPlayer, 300, 30);
	printf("PlayerHP : %d\nPlayerATK : %d\n\n", sPlayer.nHP, sPlayer.nATK);
}

int main(void) {
	StructFunctionTestMain();
	return 0;
}