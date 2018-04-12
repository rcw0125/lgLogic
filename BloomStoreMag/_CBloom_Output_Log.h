// �߼���CBloom_Output_Logͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "MaterialOutputLog.h"

class CBloom_Output_Log :
	public MaterialOutputLog
{
public:
	CBloom_Output_Log(void);
	virtual ~CBloom_Output_Log(void);

	DECLARE_L3CLASS(CBloom_Output_Log,XGMESLogic\\BloomStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBloom_Output_Log)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBloom_Output_Log" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	///2009-02-23���������ֶ�
	/// <Property class="CBloom_Output_Log" name="Length" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(Length)

	/// <Property class="CBloom_Output_Log" name="Width" type="L3LONG">
	/// ���
	/// </Property>
	DECLARE_L3PROP_LONG(Width)

	/// <Property class="CBloom_Output_Log" name="Thickness" type="L3LONG">
	/// ���
	/// </Property>
	DECLARE_L3PROP_LONG(Thickness)

	/// <Property class="CBloom_Output_Log" name="Cal_Weight" type="L3DOUBLE">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cal_Weight)

	/// <Property class="CBloom_Output_Log" name="Right_Weight" type="L3DOUBLE">
	/// �ϸ�����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Right_Weight)

	/// <Property class="CBloom_Output_Log" name="Waster_Weight" type="L3DOUBLE">
	/// ˦��������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight)

	/// <Property class="CBloom_Output_Log" name="Wrong_Weight" type="L3DOUBLE">
	/// ���ϸ�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wrong_Weight)

	/// <Property class="CBloom_Input_Log" name="Bloom_Count" type="L3LONG">
	/// ����֦��
	/// </Property>
	DECLARE_L3PROP_LONG(Bloom_Count)

	/// <Property class="CBloom_Input_Log" name="Waster_Count" type="L3DOUBLE">
	/// ˦�ϸ�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count)

	/// <Property class="CBloom_Input_Log" name="Wrong_Count" type="L3LONG">
	/// ���ϸ����֦��
	/// </Property>
	DECLARE_L3PROP_LONG(Wrong_Count)

	/// <Property class="CBloom_Input_Log" name="Right_Count" type="L3LONG">
	/// �ϸ����֦��
	/// </Property>
	DECLARE_L3PROP_LONG(Right_Count)

};
