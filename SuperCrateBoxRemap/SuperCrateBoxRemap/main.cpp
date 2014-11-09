
#include <iostream>
#include <windows.h>

using namespace std;
/*
void SendKeys(char *myMessage)
{
	char myChar;
	while (myChar = *myMessage++)
	{
		short vKey = VkKeyScan(myChar);
		if ((vKey >> 8) & 1)
		{
			keybd_event((unsigned char)VK_SHIFT, 0, 0, 0);
		}
		keybd_event((unsigned char)vKey, 0, 0, 0);
		keybd_event((unsigned char)vKey, 0, KEYEVENTF_KEYUP, 0);
		if ((vKey >> 8) & 1)
		{
			keybd_event((unsigned char)VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
		}
	}
}
*/
void SendKeysEx(BYTE myCommand)
{
	keybd_event(myCommand, 0, 0, 0);
	keybd_event(myCommand, 0, KEYEVENTF_KEYUP, 0);
}


void KeyPressVK(short keyIn, unsigned char keyOut)
{
	if (GetAsyncKeyState(keyIn))
	{
		SendKeysEx(keyOut);
		Sleep(1);
	}
}

void KeyPress(short keyIn, short keyOut)
{
	if (GetAsyncKeyState(keyIn))
	{
		keybd_event((unsigned char)keyOut, 0, 0, 0);
		keybd_event((unsigned char)keyOut, 0, KEYEVENTF_KEYUP, 0);
		Sleep(1);
	}
}

class Key{
public:
	Key(short _keyIn, short _keyOut);
	void HandleEvents();
private:
	bool keyDown;
	short keyIn;
	short keyOut;
};

Key::Key(short _keyIn, short _keyOut)
{
	keyIn = _keyIn;
	keyOut = _keyOut;
	keyDown = false;
}

void Key::HandleEvents()
{
	if (GetAsyncKeyState(keyIn) && !keyDown)
	{
		keybd_event((unsigned char)keyOut, 0, 0, 0);
		keyDown = true;
	}
	if (!GetAsyncKeyState(keyIn) && keyDown)
	{
		keybd_event((unsigned char)keyOut, 0, KEYEVENTF_KEYUP, 0);
		keyDown = false;
	}
}

int main()
{

//	system("CLS");

	//Input Keys
	short wKey = VkKeyScan('w');
	short aKey = VkKeyScan('a');
	short sKey = VkKeyScan('s');
	short dKey = VkKeyScan('d');

	short jKey = VkKeyScan('j');
	short kKey = VkKeyScan('k');

	//------------Game Keys
	//fire
	short xKey = VkKeyScan('x');
	//jump
	short zKey = VkKeyScan('z');
	//---------------------

	Key left(aKey, VK_LEFT);
	Key right(dKey, VK_RIGHT);
	Key jump(wKey, VK_UP);
	Key jump2(kKey, VK_UP);
	Key jump3(VK_SPACE, VK_UP);
	Key down(sKey, VK_DOWN);
	Key shoot(jKey, xKey);

	while (1)
	{
		


		left.HandleEvents();
		right.HandleEvents();
		jump.HandleEvents();
		jump2.HandleEvents();
		jump3.HandleEvents();
		down.HandleEvents();
		shoot.HandleEvents();


		/*
		if (GetAsyncKeyState(VK_LEFT))
		{
//			short vKey = 1;
//			char myChar = a;
			short vKey = VkKeyScan('a');
			keybd_event((unsigned char)vKey, 0, 0, 0);
			keybd_event((unsigned char)vKey, 0, KEYEVENTF_KEYUP, 0);

//			SendKeys("rip");
//			SendKeysEx(VK_RETURN);
			Sleep(1);
		}
		*/




		/*
		KeyPressVK(wKey, VK_UP);
		KeyPressVK(aKey, VK_LEFT);
		KeyPressVK(dKey, VK_RIGHT);

		KeyPress(jKey, xKey);
		KeyPress(kKey, zKey);
		*/




		/*
		if (GetAsyncKeyState(aKey))
		{
			SendKeysEx(VK_LEFT);
			Sleep(1);
		}
		*/
	}

	return 0;
}
