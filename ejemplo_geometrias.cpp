#include <iostream>
#include <cmath>


int main()
{
	
	struct punto{
		float x;
		float y;
	};

	struct recta{
		float m;
		float n;
	};



/********** 1. RECTA FORMADA ENTRE DOS PUNTOS **********/
	punto A1, B1;
	recta r1;

	A1.x = 2.0;   A1.y = 1.0;
	B1.x = 10.0;   B1.y = 7.0;

	r1.m = (B1.y - A1.y) / (B1.x - A1.x);
	r1.n = A1.y - r1.m * A1.x;

	std::cout<<"Ejemplo 1\n y = ("<<r1.m<<") * x + ("<<r1.n<<")"<<std::endl<<std::endl;


/********** 2. INTERSECCIÓN DE DOS RECTAS **********/
	recta r2, t2;	
	
	r2.m = 3.0;   r2.n = -4.0;
	t2.m = -1.0;   t2.n = 2.0;

	punto interseccion;
	interseccion.x = (-1) * (t2.n - r2.n) / (t2.m - r2.m);
	interseccion.y = r2.m * interseccion.x + r2.n;

	std::cout<<"Ejemplo 2\n Intersección = ("<<interseccion.x<<", "<<interseccion.y<<")"<<std::endl<<std::endl;


/********** 3. DISTANCIA MÍNIMA DE UN PUNTO A UNA RECTA **********/
	punto A3;
	recta r3;

	A3.x = 5.0;   A3.y = 8.0;
	r3.m = 3.0;   r3.n = -4.0;

	float dist_minima_A3_r3 = std::fabs(r3.m * A3.x - A3.y + r3.n) / std::sqrt(std::pow(r3.m, 2.0) + 1.0);

	std::cout<<"Ejemplo 3\n Distancia mínima = "<<dist_minima_A3_r3<<std::endl<<std::endl;


/********** 4. PUNTO DE UNA RECTA MÁS CERCANO A OTRO PUNTO **********/
	// Dado el punto A4 y la recta r4, encontrar el punto de r4 más cercano a A4.
	// Este va a ser la intersección de la recta r4 con una recta perpendicular a ella que pase por A4

	punto A4;	
	recta r4, t4;

	A4.x = 7.0;   A4.y = 5.5;
	r4.m = 3.0;   r4.n = -4.0;

	// Recta perpendicular a r4
	t4.m = (-1) * (1 / r4.m); // Pendiente perpendicular a r4
	t4.n = A4.y - t4.m * A4.x;

	// Intersección
	punto punto_mas_cercano;
	punto_mas_cercano.x = (-1) * (t4.n - r4.n) / (t4.m - r4.m);
	punto_mas_cercano.y = t4.m * interseccion.x + t4.n;

	std::cout<<"Ejemplo 4\n Recta perpendicular: y = ("<<t4.m<<") * x + ("<<t4.n<<")"<<std::endl;
	std::cout<<" Punto de r4 más cercano a A4 = ("<<punto_mas_cercano.x<<", "<<punto_mas_cercano.y<<")"<<std::endl<<std::endl;


	return 0;
}
