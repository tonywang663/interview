#include <iostream>
#include <cstring>

using namespace std;

bool isNumber(const char *s) {
    int mat[11][7] = {0 ,0 ,0 ,0 ,0 ,0 ,0, // false
                      0 ,2 ,3 ,0 ,1 ,4 ,0, // 1
                      0 ,2 ,5 ,6 ,9 ,0 ,10,// 2
                      0 ,5 ,0 ,0 ,0 ,0 ,0, // 3
                      0 ,2 ,3 ,0 ,0 ,0 ,0, // 4
                      0 ,5 ,0 ,6 ,9 ,0 ,10,// 5
                      0 ,7 ,0 ,0 ,0 ,8 ,0, // 6
                      0 ,7 ,0 ,0 ,9 ,0 ,10,// 7
                      0 ,7 ,0 ,0 ,0 ,0 ,0, // 8
                      0 ,0 ,0 ,0 ,9 ,0 ,10,// 9
                      10,10,10,10,10,10,10 // 10
                    };
    int i = 0;
    int stat = 1;
    while(s[i] != 0) {
        int type = 0;
        if(s[i] >= '0' && s[i] <= '9')
            type = 1;
        else if(s[i] == '.')
            type = 2;
        else if(s[i] == 'e')
            type = 3;
        else if(s[i] == ' ')
            type = 4;
        else if(s[i] == '+' || s[i] == '-')
            type = 5;
        if(stat == 0)
            return false;
        stat = mat[stat][type];
        i++;
    }
    stat = mat[stat][6];
    if(stat == 10)
        return true;
    else
        return false;
}

bool isNumber1(const char *s) {
	int state = 0;

	while(*s){
		switch(state){
			case 0:
				if(isdigit(*s))
					state = 2;
				else if(*s == '+' || *s == '-')
					state = 1;
				else if(*s == ' ')
					state = 0;
				else if(*s =='.')
					state = 11;
				else 
					return false;
				break;
			
			case 1:
				if(isdigit(*s))
					state = 2;
				else if(*s == '.')
					state = 11;
				else 
					return false;
				break;

			case 11:
				if(isdigit(*s))
					state = 6;
				else
					return false;
				break;

			case 2: 
				if(isdigit(*s))
					state = 2;
				else if(*s == 'e')
					state = 3;
				else if(*s == '.')
					state = 4;
				else if(*s ==' ')
					state = 7;
				else
					return false;
				break;

			case 3:
				if(isdigit(*s))
					state = 5;
				else if(*s == '+' || *s == '-')
					state = 31;
				else
					return false;
				break;

			case 31:
				if(isdigit(*s))
					state = 5;
				else
					return false;
				break;


			case 4:
				if(isdigit(*s))
					state = 6;
				else if(*s == ' ')
					state = 7;
				else if(*s == 'e')
					state = 3;
				else
					return false;
				break;

			case 5:
				if(isdigit(*s))
					state = 5;
				else if(*s == ' ')
					state = 7;
				else
					return false;
				break;

			case 6:
				if(isdigit(*s))
					state = 6;
				else if(*s == 'e')
					state = 3;
				else if(*s == ' ')
					state = 7;
				else
					return false;
				break;
				
			case 7:
				if(*s == ' ')
					state = 7;
				else
					return false;
				break;
		}
		s++;
	}
	if(state == 5 || state == 6 || state == 2 || state == 7|| state == 4)
		return true;
	return false;

}

bool isNumber2(const char *s) {
	
	int len = strlen(s);
	if(len <= 0)
		return false;

	int state  = 0;
	while(*s){
		switch(state){
			case 0:
				if(*s == ' ')
					state = 0;
				else if(*s == '+' || *s == '-')
					state = 1;
				else if(*s >= '0' && *s <= '9')
					state = 2;
				else if(*s == '.')
					state = 8;
				else
					return false;
				break;

			case 1:
				if(*s >= '0' && *s <= '9')
					state = 2;
				else if(*s == '.')
					state = 8;
				else
					return false;
				break;

			case 2:
				if(*s >= '0' && *s <= '9')
					state = 2;
				else if(*s == '.')
					state = 3;
				else if(*s == 'e')
					state = 4;
				else if(*s == ' ')
					state = 5;
				else
					return false;
				break;

			case 3:
				if(*s >= '0' && *s <= '9')
					state = 6;
				else if(*s == ' ')
					state = 5;
				else if(*s == 'e')
					state = 4;
				else
					return false;
				break;

			case 4:
				if(*s >= '0' && *s <= '9')
					state = 7;
				else if(*s == '+' || *s == '-')
					state = 9;
				else
					return false;
				break;

			case 5:
				if(*s == ' ')
					state = 5;
				else
					return false;
				break;

			case 6:
				if(*s >= '0' && *s <= '9')
					state = 6;
				else if(*s == 'e')
					state = 4;
				else if(*s == ' ')
					state = 5;
				else 
					return false;
				break;

			case 7:
				if(*s >= '0' && *s <= '9')
					state = 7;
				else if(*s == ' ')
					state = 5;
				else 
					return false;
				break;

			case 8:
				if(*s >= '0' && *s <= '9')
					state = 6;
				else
					return false;
				break;

			case 9:
				if(*s >= '0' && *s <= '9')
					state = 7;
				else 
					return false;
				break;
		}
		s++;

	}

	if(state == 2 || state == 3 || state == 5 || state == 6 || state == 7)
		return true;
    
}

void mainisNumber1(){
	char *s = ".1.";
	
	isNumber1(s);
	
}