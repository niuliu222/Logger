#include <iostream>
#include "../Logger.h"

int main() {
	LLD::Log::LogInit();
	LLD::Log::LogMessage("test log mesage", __FILE__, __LINE__);
	LLD::Log::LogWarning("test log Warning", __FILE__, __LINE__);
	LLD::Log::LogError("test log Error", __FILE__, __LINE__);
	std::get();
	return 0;
}