// SaiboDingZhen.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// create : b站 [内田补水彩] https://space.bilibili.com/11895443

#include <stdio.h>
#define u8 unsigned char
#define forceConLength 128

u8 forceCon[forceConLength] = { 0 };//SaiBoDingzhen数组
u8 forceCon_tmp[forceConLength] = { 0 };//临时缓存数组
u8 indextable[forceConLength] = { 0 };//索引数组

//感谢博客园StrayedKing https://www.cnblogs.com/kangjianwei101/p/5220336.html 提供思路
//功能：从字符串中提取数字，并包含数字索引信息
//因为u8定义为unsigned char，powerCon函数无法传递数组指针，被迫将下述函数返回值为0，数字索引为全局变量。
u8 r = 0;
u8 p, q, cnt = 0;

int string2nums(char *nums) {
	while (1) {

		while (nums[r] && (nums[r]<'0' || nums[r]>'9'))
			r++;

		if (nums[r])
		{
			p = r;
			q = r + 1;
			indextable[cnt] = nums[r] - '0';

			while (nums[q] >= '0'&&nums[q] <= '9') {
				indextable[cnt] = 10 * indextable[cnt] + (nums[q] - '0');
				q++;
			}
			r = q;
			cnt++;
		}
		else
			break;
	}
	return 0;
}

//SaiBoDingzhen
void powerCon(u8 whichKey, u8 force) {
	if (whichKey) {
		forceCon[whichKey - 1] = force;
	}
	else {
		for (u8 i = 0; i < 68; i++) {
			forceCon[i] = force;
		}
	}
}
//下面宏定义感谢b站up [摸鱼摸摸鱼鱼] https://www.bilibili.com/video/BV1zW4y1h7YH 提醒
#define powerCon(nums, force) powerCon(string2nums(#nums), force)

//SaiBoDingzhen
void littleFingerForce() {
	powerCon(1 | 2 | 6 | 7 | 11 | 52 | 57 | 58 | 65, 10);
}


int main()
{
	printf("I am SaiBoDingZhen!\n");
	//SaiBoDingzhen
	littleFingerForce();
	//索引位置赋值，其他为0
	for (u8 k = 0; k < cnt; k++)
		forceCon_tmp[indextable[k]] = forceCon[indextable[k]];

	//向原数组赋值，并打印输出
	for (u8 j = 0; j < forceConLength; j++) {
		forceCon[j] = forceCon_tmp[j];
		printf("%d -> %d\n", j, forceCon[j]);
	}
}

