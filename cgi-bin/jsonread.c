#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>
#include<memory.h>

#define MAX_DEVICE_NUM 20
#define MAX_DEVICE_KEY_LEN 128 //最大键值字节数
#define MAX_DATAOUTPUT_LEN 2048 //最大Json数据字节

#define leftBraces  "{"
#define rightBraces  "}"
#define leftMidBraces "["
#define rightMidBraces "]"
#define quot  "\""
#define blank  " "
#define colon  ":"
#define comma  ","
#define doublebackslash  "\\\\"

typedef struct Device
{
	char name[MAX_DEVICE_KEY_LEN];
	char enabled[MAX_DEVICE_KEY_LEN];
	char connMode[MAX_DEVICE_KEY_LEN];
	char connType[MAX_DEVICE_KEY_LEN];
	char deviceId[MAX_DEVICE_KEY_LEN];
	char factoryId[MAX_DEVICE_KEY_LEN];
	char versionId[MAX_DEVICE_KEY_LEN];
	char address[MAX_DEVICE_KEY_LEN];
	char port[MAX_DEVICE_KEY_LEN];
	char timeout[MAX_DEVICE_KEY_LEN];
	char deviceKey[MAX_DEVICE_KEY_LEN];
};

int content_parse(char* content_output, const char *content_input)
{
	char *pstart, *pend;
	//char *content_output;
	int  lang_len,cuid_len,screenPath_len,name_len, enabled_len, connMode_len, connType_len, deviceId_len, factoryId_len, versionId_len, address_len, port_len, timeout_len, deviceKey_len;
	int  device_cnt = 0;
	//filter
	content_filter(content_input, "%5C");
	content_filter(content_input, "%3A");
	content_filter(content_input, "+");
	//
	pstart = (char*)content_input;
	/*content_output前置大括号*/
	strcat(content_output, leftBraces);

	/*lang输入*/
	if(find_device_cnt(content_input,"lang=")==0)
	{
		//return 0;
	}
	else
	{
		char lang[MAX_DEVICE_KEY_LEN] = { 0 };
		pstart = strstr(pstart, "lang=");
		if (NULL == pstart)
		{
			return 0;
		}
		pend = strchr(pstart, '&');
		lang_len = pend - (pstart + 5);
		//存入lang数组
		strncpy(lang, pstart + 5, lang_len);
		tojsonroot(lang, "lang");
		//存入content_output
		strcat(content_output, lang);
		strcat(content_output, comma);
	}
	/* cuid输入 */
	if (find_device_cnt(content_input, "cuid=") == 0)
	{
		//return 0;
	}
	else
	{
		char cuid[MAX_DEVICE_KEY_LEN] = { 0 };
		pstart = strstr(pstart, "cuid=");
		if (NULL == pstart)
		{
			return 0;
		}
		pend = strchr(pstart, '&');
		cuid_len = pend - (pstart + 5);
		//存入cuid数组
		strncpy(cuid, pstart + 5, cuid_len);
		tojsonroot(cuid, "cuid");
		strcat(content_output, cuid);
		strcat(content_output, comma);
	}
	/*screenPath输入*/
	if (find_device_cnt(content_input, "screenPath=") == 0)
	{
		//return 0;
	}
	else
	{
		char screenPath[MAX_DEVICE_KEY_LEN] = { 0 };
		pstart = strstr(pstart, "screenPath=");
		if (NULL == pstart)
		{
			return 0;
		}
		pend = strchr(pstart, '&');
		screenPath_len = pend - (pstart + 11);
		//存入screenPath数组
		strncpy(screenPath, pstart + 11, screenPath_len);
		tojsonroot(screenPath, "screenPath");
		strcat(content_output, screenPath);
		strcat(content_output, comma);
	}

	/* 返回设备数量 */
	device_cnt = find_device_cnt(content_input, "name=");//��name=Ϊ��־����device����
	//printf("<p>%d</s>", device_cnt);
	if (device_cnt == 0||device_cnt > MAX_DEVICE_NUM)
	{
		//return 0;
	}

	char device_content_output[MAX_DATAOUTPUT_LEN] = { 0 };
	struct Device device[MAX_DEVICE_NUM];
	
	/* device_output中输入每个device信息 */
	int i;
	for (i = 0; i < device_cnt; i++)
	{
		/*
		* betwen the pstart and pend is useful data,
		*
		*/
		/*store device struct*/

		pstart = strstr(pstart, "name=");
		if (NULL == pstart)
		{
			return 0;
		}
		pend = strchr(pstart, '&');
		name_len = pend - (pstart + 5);
		//初始化device结构对象字符数组
		memset(device[i].name, 0, sizeof(device[i].name));
		strncpy(device[i].name, pstart + 5, name_len);
		
		//enable info
		//pstart = pend + 1;
		pstart = strstr(pstart, "enabled=");
		if (NULL == pstart)
		{
			return 0;
		}
		pend = strchr(pstart, '&');//get enabledinfo
		enabled_len = pend - (pstart + 8);
		memset(device[i].enabled, 0, sizeof(device[i].enabled));
		strncpy(device[i].enabled, pstart + 8, enabled_len);
		
		//connMode info
		
		pstart = strstr(pstart, "connMode=");
		if (NULL == pstart)
		{
			return 0;
		}
		pend = strchr(pstart, '&');
		connMode_len = pend - (pstart + 9);
		memset(device[i].connMode, 0, sizeof(device[i].connMode));
		strncpy(device[i].connMode, pstart + 9, connMode_len);
		
		//connType
		
		pstart = strstr(pstart, "connType=");
		if (NULL == pstart)
		{
			return 0;
		}
		pend = strchr(pstart, '&');
		connType_len = pend - (pstart + 9);
		memset(device[i].connType, 0, sizeof(device[i].connType));
		strncpy(device[i].connType, pstart + 9, connType_len);
		
		//deviceId
		
		pstart = strstr(pstart, "deviceId=");
		if (NULL == pstart)
		{
			return 0;
		}
		pend = strchr(pstart, '&');
		deviceId_len = pend - (pstart + 9);
		memset(device[i].deviceId, 0, sizeof(device[i].deviceId));
		strncpy(device[i].deviceId, pstart + 9, deviceId_len);
		
		//factoryId
		
		pstart = strstr(pstart, "factoryId=");
		if (NULL == pstart)
		{
			return 0;
		}
		pend = strchr(pstart, '&');
		factoryId_len = pend - (pstart + 10);
		memset(device[i].factoryId, 0, sizeof(device[i].factoryId));
		strncpy(device[i].factoryId, pstart + 10, factoryId_len);
		
		//versionId
		
		pstart = strstr(pstart, "versionId=");
		if (NULL == pstart)
		{
			return 0;
		}
		pend = strchr(pstart, '&');
		versionId_len = pend - (pstart + 10);
		memset(device[i].versionId, 0, sizeof(device[i].versionId));
		strncpy(device[i].versionId, pstart + 10, versionId_len);
		
		//address
		
		pstart = strstr(pstart, "address=");
		if (NULL == pstart)
		{
			return 0;
		}
		pend = strchr(pstart, '&');
		address_len = pend - (pstart + 8);
		memset(device[i].address, 0, sizeof(device[i].address));
		strncpy(device[i].address, pstart + 8, address_len);
		
		//port
		
		pstart = strstr(pstart, "port=");
		if (NULL == pstart)
		{
			return 0;
		}
		pend = strchr(pstart, '&');
		port_len = pend - (pstart + 5);
		memset(device[i].port, 0, sizeof(device[i].port));
		strncpy(device[i].port, pstart + 5, port_len);
		
		//timeout
		
		pstart = strstr(pstart, "timeout=");
		if (NULL == pstart)
		{
			return 0;
		}
		pend = strchr(pstart, '&');
		timeout_len = pend - (pstart + 8);
		memset(device[i].timeout, 0, sizeof(device[i].timeout));
		strncpy(device[i].timeout, pstart + 8, timeout_len);

		//deviceKey
		
		pstart = strstr(pstart, "deviceKey=");
		if (NULL == pstart)
		{
			return 0;
		}

		//判断是否遍历到字符串结尾

		pend = strchr(pstart, '&');
		if (NULL == pend)
		{
			pend = strchr(pstart, '\0');
		}
		deviceKey_len = pend - (pstart + 10);
		memset(device[i].deviceKey, 0, sizeof(device[i].deviceKey));
		strncpy(device[i].deviceKey, pstart + 10, deviceKey_len);
	}
	for (i = 0; i < device_cnt; i++)
	{
		
		/* 将内容加入字符链 */
		tojson(device[i], device_content_output);
		if (i!=device_cnt - 1)
		{
			strcat(device_content_output, comma);
		}
		
	}
	tojsonroot(device_content_output,"devices");
	strcat(content_output,device_content_output);
	strcat(content_output, rightBraces);
	strcat(content_output, "\n");
	//printf("<p>%s</s>", content_output);
	return 1;
}
/*filter useless str*/
void content_filter(char* content_input,char* str)
{
	//临时数组
	char temphead[MAX_DATAOUTPUT_LEN/2] = { 0 };
	char tempend[MAX_DATAOUTPUT_LEN/2] = { 0 };
	char temp[MAX_DATAOUTPUT_LEN] = { 0 };

	strncpy(temp, content_input, strlen(content_input));
	int str_len = strlen(str);

	char *pstart;
	char *pend;
	//char *pend;
	//遍历字符串
	while (pstart=strstr(temp,str))
	{
		pend = pstart + str_len;
		/* 截取有效字段 */
		memset(temphead, 0, sizeof(temphead));
		memset(tempend, 0, sizeof(tempend));
		strncpy(temphead,temp,pstart-temp);
		strncpy(tempend, pend,strlen(temp)-(pend-temp));
		
		memset(temp, 0, sizeof(temp));
		strcat(temp, temphead);
		if (str=="%5C")
		{
			strcat(temp,doublebackslash);
		}
		else if(str=="%3A")
		{
			strcat(temp, colon);
		}
		else if (str == "+")
		{
			strcat(temp,blank);
		}
		strcat(temp, tempend);
	}
	//printf("<p>%s</p>", temp);
	memset(content_input, 0, strlen(content_input));
	strncpy(content_input, temp, strlen(temp));
	//printf("<p>%s</p>",content_input);
	
}
	

