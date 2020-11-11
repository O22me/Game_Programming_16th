#include <stdio.h>
#include <string.h>

//구조체 : 여러가지 변수를 묶어서 새로운 사용자정의 변수를 만드는 것.
//플레이어를 구조체로 묶어서 표현하면 대상을 표현할 때 코드가 간략해진다.
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