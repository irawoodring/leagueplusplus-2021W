#ifndef			__HPP_UTILITY__
#define			__HPP_UTILITY__

#include <functional>

typedef std::function<void(double)> Callback;

class Vector2 {
	public:
		Vector2(double x=0.0, double y=0.0);
		double getX();
		double getY();
		void setX(double x);
		void setY(double y);
		
	protected:
		double x;
		double y;
};

class Vector3 : public Vector2 {
	public:
		Vector3(double x=0.0, double y=0.0, double z=0.0); 
		double getZ();
		void setZ(double z);
	protected:
		double z;
};

#endif