/*count device num*/
int find_device_cnt(char *str1, char *str2)
{
	int len = strlen(str2);
	int cnt = 0;
	while (str1 = strstr(str1, str2))
	{
		cnt++;
		str1 += len;//加上偏移量
	}
	return cnt;
}

/*device struct tojson*/
void tojson(struct Device device, char* content_output)
{
	strcat(content_output, leftBraces);
	construct(device.name, "name");
	strcat(content_output, device.name);
	construct(device.enabled, "enabled");
	strcat(content_output, device.enabled);
	construct(device.connMode, "connMode");
	strcat(content_output, device.connMode);
	construct(device.connType, "connType");
	strcat(content_output, device.connType);
	construct(device.deviceId, "deviceId");
	strcat(content_output, device.deviceId);
	construct(device.factoryId, "factoryId");
	strcat(content_output, device.factoryId);
	construct(device.versionId, "versionId");
	strcat(content_output, device.versionId);
	construct(device.address, "address");
	strcat(content_output, device.address);
	construct(device.port, "port");
	strcat(content_output, device.port);
	construct(device.timeout, "timeout");
	strcat(content_output, device.timeout);
	construct(device.deviceKey, "deviceKey");
	strcat(content_output, device.deviceKey);
	strcat(content_output, rightBraces);

}
/*add jsonroot */
void tojsonroot(char* key_value, char* key)
{
	//临时json root数组
	char temp[MAX_DATAOUTPUT_LEN] = { 0 };
	int temp_value_len;
	strcat(temp, quot);
	strcat(temp, key);
	strcat(temp, quot);
	strcat(temp, colon);
	if (key!="devices")
	{
		strcat(temp, quot);
		strcat(temp, key_value);
		strcat(temp, quot);
	}
	else
	{
		strcat(temp, leftMidBraces);
		strcat(temp, key_value);
		strcat(temp, rightMidBraces);
	}

	memset(key_value, 0, sizeof(key_value));
	temp_value_len = strlen(temp);
	strncpy(key_value, temp, temp_value_len);

}

