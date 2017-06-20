#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "cgic.h"



char * headname = "head.html";
char * footname = "footer.html";
int cgiMain()
{

	fprintf(cgiOut, "Content-type:text/html;charset=utf-8\n\n");

	char classNo[10] = "\0";
	char className[30] = "\0";
	char grade[30] = "\0";

	int status = 0;
	int ret;
	//char sql[128] = "\0";
	char ch;
  FILE * fd;

//	fprintf(cgiOut, "Content-type:text/html;charset=utf-8\n\n");
	if(!(fd = fopen(headname, "r"))){
		fprintf(cgiOut, "Cannot open file, %s\n", headname);
		return -1;
	}
	ch = fgetc(fd);

	while(ch != EOF){
		fprintf(cgiOut, "%c", ch);
		ch = fgetc(fd);
	}
  fclose(fd);
	MYSQL *db;
	char sql[128] = "\0";

	status = cgiFormString("classNo",  classNo, 10);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get classNo error!\n");
		return 1;
	}



	status = cgiFormString("className",  className, 30);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get className error!\n");
		return 1;
	}

	status = cgiFormString("grade",  grade, 30);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get grade error!\n");
		return 1;
	}


	//fprintf(cgiOut, "name = %s, age = %s, stuId = %s\n", name, age, stuId);

	//初始化
	db = mysql_init(NULL);
	if (db == NULL)
	{
		fprintf(cgiOut,"mysql_init fail:%s\n", mysql_error(db));
		return -1;
	}

	//连接数据库
	db = mysql_real_connect(db, "127.0.0.1", "root", "1", "stu",  3306, NULL, 0);
	if (db == NULL)
	{
		fprintf(cgiOut,"mysql_real_connect fail:%s\n", mysql_error(db));
		mysql_close(db);
		return -1;
	}

mysql_set_character_set(db, "utf8");
	sprintf(sql, "update Class set className = '%s',grade= '%s' where classNo = '%s' ", className, grade,classNo);
	if ((ret = mysql_real_query(db, sql, strlen(sql) + 1)) != 0)
	{
		fprintf(cgiOut,"mysql_real_query fail:%s\n", mysql_error(db));
		mysql_close(db);
		return -1;

	}




	fprintf(cgiOut, "<p style='margin-left:20px;'>update Class ok!</p>");
	fprintf(cgiOut, "<input type='button' name='button1' id='button1' value='返回' onclick='history.go(-1)'  class='btn btn-default'>");
	mysql_close(db);
	return 0;
}
