/*
 * @Author: Weiqi Si 
 * @Date: 2018-09-27 15:24:01 
 * @Last Modified by: Weiqi Si
 * @Last Modified time: 2018-09-27 16:03:36
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(int argc,char *argv[])
{
	char *data;
	char *method;   
	char *len;		
	int data_len,read_len;

	/* CGI标准格式 */

	printf("Content-type:text/html;charset=utf-8\n\n"); 
	printf("\n");
	printf("<html><head>");
	printf("<title>CGI Login</title>");
	printf("</head><body>");
	printf("<h2 align='center'>KEY CHECKED RESULT</h2>");

	/* POST/GET 表单发送 */

	if (getenv("REQUEST_METHOD") == NULL)
	{
		printf("<p>No Request!");
		return -1;
	}
	else
	{
		method = getenv("REQUEST_METHOD");
	}

	if (strcmp(method,"POST")==0)
	{
		len = getenv("CONTENT_LENGTH");
		if (len != NULL)
		{
			data_len = atoi(len);
			data = (char*)malloc(data_len);
			read_len = fread(data, 1, data_len, stdin);
			if (read_len!=data_len)
			{
				return 0;
			}
		}
		else
		{
			return -1;
		}

		/* KEY校验 */

		if (!strcmp(&data[4], "fonda"))
		{
			printf("<p align='center'>RIGHT_KEY!</p>");
			printf("<meta http-equiv=\"Refresh\" content=\"1;URL=deviceRW.cgi\">");		//校验通过跳转
		}
		else
		{
			printf("<p align='center'>KEY_ERROR!</p>");
		}
		free(data);
	}
	else if (strcmp(method, "GET") == 0)
	{
		printf("<p>method is get</p>");
		if (getenv("QUERY_STRING") == NULL)
		{
			printf("<p>No data!<br>");
			return -1;
		}
		else
		{
			data = getenv("QUERY_STRING");
			data_len = strlen(data);

			if (!strcmp(&data[4], "fonda"))
			{
				printf("<p>RIGHT_KEY!</p>");
				printf("<meta http-equiv=\"Refresh\" content=\"1;URL=deviceRW.cgi\">");		//校验通过跳转
			}
			else
			{
				printf("<p>KEY_ERROR!</p>");
			}
		}
	}
		
	printf("</body></html>");
	return 0;
		
}