void construct(char* key_value, char* key)
{
	//临时json数组
	char temp[MAX_DEVICE_KEY_LEN] = {0};
	int temp_value_len;
	strcat(temp, quot);
	strcat(temp, key);
	strcat(temp, quot);
	strcat(temp, colon);
	if (key == "name"||key =="address")
	{
		strcat(temp, quot);
		strcat(temp, key_value);
		strcat(temp, quot);
	}
	else
	{
		strcat(temp, key_value);
	}
	/*strcat(temp, quot);
	strcat(temp, key_value);
	strcat(temp, quot);*/
	if (key != "deviceKey")
	{
		strcat(temp, comma);
	}

	memset(key_value,0,sizeof(key_value));
	temp_value_len = strlen(temp);
	strncpy(key_value, temp,temp_value_len );

}



int main(void)
{
	printf("Content-type:text/html;charset=utf-8\n\n");//standard response header
	printf("\n");
	printf("<html><head>");

	FILE *fp;
	char *data;
	char content_output[MAX_DATAOUTPUT_LEN];
	char *method;    
	char *len;		
	int data_len, read_len;
	int content_output_flag;

	//接收Browser端数据
	if (getenv("REQUEST_METHOD") == NULL)
	{
		printf("<p>No Request!");
		return -1;
	}
	else
	{
		method = getenv("REQUEST_METHOD");
	}
	if (strcmp(method, "POST") == 0)
	{
		//printf("<p>method is post</p>");
		len = getenv("CONTENT_LENGTH");
		//printf("<p>%s</p>",len);
		if (len != NULL)
		{
			data_len = atoi(len);
			data = (char*)malloc(data_len);
			read_len = fread(data, 1, data_len, stdin);
			if (read_len != data_len)
			{
				return 0;
			}
			//printf("<p>%s</p>",data);

			/*data transfer*/
			memset(content_output,0,sizeof(content_output));
			content_output_flag = content_parse(content_output, data);
			if(content_output_flag==0)
			{
				printf("<p style='font-weight:bold'>SAVE_EDIT_ERROR!</p>");
				return 0;
			}
			else
			{
				printf("<p style='font-weight:bold'>SAVE_EDIT_SUCCEED</p>");
				printf("<p>%s</p>", content_output);
			}
			fp = fopen("../data/test.json", "w");
			fwrite(content_output, 1, strlen(content_output), fp);
			fclose(fp);
		}
		else
		{
			return 1;
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
		}
	}
	printf("</body></html>");
	return 0;

}



