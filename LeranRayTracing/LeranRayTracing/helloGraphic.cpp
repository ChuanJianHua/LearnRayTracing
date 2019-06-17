#include <iostream>
#include <fstream>
#include <string>
#include "vec3.h"
#include "ray.h"
using namespace std;

vec3 color(const ray& r)
{
	vec3 unit_direction = unit_vector(r.direction());
	auto t = 0.5*(unit_direction.y() + 1.0);
	return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}


int main()
{
	auto nx = 200;
	auto ny = 100;
	const char *fileName = "ppm.ppm";
	ofstream outFile;
	outFile.open(fileName);
	outFile << "P3\n" << nx << " " << ny << "\n255\n";

	vec3 lower_left_corner(-2.0, -1.0, -1.0);

	vec3 horizontal(4.0, 2.0, 0.0);
	vec3 vertical(0.0, 2.0, 0.0);
	vec3 origin(0.0, 0.0, 0.0);
	for (int j = ny-1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			float u = static_cast<float>(i) / static_cast<float>(nx);
			float v = static_cast<float>(j) / static_cast<float>(ny);

			ray r(origin, lower_left_corner + u * horizontal + v * vertical);
			vec3 col = color(r);

			float b = 0.2f;
			int ir = int(255.99*col[0]);
			int ig = int(255.99*col[1]);
			int ib = int(255.99*col[2]);
			outFile << ir << " " << ig << " " << ib << "\n";
		}
	}
	outFile.close();
return 0;
}

