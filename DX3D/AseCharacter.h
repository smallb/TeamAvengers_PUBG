#pragma once
#include "IDisplayObject.h"
#include "IUnitObject.h"

class AseObject;

class AseCharacter : public IUnitObject
{
private:
	ASE_SCENE m_aseScene;	//tick�� ����
	AseObject * m_pCurrObj;
	AseObject * m_pStandObj;	//�Ͼ�ִ� ��� ����
	AseObject * m_pRunObj;		//�ٴ� ��� ����

public:
	AseCharacter();
	~AseCharacter();

	// IDisplayObject��(��) ���� ��ӵ�
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;

	void Load(OUT AseObject* &rootObj, const char* fullPath);
	void SetCurrentObject(AseObject* pObj) { m_pCurrObj = pObj; }
};
