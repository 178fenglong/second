#include <stdio.h>
#include <string.h>
#define    N   10
int  fun(char* s)
{
	int i, j = 0;
	for (i = 0; s[i] != '\0'; i++)
		if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0'))   /*如果一个字母的下一个字符为空格或者结束标记,则表示一个单词结束*/
			j++;
	return j;           /*返回单词个数*/
}
main()
{
	char  line[N];
	int  num = 0;
	void NONO();/*声明void NONO()*/
	printf("Enter a string :\n");
	gets(line);/*文本行输入函数,从标准输入设备读取字符串line[N]*/
	num = fun(line);
	printf("The number of word is  :  %d\n\n", num);
	NONO();
}
void NONO()
{/* 请在此函数内打开文件,输入测试数据,调用 fun 函数,输出数据,关闭文件。 */
	FILE* rf, * wf;/*文件指针变量*/
	int i, num;
	char line[N], * p;
	rf = fopen("in.dat", "r");/*如果文件成功打开，该函数将返回指向​​FILE​​对象的指针；失败则返回空指针*/
	wf = fopen("out.dat", "w");
	for (i = 0; i < 5; i++)
	{
		fgets(line, N, rf); /*(N)读取最大的字节数,从标准输入设备输入的数据流rf存储到line所指的字符串中*/
		p = strchr(line, '\n');
		if (p != NULL)
		*p = 0;
		num = fun(line);
		fprintf(wf, "%d\n", num);/*从指定的输出数据流wf中写入num数据*/
	}
	fclose(rf);
	fclose(wf);
}
