/*
 * cJSON_User.c
 *
 *  Created on: 2019-10-22
 *      Author: siasunhebo
 */

#include<stdio.h>
#include<stdlib.h>
#include"cJSON.h"
#include<cJSON_User.h>

extern char *De_Serialize_Data;
extern char *Serialize_Data_Out;
int De_Serialize_flag;

 void Serialize()//序列化函数  将对象转化为字符串
 {
		cJSON *json;
		double Data_1=100.13133;

		json = cJSON_CreateArray();
		cJSON_AddItemToArray(json,cJSON_CreateString("Hello world"));
		cJSON_AddItemToArray(json,cJSON_CreateNumber(Data_1));

	 			Serialize_Data_Out=cJSON_Print(json);//将json转化位普通的字符串
	 			if(Serialize_Data_Out)
	 			{
		 			//printf("%s\n",Serialize_Data_Out);
		 			//free(Serialize_Data_Out);
	 			}
	 			if(json)
	 			{
	 				cJSON_Delete(json);
	 			}
 }

 void De_Serialize()//反序列化函数   将字符串转化为对象
 {
		cJSON *tmp;
		cJSON *De_Serialize_Json;

		if (De_Serialize_flag==1)
		{
				   De_Serialize_flag=0;
				   tmp=cJSON_Parse(De_Serialize_Data);
					De_Serialize_Json=cJSON_GetArrayItem(tmp,1);//(tmp,0)表示tmp的数组0,表示tmp的数组1
					printf("De_Serialize_Json type is=%d\n",De_Serialize_Json->type);
					//printf("valuestring is=%s\n",De_Serialize_Json->valuestring);
					printf("valuedouble is=%f\n",De_Serialize_Json->valuedouble);
				   if(tmp);
				cJSON_Delete(tmp);
		}
 }







