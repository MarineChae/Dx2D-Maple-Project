#pragma once
#include"Mymath.h"

struct CUVRect
{
    CVector2 m_Min;
    CVector2 m_Max;

};

class CRect
{
public:
    bool m_bvalid = true;
    CVector2 m_pPosition;
    float m_Width = 0.0f;
    float m_height = 0.0f;
    CVector2 m_Point[4];
    CVector2 m_pCenter;
    CVector2 Size;
    CVector2 m_Max;
    CVector2 m_Min;
    CVector2 m_Half;
    float m_Angle;
public:
    CRect operator+(CRect& other);
    CRect operator - (CRect& other);
    CRect operator *(float value);
    CRect operator /(float value);
    bool operator == (CRect& other);
    bool operator !=(CRect& other);
    
public:
    bool ToRect(CRect& rect);
    bool ToRectFootHold(CRect& rect);
    void Set(CVector2 p, float width, float height);
    void SetRect(CVector2 p, float width, float height);
public:
    CRect();
    CRect(CVector2 p, float width, float height);
};



class CBox
{
public:
    bool m_bvalid = true;
    CVector3 m_pPosition;
    float m_Width = 0.0f;
    float m_height = 0.0f;
    float m_Depth = 0.0f;
    CVector3 m_Point[8];
    CVector3 m_pCenter;
    CVector3 Size;
    CVector3 m_Max;
    CVector3 m_Min;
    CVector3 m_Half;
public:
    CBox operator+(CBox& other);
    CBox operator - (CBox& other);
    CBox operator *(float value);
    CBox operator /(float value);
    bool operator == (CBox& other);
    bool operator !=(CBox& other);

public:
    bool ToBox(CBox& Box);
    void Set(CVector3 p, float width, float height, float depth);
public:
    CBox();
    CBox(CVector3 p, float width, float height, float depth);
};



class CUtiliy
{



};

