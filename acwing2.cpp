#include <windows.h>
#include <iostream>
#include <string>
#include "ACwing.h"
//#include "Dazitong.h"
#ifdef Dazitong 
	std::string _t="ASDFJKL;GHQWERTYUIOPZXCVBNM,./[]\'";
#endif
inline void press(int vk) {
	keybd_event(vk, 0, 0, 0);
	keybd_event(vk, 0, KEYEVENTF_KEYUP, 0);
}
inline void shift(int vk) {
	keybd_event(VK_SHIFT, 0, 0, 0);
	keybd_event(vk, 0, 0, 0);
	keybd_event(vk, 0, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
}
int main() {
	freopen("a.txt", "r", stdin);
	Sleep(2000);
	std::string s;
	while (std::getline(std::cin,s)) {
		int now=0;
		#ifdef ACwing
			for(int i=0;i<s.size();++i){
				if(s[i]!=' '){
					now=i;
					break;
				}
			}
		#endif
		#ifdef Dazitong
		int lst=0;
		#endif
		for(int i=now;i<s.size();++i){
			#ifdef ACwing
			if(i<s.size()-1&&s[i]==s[i+1]&&s[i+1]=='/')
				break;
			#endif
			char c=s[i];
			#ifdef Dazitong
				if((rand()&4))
					lst=rand()%_t.size();
				c=_t[lst];
			#endif
			if ('a' <= c && c <= 'z') press(c - 'a' + 0x41);
			else if ('A' <= c && c <= 'Z') shift(c - 'A' + 0x41); 
			else if ('0' <= c && c <= '9') press(0x60 + c - '0'); 
			else if(c=='=') press(VK_OEM_PLUS);
			else if(c=='+') shift(VK_OEM_PLUS);
			else if(c=='-') press(VK_OEM_MINUS);
			else if(c=='_') shift(VK_OEM_MINUS);
			else if(c=='.') press(VK_OEM_PERIOD);
			else if(c==' ') press(VK_SPACE);
			else if(c=='!') shift('1');
			else if(c=='@') shift('2');
			else if(c=='#') shift('3');
			else if(c=='$') shift('4');
			else if(c=='%') shift('5');
			else if(c=='^') shift('6');
			else if(c=='&') shift('7');
			else if(c=='*') shift('8');
			else if(c=='(') shift('9');
			else if(c==')') shift('0');
			else if(c==';') press(VK_OEM_1);
			else if(c==':') shift(VK_OEM_1);
			else if(c=='/') press(VK_OEM_2);
			else if(c=='?') shift(VK_OEM_2);
			else if(c=='`') press(VK_OEM_3);
			else if(c=='~') shift(VK_OEM_3);
			else if(c=='[') press(VK_OEM_4);
			else if(c=='{'){
				shift(VK_OEM_4);
				#ifdef ACwing 
					break;
				#endif
			} 
			else if(c=='\\') press(VK_OEM_5);
			else if(c=='|') shift(VK_OEM_5);
			else if(c==']') press(VK_OEM_6);
			else if(c=='}'){
				#ifdef ACwing
					press(VK_DOWN);
				#else
					shift(VK_OEM_6);
				#endif
			} 
			else if(c=='\'') press(VK_OEM_7);
			else if(c=='\"') shift(VK_OEM_7);
			else if(c=='<') shift(VK_OEM_COMMA);
			else if(c=='>') shift(VK_OEM_PERIOD);
			else if(c==',') press(VK_OEM_COMMA);
			else if(c=='\n') press(VK_RETURN);
			#ifndef ACwing
				if(c=='\t') press(VK_TAB);
			#endif
			Sleep(rand()%100);
		}
		press(VK_RETURN);
		Sleep(rand()%300);
	}
	return 0;
}
