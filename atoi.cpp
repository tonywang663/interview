#include <iostream>
#include <cstring>

using namespace std;

// const  int INT_MAX = 65535;

int atoim(const char *str) {
	if(str == NULL)
	{
		return 0;
	}

	int len = strlen(str);

	int res = 0;

	bool isbeg = true;
	bool isneg = false;
	for(int i = 0; i < len; i++)
	{
		if(str[i] ==' ')
		{
			continue;
		}
		if(str[i]>='0' && str[i] <= '9')
		{
			int t = (int)(str[i] - '0');
			res = res * 10 + t;
			if(isbeg == true)
			{
				isbeg == false;
			}
		}else if(isbeg == true && (str[i] =='+' || str[i] == '-'))
		{
			if(str[i] == '-')
			{
				isneg = true;
			}
		}else
		{
			return 0;
		}

	}
	
	if(isneg == false)
	{
		return res;
	}else
	{
		return -res;
	}
    
}

int atoi1(const char *str) {
	
	int res = 0;
	bool numend = false;
	bool neg = false;
	

	int state = 0;
	while(*str){
		
		if(numend)
			break;

		switch(state){
			case 0:
				if(*str == '-'){
					neg = true;
					state = 1;
				}else if(isdigit(*str)){
					int t = *str - '0';
					res = res * 10 + t;
					state = 2;
				}else if(*str == ' '){
					state = 0;
				}else if(*str == '+'){
					state = 1;
				}else{
					return 0;
				}
				break;

			case 1: 
				if(isdigit(*str)){
					state = 2;
					int t = *str - '0';
					res = res * 10 + t;
				}else{
					return 0;
				}
				break;

			case 2:
				if(isdigit(*str)){
					int t = *str - '0';
					
					if(!neg && ((res == INT_MAX / 10 && t >= INT_MAX % 10 ) || res > INT_MAX / 10)){
						return INT_MAX;
					}

					if(neg && ((res == INT_MAX / 10 && t >= INT_MAX % 10 + 1) || res > INT_MAX / 10)){
						return INT_MIN;
					}


					res = res * 10 + t;
					state = 2;
				}else{
					numend = true;
				}
				break;

			
		}
				str++;

	}

	if(neg)
		res = -res;

	return res;
    
}

int mainatoi1()
{

	return 0;
	system("pause");
}