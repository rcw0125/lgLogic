// �߼���CBOF_Prod_Areaͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "ProduceArea.h"

class CBOF_Prod_Area :
	public ProduceArea
{
public:
	CBOF_Prod_Area(void);
	virtual ~CBOF_Prod_Area(void);

	DECLARE_L3CLASS(CBOF_Prod_Area,XGMESLogic\\BOFMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_Prod_Area)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

protected:
	/// <summary>
	/// ����λ�ñ�����麯�����̳���������ش˺��������Լ���λ�ñ��붨�塣
	/// ARG >> void
	/// RET << λ�ñ���
	/// </summary>
	virtual CString GetPositionCode();

	/// <summary>
	/// �ӹ�ǰԤ�����ڽ��мӹ��߼�����ǰ���ã��̳�������ش˺�����������Ԥ����
	/// ARG >> rsParameter : �ӹ�������¼����
	/// RET << ����TRUE�����ӹ�������FALSE�жϼӹ���
	/// </summary>
	virtual BOOL OnBeforeProcess(L3RECORDSET rsParameter);

	/// <summary>
	/// ���ϼӹ��߼������̳�����Ҫ���ش˺����������ض��Ĳ��ϼӹ�����
	/// ע�⣺�ڴ˷����в�Ҫ�Լӹ���ص����ݽ���ֱ���޸ģ�����������������������
	/// ARG >> rsMaterials : �ӹ�ʹ�õ�ԭ����Ϣ������MaterialType,MaterialID,Amount�ֶΡ�
	///		>> rsParameter : �ӹ�ʹ�õĲ�����¼����
	///		<< pnProcessType : �ɹ��󷵻ؼӹ����͡�
	///		<< prsProducts : �ɹ��󷵻ز�Ʒ���ݼ�¼��
	///		<< prsMaterialMap : ����ӹ�������CreateNew���ɹ��󷵻�ԭ�ϳ�Ʒ���ձ��������á�
	/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// </summary>
	virtual BOOL ProcessMaterials(L3RECORDSET rsMaterials,L3RECORDSET rsParameter,L3LONG* pnProcessType,L3RECORDSET *prsProducts,L3RECORDSET *prsMaterialMap);

	/// <summary>
	/// �ӹ����������ڼӹ��߼�������ɺ���ã��̳�������ش˺������ж��⴦��
	/// ARG >> rsMaterials : �ӹ�ʹ�õ�ԭ����Ϣ������MaterialType,MaterialID,Amount�ֶΡ�
	///		>> rsParameter : �ӹ�ʹ�õĲ�����¼����
	///		>> pnProcessType : �ӹ����͡�
	///		>> rsProducts : ��Ʒ���ݼ�¼��
	///		>> rsMaterialMap : ����ӹ�������CreateNew��Ϊԭ�ϳ�Ʒ���ձ��������á�
	/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// </summary>
	virtual BOOL OnAfterProcessed(L3RECORDSET rsMaterials,L3RECORDSET rsParameter,L3LONG nProcessType,L3RECORDSET rsProducts,L3RECORDSET rsMaterialMap);

};
