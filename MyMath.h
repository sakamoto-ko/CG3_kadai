#pragma once
#define _USE_MATH_DEFIENS
#include <math.h>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4x4.h"

#define kWindowWidth 1280
#define kWindowHeight 720

#define PAI 3.14f

//static const int kRowHeight = 20;
//static const int kColumnWidth = 60;

struct VertexData {
	Vector4 position;
	Vector2 texcoord;
	Vector3 normal;
};

struct MaterialData {
	std::string textureFilePath;
};

struct ModelData {
	std::vector<VertexData> vertices;
	MaterialData material;
};

struct TransformationMatrix
{
	Matrix4x4 WVP;
	Matrix4x4 World;
};

struct Transform {
	Vector3 scale;
	Vector3 rotate;
	Vector3 translate;
};

struct Sphere {
	Vector3 center;//!<中心点
	float radius;//!<半径
};

struct Triangle {
	Vector3 vertices[3];//頂点
};

//線の始点と終点
struct StartEnd {
	Vector3 start;//始点
	Vector3 end;//終点
};

//直線(-∞~∞)
struct Line {
	Vector3 origin;//始点
	Vector3 diff;//終点への差分ベクトル
};

//半直線(0~∞)
struct Ray {
	Vector3 origin;//始点
	Vector3 diff;//終点への差分ベクトル
};

//線分(0~1)
struct Segment {
	Vector3 origin;//始点
	Vector3 diff;//終点への差分ベクトル
};

struct Plane {
	Vector3 normal;//法線
	float distance;//距離
};

struct AABB {
	Vector3 min;//最小点
	Vector3 max;//最大点
};

struct Spring {
	//アンカー。固定された端の位置
	Vector3 anchor;
	float naturalLength;//自然長
	float stiffness;//合成。ばね定数k
	float damplingCoefficient;//減衰係数
};

struct Ball {
	Vector3 positon;//ボールの位置
	Vector3 velocity;//ボールの速度
	Vector3 acceleration;//ボールの加速度
	float mass;//ボールの質量
	float radius;//ボールの半径
	unsigned int color;//ボールの色
};

struct Pendulum {
	Vector3 anchor; //アンカーポイント。固定された橋の位置
	float length;//紐の長さ
	float angle;//現在の角度
	float angulerVelocity;//角速度ω
	float angluerAcceleration;//角加速度
};

struct ConicalPendulum {
	Vector3 anchor; //アンカーポイント。固定された橋の位置
	float length;//紐の長さ
	float halfApexAngle;//延髄の頂角の半分	
	float angle;//現在の角度
	float angulerVelocity;//角速度ω
};

struct Capsule {
	Segment segment;
	float radius;
};

// 加算
Vector3 Add(const Vector3& v1, const Vector3& v2);
// 減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2);
// スカラー倍
Vector3 Multiply(const float scalar, const Vector3& v);
// 内積
float Dot(const Vector3& v1, const Vector3& v2);
// 長さ
float Length(const Vector3& v);
// 正規化
Vector3 Normalize(const Vector3& v);

// 加算
Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);
// 減算
Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2);
// 積
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

//単位行列
Matrix4x4 MakeIdenttity4x4();

// 平行移動行列
Matrix4x4 MakeTranslateMatrix(const Vector3& translate);

// X軸回転
Matrix4x4 MakeRotateXMatrix(float radian);
// Y軸回転
Matrix4x4 MakeRotateYMatrix(float radian);
// Z軸回転
Matrix4x4 MakeRotateZMatrix(float radian);
// 回転行列
Matrix4x4 MakeRotateMatrix(const Vector3& radian);

// 拡大縮小行列
Matrix4x4 MakeScaleMatrix(const Vector3& scale);

//アフィン変換行列
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate);

//ベクトル変換
Vector3 TransformNormal(const Vector3& v, const Matrix4x4& m);

//逆行列
Matrix4x4 Inverse(const Matrix4x4& m);

//透視投影行列
Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);

//正射影行列
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);

//ベクトルと行列の積
Vector3 Multiply(Vector3 v, Matrix4x4 m);
// ベクトルと行列の加算
//Vector3 Add(Vector3 v, Matrix4x4 m);
//ビューポート変換行列
Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);

int GetColor(unsigned int red, unsigned int  green, unsigned int  blue, int  alpha);

float Cot(float a);

void DrawSphere();