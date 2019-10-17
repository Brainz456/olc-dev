#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "Boundary.h"
#include <vector>
#include "Ray.h"

class GEngine : public olc::PixelGameEngine{
public:
	GEngine(){
		sAppName = "GEngine";
	}

public:
	std::vector<Boundary> boundaries;
	std::vector<Ray> rays;

	bool OnUserCreate() override{
		// Called once at the start, so create things here
		boundaries = {
			Boundary(150,150,300,150) //Add extra "hard-coded" boundaries here 
			,Boundary(150,150,150,300)
			,Boundary(150,300,300,300)
			,Boundary(300,150,300,300)
		};
		rays = {
			Ray(256,200,27)
		};
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override{
		//FOR THE RECORD, CO-ORDINATES START FROM TOP LEFT
		// called once per frame
		for (int x = 0; x < ScreenWidth(); x++) {
			for (int y = 0; y < ScreenHeight(); y++) {
				Draw(x,y,olc::BLACK);
			}
		}

		for (int x = 0; x < boundaries.size();x++) {
			Boundary bound = boundaries[x];
			DrawBoundary(bound);
		}

		CheckRays();
		
		return true;
	}
	
	void DrawBoundary(Boundary B) {
		int x1 = B.getX1();
		int y1 = B.getY1();
		int x2 = B.getX2();
		int y2 = B.getY2();
		DrawLine(x1,y1,x2,y2,olc::WHITE);
	}

	void CheckRays() {
		for (int x = 0; x < rays.size(); x++) {
			for (int y = 0; y < boundaries.size(); y++) {
				std::tuple<int, int> intersectPoint = rays[x].intersect(boundaries[y]);
				if (std::get<0>(intersectPoint) > 0 && std::get<1>(intersectPoint) > 0) {
					DrawLine(rays[x].getX(), rays[x].getY(), std::get<0>(intersectPoint), std::get<1>(intersectPoint));
				}
			}
		}
	}
};



int main()
{
	GEngine demo;
	if (demo.Construct(512, 512, 1, 1)) {
		demo.Start();
	}
	return 0;
}