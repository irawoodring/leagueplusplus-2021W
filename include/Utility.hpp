#ifndef			__HPP_UTILITY__
#define			__HPP_UTILITY__

#include <functional>

typedef std::function<void(double)> Callback;

class Vector2 {
	public:
		Vector2(double x=0.0, double y=0.0);
		double getX();
		double getY();
		
	private:
		double x;
		double y;
};

class Vector3 : public Vector2 {
	public:
		Vector3(double x=0.0, double y=0.0, double z=0.0); 
		double getZ();
	private:
		double z;
};

#endif
