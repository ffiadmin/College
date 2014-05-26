#include "stubs.h"

using namespace glm;

double Test_RaySphereIntersect(const vec3& P0, const vec3& V0, const mat4& T) {
//Transform the ray to local space
	mat4 PTrans = inverse(T);
	mat4 VTrans = T;
	VTrans[0].w = 0;
	VTrans[1].w = 0;
	VTrans[2].w = 0;
	VTrans = inverse(VTrans);

	vec4 P1 = PTrans * vec4(P0, 1.0);
	vec4 V1 = VTrans * vec4(V0, 0.0);
	vec3 P = vec3(P1);
	vec3 V = vec3(V1);

//Generate infomation about the sphere
	float radius = 1.0f;
	vec3 translate(T[3].x, T[3].y, T[3].z);
	vec3 TwoV(2 * V.x, 2 * V.y, 2 * V.z);

//Find out the T value
	int a = 1;
	float b = dot(TwoV, P);
	float c = pow(length(P), 2) - pow(radius, 2);

	float t1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	float t2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);

//Which value should return?
	if (t1 < 0 && t2 < 0) { // 0 solutions
		return -1;
	} else if (t1 >= 0 && t2 < 0) { // 1 solution
		return t1;
	} else if (t1 < 0 && t2 >= 0) { // 1 solution
		return t2;
	} else { // 2 solutions
		return t1 < t2 ? t1 : t2;
	}	
}

double Test_RayPolyIntersect(const vec3& P0, const vec3& V0, const vec3& p1, const vec3& p2, const vec3& p3, const mat4& T) {
	// TODO fill this in.
	// See the documentation of this function in stubs.h.

	float epsilon = 0.001; //fine tune this value

	vec3 E = vec3((inverse(T) * vec4(P0,1))); //Transform the ray origin
	mat4 cMult = mat4(1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1); //Prepare to make C*
	vec3 D = vec3(inverse(matrixCompMult(T,cMult)) * vec4(V0,0)); //Transform the ray direction
	vec3 v1 = p3 - p1; //prep for Normal vector calc
	vec3 v2 = p3 - p2;
	vec3 N = cross(v1,v2); //calculate the normal vector
	vec3 P = E + D; //Calculate a point on the ray
	if (dot(N, P-E) == 0) //t would be undefined
		return -1;
	float t = dot(N, p1 - E)/dot(N, P - E); //Find the value for t
	if (t - epsilon < 0) //the ray is parallel to the plane
		return -1;
	vec3 R = E + t*(P - E);
	//set up matrices for area calculations
	mat3 S01 = mat3(p1.y, p1.z, 1, p2.y, p2.z, 1, p3.y, p3.z, 1);
	mat3 S02 = mat3(p1.z, p1.x, 1, p2.z, p2.x, 1, p3.z, p3.x, 1);
	mat3 S03 = mat3(p1.x, p1.y, 1, p2.x, p2.y, 1, p3.x, p3.y, 1);

	mat3 S11 = mat3(R.y, R.z, 1, p2.y, p2.z, 1, p3.y, p3.z, 1);
	mat3 S12 = mat3(R.z, R.x, 1, p2.z, p2.x, 1, p3.z, p3.x, 1);
	mat3 S13 = mat3(R.x, R.y, 1, p2.x, p2.y, 1, p3.x, p3.y, 1);

	mat3 S21 = mat3(R.y, R.z, 1, p3.y, p3.z, 1, p1.y, p1.z, 1);
	mat3 S22 = mat3(R.z, R.x, 1, p3.z, p3.x, 1, p1.z, p1.x, 1);
	mat3 S23 = mat3(R.x, R.y, 1, p3.x, p3.y, 1, p1.x, p1.y, 1);

	mat3 S31 = mat3(R.y, R.z, 1, p1.y, p1.z, 1, p2.y, p2.z, 1);
	mat3 S32 = mat3(R.z, R.x, 1, p1.z, p1.x, 1, p2.z, p2.x, 1);
	mat3 S33 = mat3(R.x, R.y, 1, p1.x, p1.y, 1, p2.x, p2.y, 1);

	//After matrices are set up calculate areas

	float S0 = sqrt(determinant(S01)*determinant(S01) + determinant(S02)*determinant(S02) + determinant(S03)*determinant(S03));
	float S1 = sqrt(determinant(S11)*determinant(S11) + determinant(S12)*determinant(S12) + determinant(S13)*determinant(S13))/S0;
	float S2 = sqrt(determinant(S21)*determinant(S21) + determinant(S22)*determinant(S22) + determinant(S23)*determinant(S23))/S0;
	float S3 = sqrt(determinant(S31)*determinant(S31) + determinant(S32)*determinant(S32) + determinant(S33)*determinant(S33))/S0;
	float testS = S1+S2+S3;

	if (testS <= 1 + epsilon && testS >= 1 - epsilon) //Include epsilon value since floating point numbers are not 100% accurate
		return t;
	else
		return -1;
}

double Test_RayCubeIntersect(const vec3& P0, const vec3& V0, const mat4& T) {
	// TODO fill this in.
	// See the documentation of this function in stubs.h.

	float Tnear = -FLT_MAX; //"Negative Infinity"
	float Tfar  = FLT_MAX; //"Infinity"
	float T1, T2;
	vec3 E = vec3(inverse(T) * vec4(P0,1)); //Transform the ray's origin
	mat4 cMult = mat4(1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1); //Prepare to transform the direction
	vec3 D = vec3(inverse(matrixCompMult(T,cMult))*vec4(V0,0)); //Transform the ray's direction
	//Slab Intersection for X slabs
	if (D.x == 0) {
		if (E.x < -0.5 || E.x > 0.5)
			return -1;
	}
	else {
		T1 = (-0.5f - E.x)/D.x;
		T2 = (0.5f - E.x)/D.x;
		if (Test_T1T2(T1, T2, Tnear, Tfar))
			return -1;
	}
	//Slab Intersection for Y slabs
	if (D.y == 0) {
		if (E.y < -0.5 || E.y > 0.5)
			return -1;
	}
	else {
		T1 = (-0.5f - E.y)/D.y;
		T2 = (0.5f - E.y)/D.y;
		if (Test_T1T2(T1, T2, Tnear, Tfar))
			return -1;
	}
	//Slab Intersection for Z slabs
	if (D.z == 0) {
		if (E.z < -0.5 || E.z > 0.5)
			return -1;
	}
	else {
		T1 = (-0.5f - E.z)/D.z;
		T2 = (0.5f - E.z)/D.z;
		if (Test_T1T2(T1, T2, Tnear, Tfar))
			return -1;
		return Tnear;
	}
}

bool Test_T1T2(float& T1, float&T2, float& Tnear, float& Tfar) {
	if (T1 > T2) {
		float temp = T1;
		T1 = T2;
		T2 = temp;
	}
	if (T1 > Tnear)
		Tnear = T1;
	if (T2 < Tfar)
		Tfar = T2;
	if (Tnear > Tfar)
		return true;
	if (Tfar < 0)
		return true;
	return false;
}