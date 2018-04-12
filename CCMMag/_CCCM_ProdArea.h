// �߼���CCCM_ProdAreaͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_ProdArea :
	public CL3Object
{
public:
	CCCM_ProdArea(void);
	virtual ~CCCM_ProdArea(void);

	DECLARE_L3CLASS(CCCM_ProdArea,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_ProdArea)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Method class="CCCM_ProdArea" name="ProcessMaterials" type="L3BOOL">
	/// 
	/// ���ϼӹ��߼������̳�����Ҫ���ش˺����������ض��Ĳ��ϼӹ�����
	/// ע�⣺�ڴ˷����в�Ҫ�Լӹ���ص����ݽ���ֱ���޸ģ�����������������������
	/// ARG &gt;&gt; rsMaterials : �ӹ�ʹ�õ�ԭ����Ϣ������MaterialType,MaterialID,Amount�ֶΡ�
	/// &gt;&gt; rsParameter : �ӹ�ʹ�õĲ�����¼����
	/// &lt;&lt; pnProcessType : �ɹ��󷵻ؼӹ����͡�
	/// &lt;&lt; prsProducts : �ɹ��󷵻ز�Ʒ���ݼ�¼��
	/// &lt;&lt; prsMaterialMap : ����ӹ�������CreateNew���ɹ��󷵻�ԭ�ϳ�Ʒ���ձ��������á�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsMaterials" type="L3RECORDSET"></Param>
	/// <Param name="rsParameter" type="L3RECORDSET"></Param>
	/// <Param name="pnProcessType" type="L3LONG*"></Param>
	/// <Param name="prsMaterialMap" type="L3RECORDSET*"></Param>
	/// <Param name="prsProducts" type="L3RECORDSET*"></Param>
	/// </Method>
	L3BOOL ProcessMaterials(L3RECORDSET rsMaterials, L3RECORDSET rsParameter, L3LONG* pnProcessType, L3RECORDSET* prsMaterialMap, L3RECORDSET* prsProducts);
};
