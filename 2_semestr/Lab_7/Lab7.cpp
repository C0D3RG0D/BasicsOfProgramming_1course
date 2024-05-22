#include "Class_lab7.hpp"


int main()
{
	float buf[100];
	uint32_t n;
	DataReader* Reader = Factory("input.binf");
	if (Reader == nullptr)
		return -1;
	//Reader->Write();
	Reader->Open();
	Reader->Read();
	Reader->GetData((uint8_t*)buf, n);
	for (int i = 0; i < n; i++)
		std::cout << buf[i] << " ";
	std::cout << std::endl;
	delete Reader;
	return 0;
}