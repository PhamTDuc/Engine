#include "Test.h"
#include <stdio.h>

namespace Engine {
	__declspec(dllimport) void hello()
	{
		printf("Welcome to game engine");
	}
}