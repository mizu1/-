#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int ATK_1, DEF_1, HP_1; //玩家的攻击力与防御力与生命
int ATK_2, DEF_2, HP_2; //计算机的攻击力与防御力与生命
int Input;//玩家的输入
int hit_c;//计算机的输入
void UpdateSystem() { //数据初始化
	ATK_1 = 10;
	DEF_1 = 5;
	HP_1 = 20;
	ATK_2 = 5;
	DEF_2 = 8;
	HP_2 = 22;

}

void show() { //显示画面
	printf("Player                    Computer\n");
	printf("ATK:%d                    ATK:%d\n", ATK_1, ATK_2);
	printf("DEF:%d                    DEF:%d\n", DEF_1, DEF_2);
	printf("HP:%d                     HP:%d\n", HP_1, HP_2);
	printf("1 普通攻击    ");
	printf("2 无视防御的攻击    ");
	printf("3 嘲讽    ");
	printf("4 颓废    \n");
	if (ATK_1 == 0)
		printf("Player成了废物\n");
	if (DEF_1 == 0)
		printf("Player马上要完了\n");
	if (HP_1 == 0)
		printf("Player成了活死人\n");
	if (ATK_2 == 0)
		printf("Computer成了废物\n");
	if (DEF_1 == 0)
		printf("Computer马上要完了\n");
	if (HP_1 == 0)
		printf("Computer成了活死人\n");
}

void UpdataWithInput() { //与用户输入有关的更新
	Input = getch();
	{
		if (Input == '1') //一技能普通攻击
			HP_2 = HP_2 - (ATK_1 - DEF_2); //伤害等于主动方攻击减去被动方防御
		if (Input == '2') //二技能无视防御的攻击
			HP_2 = HP_2 - 2;
		if (Input == '3') { //三技能降低对方防御力
			DEF_2 -= 1;
			printf("你问候了对方的家长，对方破防了\n");
		}
		if (Input == '4') { //四技能降低对方攻击力
			ATK_2 -= 1;
			printf("你色诱了对方，对方的攻击力降低了\n");
		}
	}
	printf("玩家使用了%c技能\n", Input);
}

void UpdataWithoutInput() { //与用户输入无关的更新
	hit_c = rand() % 4;
	if (hit_c == 0)
		HP_1 = HP_1 - (ATK_2 - DEF_1);
	if (hit_c == 1)
		HP_1 = HP_1 - 2;
	if (hit_c == 2) {
		DEF_1 -= 1;
		printf("对方问候了你的家长，你破防了\n");
	}
	if (hit_c == 3) {
		ATK_1 -= 1;
		printf("对方色诱了你，你的攻击力降低了\n");
	}
	printf("电脑使用了%d技能\n\n", hit_c + 1);
}

void main() {
	UpdateSystem();//数据初始化
	while (1) {
		show();//显示画面
		UpdataWithInput();//与用户输入有关的更新
		UpdataWithoutInput();//与用户输入无关的更新
		if (HP_1 <= -100) {
			printf("你输了,不想输可以给作者充钱索要无敌版\n");//当然也可以自己改代码2333
			break;
		}
		if (HP_2 <= -100) {
			printf("你赢了，赢麻了\n");
			break;
		}
	}


}
