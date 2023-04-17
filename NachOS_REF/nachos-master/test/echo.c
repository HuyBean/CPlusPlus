/* echo program */

#include "syscall.h"
#include "copyright.h"

int main(int argc, char* argv[])
{
	char mess[255];
	unsigned int i ;
	OpenFileID inConsole = OpenFileFunc("stdin", 2);
	OpenFileID outConsole = OpenFileFunc("stdout", 3);
	if (inConsole == -1 || outConsole == -1)
	{
		PrintString("Can not open console\n");
		return 0;
	}
	ReadFile(mess, 255, inConsole); 
	
	
	WriteFile(mess, 255, outConsole);
	CloseFile(inConsole);
	CloseFile(outConsole);
	return 0;
}
