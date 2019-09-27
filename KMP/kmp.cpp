//代码来自数据结构：邓俊辉
#include <stdio.h>
#include <iostream>
using namespace std;
#define printString(s) { for (size_t m = strlen(s), k = 0; k < m; k++) printf("%4c", (s)[k]); }

void printNext(int* N, int offset, int length) {
	for (int i = 0; i < length; i++) printf("%4d", i); printf("\n");
	for (int i = 0; i < offset; i++) printf("    ");
	for (int i = 0; i < length; i++) printf("%4d", N[i]); printf("\n\n");
}
void showProgress(char* T, char* P, int i, int j) {
	static int step = 0; //操作计数器
	printf("\n-- Step %2d: --\n", ++step);
	for (size_t n = strlen(T), t = 0; t < n; t++) printf("%4d", t); printf("\n");
	printString(T); printf("\n");
	if (0 <= i + j)
		 {
		for (int t = 0; t < i + j; t++) printf("%4c", ' '); printf("%4c", '|');
	}
	printf("\n");
	for (int t = 0; t < i; t++) printf("%4c", ' ');
	printString(P); printf("\n");
}
int* buildNext(char* P) { //构造模式串P的next表
	size_t m = strlen(P), j = 0; //“主”串指针
	int* N = new int[m]; //next表
	int t = N[0] = -1; //模式串指针
	while (j < m - 1)
		if (0 > t || P[j] == P[t]) { //匹配
			j++; t++;
			N[j] = t; //此句可改进...
		}
		else //失配
			t = N[t];
	//printString(P); printf("\n");
	//printNext(N, 0, m);
	return N;
}
int match(char* P, char* T) {  //KMP算法
	int* next = buildNext(P); //构造next表
	int n = (int)strlen(T), i = 0; //文本串指针
	int m = (int)strlen(P), j = 0; //模式串指针
	while (j < m && i < n) //自左向右逐个比对字符
		 {
		//showProgress(T, P, i - j, j);
		//printNext(next, i - j, strlen(P));
		//getchar(); printf("\n");
		if (0 > j || T[i] == P[j]) //若匹配，或P已移出最左侧（两个判断的次序不可交换）
		{
			i++;  j++;
		} //则转到下一字符
		else //否则
			j = next[j]; //模式串右移（注意：文本串不用回退）
		 
	}
	delete[] next; //释放next表
	return i - j;
}

void main(void) {
	char s1[] = "ABCDABCEAAAABASABCDABCADABCDABCEAABCDABCEAAABASABCDABCAABLAKABCDABABCDABCEAAADSFDABCADABCDABCEAAABCDABCEAAABASABCDABCADABCDABCEAAABLAKABLAKK";
	char s2[] = "ABCDABCEAAABASABCDABCADABCDABCEAAABLAK";
	//char s1[] = "abcababbaabcd";
	//char s2[] = "abcd";
	int pos = match(s2, s1);
	cout << pos<< endl;
}
