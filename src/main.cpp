#include <iostream>
#include "TPoint.h"
#include "TVecteur3D.h"
#include <ostream>

constexpr  float PI = 3.14159265f;

int main()
{
	std::cout << "Debut du programme" << std::endl;

	auto* const point = new TPoint<int>(4, 2, 8);
	//auto* const point2 = new TPoint<int>(*point);
	//auto* const point3 = point2;

	////std::cout << "Coordonnees du point 3 : (" << point3->X() << "," << point3->Y() << "," << point3->Z() << ")" << std::endl;
	std::cout << *point << std::endl;
	//auto* const point4 = new TPoint<int>(4, 6, 1);
	//auto* vecteur = new TVecteur3D<int>(*point4, *point);
	//auto* const vecteur2 = vecteur;
	//std::cout << vecteur2 << std::endl;
	//std::cout << "Coordonnees du vecteur : [" << vecteur2->X() << "," << vecteur2->Y() << "," << vecteur2->Z() << "]" << std::endl;
	//auto* vecteur3 = new TVecteur3D<int>(4, 2, 7);
	//*vecteur3 += *vecteur;
	//std::cout << "Coordonnees du vecteur : [" << vecteur3->X() << "," << vecteur3->Y() << "," << vecteur3->Z() << "]" << std::endl;
	//auto* vecteur4 = new TVecteur3D<int>(0, 0, 0);
	//*vecteur4 = *vecteur + *vecteur3;
	//std::cout << "Coordonnees du vecteur : [" << vecteur4->X() << "," << vecteur4->Y() << "," << vecteur4->Z() << "]" << std::endl;
	//*vecteur4 = *vecteur3 - *vecteur;
	//std::cout << "Coordonnees du vecteur : [" << vecteur4->X() << "," << vecteur4->Y() << "," << vecteur4->Z() << "]" << std::endl;
	//*vecteur4 = *vecteur3 * *vecteur;
	//std::cout << "Coordonnees du vecteur : [" << vecteur4->X() << "," << vecteur4->Y() << "," << vecteur4->Z() << "]" << std::endl;
	//*vecteur4 = *vecteur3 / 5;
	//std::cout << "Coordonnees du vecteur : [" << vecteur4->X() << "," << vecteur4->Y() << "," << vecteur4->Z() << "]" << std::endl;
	//*vecteur4 = *vecteur3 * 5;
	//std::cout << "Coordonnees du vecteur : [" << vecteur4->X() << "," << vecteur4->Y() << "," << vecteur4->Z() << "]" << std::endl;
	//*vecteur4 = 5 * *vecteur3;
	//std::cout << "Coordonnees du vecteur : [" << vecteur4->X() << "," << vecteur4->Y() << "," << vecteur4->Z() << "]" << std::endl;
	//TVecteur3D<double> vecteur5 = vecteur4->Normalized();
	//std::cout << "Coordonnees du vecteur : [" << vecteur5.X() << "," << vecteur5.Y() << "," << vecteur5.Z() << "]" << std::endl;
	//*vecteur4 = vecteur3->Opposite();
	//std::cout << "Coordonnees du vecteur : [" << vecteur4->X() << "," << vecteur4->Y() << "," << vecteur4->Z() << "]" << std::endl;
	//auto t = new TVecteur3D<std::string>();
	//t->SetX("t");
	
	const auto point1 = new TPoint<float>(2.0f, 0.0f, 0.0f);
	const auto point2 = new TPoint<float>(0.0f, 0.0f, 0.0f);

	const auto vecteur = new TVecteur3D<float>(*point2, *point1);

	const float norm = vecteur->Magnitude();

	float x = cosf(90.f * (PI / 180.f)) * norm;
	float y = sinf(90.f * (PI / 180.f)) * norm;

	x *= 100;
	x = trunc(x);
	x /= 100;
	
	y *= 100;
	y = trunc(y);
	y /= 100;
	
	std::cout << norm << std::endl;
	std::cout << x << " , " << y << std::endl;
	
	return 0;
}
