#pragma once
#include "CUtiliy.h"

// �浹Ÿ��üũ
enum class CollisionType
{
    _OUTSIDE = 0,
    _INSIDE = 1,
    _SPANNING = 2

};


class CCollision
{
public:
    //���� �����浹
    static bool PointToRect(CRect& rt, CVector2 p)
    {
        if (rt.m_Min.x <= p.x && rt.m_Max.x >= p.x
            &&
            rt.m_Min.y <= p.y && rt.m_Max.y >= p.y)
            return true;

        return false;



    }
    //������ ������ �浹
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
    //�ڽ��� �ڽ����浹
    static CollisionType BoxToBox(CBox& Box1, CBox& Box2)
    {
        //�⺻�� �浹���� �������� ����
        CollisionType ret = CollisionType::_OUTSIDE;
        //�ڽ��� ���ԵǾ��ִ��� Ȯ��
        if (BoxInBox(Box1, Box2))
        {   
            ret = CollisionType::_INSIDE;
            return ret;

        }

        CVector3 Direction = Box1.m_pCenter - Box2.m_pCenter;
       
        //�ڽ����� �Ÿ��� ���� �� ���� ������ǥ�踦 ����߱� ������
        //������ ����ؼ� ������ ������ ���� ����� �̻�����
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
    
    //�ڽ��� ���ԵǾ��ִ��� Ȯ��
    //������Ʈ�� Ʈ���� ��忡 ���ԵǴ��� Ȯ���ϴ� �۾�
    static bool BoxInBox(CBox& Box1, CBox& Box2)
    {
        //1�� �ڽ��� �ּҰ����� 2���� �ּҰ��� ũ�� 1���� �ִ뺸�� 2���� �ִ밪�� ������
        //1�� �ڽ��� 2���ڽ��� ���ԵǾ��ִ�
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

