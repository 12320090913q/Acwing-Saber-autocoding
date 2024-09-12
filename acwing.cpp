#include <windows.h>
#include <bits/stdc++.h>

using namespace std;
// VK_SHIFT
// VK_OEM_COMMA ,

void press(int vk) {
	keybd_event(vk, 0, 0, 0);
	keybd_event(vk, 0, KEYEVENTF_KEYUP, 0);
}

void shift(int vk) {
	keybd_event(VK_SHIFT, 0, 0, 0);
	keybd_event(vk, 0, 0, 0);
	keybd_event(vk, 0, KEYEVENTF_KEYUP, 0);           
	{
	}
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
}

int main() {
	freopen("a.txt", "r", stdin);
	Sleep(3000);
	
	string s;
	while (getline(cin, s)) {
		int now = 0;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] != ' ') {
				now = i;
				break;
			}
		}
		for (int i = now; i < s.size(); i++) {
			char c=s[i];
			if ('a' <= c && c <= 'z') press(c - 'a' + 0x41);
			else if ('A' <= c && c <= 'Z') shift(c - 'A' + 0x41); 
			else if ('0' <= c && c <= '9') press(0x60 + c - '0'); 
			else {
				switch(c) {
					case '=' : press(VK_OEM_PLUS); break;
					case '+' : shift(VK_OEM_PLUS); break;
					case '-' : press(VK_OEM_MINUS); break;
					case '_' : shift(VK_OEM_MINUS); break;
					case '.' : press(VK_OEM_PERIOD); break;
					case ' ' : press(VK_SPACE); break;
	//				case '\t': press(VK_TAB); break;
					case '!' : shift('1'); break;
					case '@' : shift('2'); break;
					case '#' : shift('3'); break;
					case '$' : shift('4'); break;
					case '%' : shift('5'); break;
					case '^' : shift('6'); break;
					case '&' : shift('7'); break;
					case '*' : shift('8'); break;
					case '(' : shift('9'); break;
					case ')' : shift('0'); break;
					case ';' : press(VK_OEM_1); break;
					case ':' : shift(VK_OEM_1); break;
					case '/' : press(VK_OEM_2); break;
					case '?' : shift(VK_OEM_2); break;
					case '`' : press(VK_OEM_3); break;
					case '~' : shift(VK_OEM_3); break;
					case '[' : press(VK_OEM_4); break;
					case '{' : shift(VK_OEM_4); break;
					case '\\' : press(VK_OEM_5); break;
					case '|' : shift(VK_OEM_5); break;
					case ']' : press(VK_OEM_6); break;
					case '}' : press(VK_DOWN); break;
					case '\'' : press(VK_OEM_7); break;
					case '\"' : shift(VK_OEM_7); break;
					case '<' : shift(VK_OEM_COMMA); break;
					case '>' : shift(VK_OEM_PERIOD); break;
					case ',' : press(VK_OEM_COMMA); break;
					case '\n' : press(VK_RETURN); break;
				}
			}
			Sleep(rand() % 80);
		}
		press(VK_RETURN);
		Sleep(rand() % 80);
	}
	return 0;
}
