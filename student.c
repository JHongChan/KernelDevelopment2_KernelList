#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "list.h"



/* 定义学生的数据类型 */
struct student {
	char name[32];
	int id;
	struct list_head list;
};

/* 创建链表，链表名是student_list */
struct student student_list={
	.list=LIST_HEAD_INIT((student_list.list)),
};

int main(int argc, char **argv)
{
	/* 判断链表是否为空链表 */
	if(list_empty(&(student_list.list)))
		printf("student_list is empty!\n");
	else
		printf("student_list is not empty!\n");

	/* 向链表中添加节点 */
	struct student *one = (struct student *)malloc(sizeof(struct student));
	strcpy(one->name,"liming");
	one->id = 1;
	list_add(&(one->list),&(student_list.list));/* 将one 添加到链表student_list中 */

	one = (struct student *)malloc(sizeof(struct student));
	strcpy(one->name,"lingzhitao");
	one->id = 2;
	list_add_tail(&(one->list),&(student_list.list));/* 添加到链表student_list的尾部 */


	/* 遍历链表 */
	list_for_each_entry(one,&(student_list.list),list)
	{
		printf(" ID: %d\t name:%s\n",one->id,one->name); //打印信息
	}

	/* 删除一个节点 */
	list_del(student_list.list.prev);

	/* 再次遍历链表 */
	printf("del one node ,list is:\n");
	list_for_each_entry(one,&(student_list.list),list)
	{
		printf(" ID: %d\t name:%s\n",one->id,one->name); //打印信息
	}

    /* 再次判断链表是否为空 */
	if(list_empty(&(student_list.list)))
		printf("list is empty!\n");
	else
		printf("list is not empty!\n");

return 0;
}

