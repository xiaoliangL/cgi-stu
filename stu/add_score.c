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

	char studentNo[32] = "\0";
	char courseNo[32] = "\0";
	int status = 0;
	char score[30] = "\0";
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

	status = cgiFormString("studentNo",  studentNo, 32);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get studentNo error!\n");
		return 1;
	}

	status = cgiFormString("courseNo",  courseNo, 32);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get courseNo error!\n");
		return 1;
	}

	status = cgiFormString("score",  score, 30);
  if (status != cgiFormSuccess)
  {
 	 fprintf(cgiOut, "get score error!\n");
 	 return 1;
  }


	//fprintf(cgiOut, "name = %s, age = %s, stuId = %s\n", name, age, stuId);

	int ret;
	char sql[128] = "\0";
	MYSQL *db;

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

/*

	strcpy(sql, "create table stu(id int not null primary key, name varchar(20) not null, age int not null)");
	if ((ret = mysql_real_query(db, sql, strlen(sql) + 1)) != 0)
	{
		if (ret != 1)
		{
			fprintf(cgiOut,"mysql_real_query fail:%s\n", mysql_error(db));
			mysql_close(db);
			return -1;
		}
	}

*/
mysql_set_character_set(db, "utf8");
/*
fprintf(cgiOut, "name = %s, age = %s, stuId = %s stu_address = %s\n", name, age, stu_id,stu_address);*/
	sprintf(sql, "insert into Score(studentNo,courseNo,score) values('%s', '%s', '%s')",studentNo, courseNo,score);
	if (mysql_real_query(db, sql, strlen(sql) + 1) != 0)
	{
		fprintf(cgiOut, "%s\n", mysql_error(db));
		mysql_close(db);
		return -1;
	}

	fprintf(cgiOut, "<p style='margin-left:20px;'>添加成绩完成!</p> ");
	fprintf(cgiOut, "<input type='button' name='button1' id='button1' value='返回' onclick='history.go(-1)'  class='btn btn-default'>");
	fprintf(cgiOut, "    <a href='../../index.html' class='btn btn-success'>点我回首页</a> </body></html> ");

	mysql_close(db);
	return 0;
}
