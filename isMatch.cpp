#include <iostream>
#include <cstring>

using namespace std;






bool recurMatch(const char *s, const char *p)
{
	int slen = strlen(s);
	int plen = strlen(p);
	if(slen == 0){
		if(plen == 0)
			return true;
		bool allstar = true;
		for(int i = 0; i <= plen - 1; i++){
			if(p[i] != '*'){
				allstar = false;
				break;
			}
		}
		return allstar;
	}else if(plen == 0){
		return false;
	}

	if(s[0] == p[0] || p[0] == '?'){
		return  recurMatch(s + 1, p + 1);
	}else if(p[0] == '*'){
		if(recurMatch(s + 1, p + 1) ||  recurMatch(s + 1, p) || recurMatch(s, p+1)){
			return true;
		}
	}else{
			return false;
	}

	return false;
}



bool isMatch1(const char *s, const char *p) {
	if(s == NULL || p == NULL){
		return false;
	}
	
	return recurMatch(s, p);
}

bool isMatch2(const char *s, const char *p) {
     const char* start = NULL;
    const char* ss = NULL;
   
    while(*s){
        if(*p=='?' || *p==*s){
            p++;
            s++;
        }else if(*p == '*'){
            start = p;
            ss = s;
            p++;
        }else{
            if(start){
                s = ss++;
                p = start + 1;
            }else
                return false;
        }
    }
   
    while(*p == '*')
        p++;
       
    return *p == '\0';
}


bool isMatch3(const char *s, const char *p) {
	
	const char* start = NULL;
	const char* ss = NULL;
	while(*s != '\0'){
		if(*s == *p || *p == '?'){
			s++;
			p++;
		}else if(*p == '*'){
			start = p;
			ss = s;
			p++;
		}else{
			if(start){
				s = ss++;
				p = start + 1;
			}else{
				return false;
			}
		}
	}

	while(*p == '*')p++;

	return *p == '\0';
}


//regex match
bool rematch(const char *s, const char* p){
	if(*s == 0 && *p == 0)
		return true;
	else if(*p == 0){
		return false;
	}
	
	if(*s == 0){
	    if(p[1] == '*')    
	        return rematch(s, p + 2);
		else
	        return false;
	}
	
//s not empty
	if(p[1] == '*'){
		if(p[0] == '.'){
			if(rematch(s + 1, p))
				return true;
		}else{
			if( *s == *p && rematch(s + 1, p))
					return true;
		}
		
		if(rematch(s, p + 2))
			return true;
	}
	
	if(p[0] == '.') {
		if(rematch(s + 1, p + 1))
			return true;
	}else{
		if(*s == *p && rematch(s + 1, p + 1))
				return true;
	}
	
	return false;
}

bool isMatch4(const char *s, const char *p) {
	return rematch(s, p);
}

//wildcard match
//overtime if using recursion

bool rem5(const char *s, const char *p){
	int len1 = strlen(s);
	int len2 = strlen(p);

	if(len1 == 0 && len2 == 0){
		return true;
	}

	if(len2 == 0)
		return false;

	if(p[0] == '?'){
		if(len1 > 0 && rem5(s + 1, p + 1))
				return true;

	}else if(p[0] == '*'){
		if(rem5(s, p + 1))
			return true;

		if(len1 > 0 && (rem5(s + 1, p + 1) || rem5(s + 1, p)))
			return true;
	}else {
		if(len1 > 0 && *s == *p && rem5(s + 1, p + 1))
			return true;
	}

	return false;
}

bool isMatch5(const char *s, const char *p) {
    return rem5(s, p);
}

//wildcard match, no recursion
bool isMatch6(const char *s, const char *p) {
	const char* start = NULL;
	const char* ss = NULL;

	while(*s){
		if(*p == '?' || *s == *p){
			s++;
			p++;
		}else if(*p == '*'){
			start = p;
			ss = s;
			p++;
		}else{
			if(start == NULL)
				return false;
			
			p = start + 1;
			s = ss++;
		}
	
	}

	while(*p == '*')
		p++;

	if(*p == 0)
		return true;
	else
		return false;
	
}


//10/12/2013 reg match



int mainisMatch4()
{

	isMatch5("aa", "a"); 
	system("pause");
	return 0;

}