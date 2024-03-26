#pragma once
#include "CUtiliy.h"

// 충돌타입체크
enum class CollisionType
{
    _OUTSIDE = 0,
    _INSIDE = 1,
    _SPANNING = 2

};


class CCollision
{
public:
    //점과 영역충돌
    static bool PointToRect(CRect& rt, CVector2 p)
    {
        if (rt.m_Min.x <= p.x && rt.m_Max.x >= p.x
            &&
            rt.m_Min.y <= p.y && rt.m_Max.y >= p.y)
            return true;

        return false;



    }
    //영역과 영역의 충돌
    static bool RectToRect(CRect& rt1, CRect& rt2)
    {
        CRect rt = rt1 + rt2;

        if (rt1.m_Width + rt2.m_Width >= rt.m_Width)
        {
            if (rt1.m_height + rt2.m_height >= rt.m_height)
            {
                return true;
            }
        }





        return false;



    }
    //박스와 박스의충돌
    static CollisionType BoxToBox(CBox& Box1, CBox& Box2)
    {
        //기본은 충돌하지 않음으로 설정
        CollisionType ret = CollisionType::_OUTSIDE;
        //박스에 포함되어있는지 확인
        if (BoxInBox(Box1, Box2))
        {   
            ret = CollisionType::_INSIDE;
            return ret;

        }

        CVector3 Direction = Box1.m_pCenter - Box2.m_pCenter;
       
        //박스끼리 거리를 구한 후 현재 직교좌표계를 사용했기 때문에
        //절댓값을 사용해서 비교해줌 절댓값을 빼면 결과가 이상해짐
        if (fabs(Direction.x) <= (Box1.m_Half.x + Box2.m_Half.x))
        {
            if (fabs(Direction.y) <= (Box1.m_Half.y + Box2.m_Half.y))
            {
                if (fabs(Direction.z) <= (Box1.m_Half.z + Box2.m_Half.z))
                {
                    ret = CollisionType::_SPANNING;
                    return ret;
                }
            }
        }




        return ret;


    }
    /*static bool BoxToBox(CBox& Box1 ,CBox& Box2)
    {
        CBox box = Box1 + Box2;

        float fw= Box1.m_Width + Box2.m_Width;
        float fh= Box1.m_height + Box2.m_height;
        float fd= Box1.m_Depth + Box2.m_Depth;

        if (fw >= box.m_Width)
        {
            if (fh >= box.m_height)
            {
                if (fd >= box.m_Depth)
                {
                    return true;
                }
            }
        }



        return false;


    }*/
    
    //박스에 포함되어있는지 확인
    //오브젝트가 트리의 노드에 포함되는지 확인하는 작업
    static bool BoxInBox(CBox& Box1, CBox& Box2)
    {
        //1번 박스의 최소값보다 2번의 최소값이 크고 1번의 최대보다 2번의 최대값이 작으면
        //1번 박스에 2번박스가 포함되어있다
        if (Box1.m_Min.x <= Box2.m_Min.x && Box1.m_Max.x >= Box2.m_Max.x)
        {
            if (Box1.m_Min.y <= Box2.m_Min.y && Box1.m_Max.y >= Box2.m_Max.y)
            {
                if (Box1.m_Min.z <= Box2.m_Min.z && Box1.m_Max.z >= Box2.m_Max.z)
                {
                    return true;
                }
            }

        }


        return false;


    }


};

