/*
	Copyright (C) 2008, kobake

	This software is provided 'as-is', without any express or implied
	warranty. In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

		1. The origin of this software must not be misrepresented;
		   you must not claim that you wrote the original software.
		   If you use this software in a product, an acknowledgment
		   in the product documentation would be appreciated but is
		   not required.

		2. Altered source versions must be plainly marked as such,
		   and must not be misrepresented as being the original software.

		3. This notice may not be removed or altered from any source
		   distribution.
*/
#ifndef SAKURA_CSTRICTRANGE_01CCFDA1_93B9_4053_BF1E_0CFE0E5F55A1_H_
#define SAKURA_CSTRICTRANGE_01CCFDA1_93B9_4053_BF1E_0CFE0E5F55A1_H_

template <class PointType>
class CRangeBase{
public:
	typedef typename PointType::IntType IntType;
public:
	//�R���X�g���N�^
	CRangeBase()
	{
	}
	CRangeBase(const CRangeBase& rhs)
	{
		operator=(rhs);
	}
	CRangeBase(const PointType& _ptFrom,const PointType& _ptTo)
	{
		m_ptFrom=_ptFrom;
		m_ptTo=_ptTo;
	}

	//���
	CRangeBase& operator = (const CRangeBase& rhs)
	{
		m_ptFrom=rhs.m_ptFrom;
		m_ptTo=rhs.m_ptTo;
		return *this;
	}

	//��r
	bool operator == (const CRangeBase& rhs) const
	{
		return m_ptFrom == rhs.m_ptFrom && m_ptTo == rhs.m_ptTo;
	}
	bool operator != (const CRangeBase& rhs) const
	{
		return !operator==(rhs);
	}

	//����
	//! 1���������I�����ĂȂ���ԂȂ�true
	bool IsOne() const
	{
		return m_ptFrom==m_ptTo;
	}
	bool IsLineOne() const
	{
		return m_ptFrom.y==m_ptTo.y;
	}
	bool IsValid() const //!�L���Ȕ͈͂Ȃ�true
	{
		return m_ptFrom.BothNatural() && m_ptTo.BothNatural();
	}

	//�擾
	PointType GetFrom() const
	{
		return m_ptFrom;
	}
	PointType GetTo() const
	{
		return m_ptTo;
	}

	//����
	PointType* GetFromPointer()
	{
		return &m_ptFrom;
	}
	PointType* GetToPointer()
	{
		return &m_ptTo;
	}


	//�ݒ�
	void Clear(int n)
	{
		m_ptFrom.Set(IntType(n),IntType(n));
		m_ptTo.Set(IntType(n),IntType(n));
	}
	void Set(const PointType& pt)
	{
		m_ptFrom=pt;
		m_ptTo  =pt;
	}
	void SetFrom(const PointType& pt)
	{
		m_ptFrom = pt;
	}
	void SetTo(const PointType& pt)
	{
		m_ptTo = pt;
	}

	void SetFromX(IntType nX)
	{
		m_ptFrom.x = nX;
	}
	/*
	void SetFromY(int nY)
	{
		m_ptFrom.y = nY;
	}
	*/
	void SetFromY(IntType nY)
	{
		m_ptFrom.y = nY;
	}
	
	void SetToX(IntType nX)
	{
		m_ptTo.x = nX;
	}
	/*
	void SetToY(int nY)
	{
		m_ptTo.y = nY;
	}
	*/
	void SetToY(IntType nY)
	{
		m_ptTo.y = nY;
	}

	//����ݒ�
	void SetLine(IntType nY)					{ m_ptFrom.y = nY;     m_ptTo.y = nY;   }
	void SetXs(IntType nXFrom, IntType nXTo)	{ m_ptFrom.x = nXFrom; m_ptTo.x = nXTo; }
private:
	PointType m_ptFrom;
	PointType m_ptTo;
};

#endif /* SAKURA_CSTRICTRANGE_01CCFDA1_93B9_4053_BF1E_0CFE0E5F55A1_H_ */
/*[EOF]*/