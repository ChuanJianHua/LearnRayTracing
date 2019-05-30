#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	auto nx = 200;
	auto ny = 100;
	const char *fileName = "ppm.ppm";
	ofstream outFile;
	outFile.open(fileName);
	outFile << "P3\n" << nx << " " << ny << "\n255\n";
	for (int j = ny-1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			float r = static_cast<float>(i) / static_cast<float>(nx);
			float g = static_cast<float>(j) / static_cast<float>(ny);
			float b = 0.2f;
			int ir = int(255.99*r);
			int ig = int(255.99*g);
			int ib = int(255.99*b);
			outFile << ir << " " << ig << " " << ib << "\n";
		}
	}
	outFile.close();
return 0;
}

