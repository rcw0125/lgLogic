// 逻辑类CBOF_Prod_Area头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
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

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

protected:
	/// <summary>
	/// 生成位置编码的虚函数。继承类可以重载此函数进行自己的位置编码定义。
	/// ARG >> void
	/// RET << 位置编码
	/// </summary>
	virtual CString GetPositionCode();

	/// <summary>
	/// 加工前预处理。在进行加工逻辑处理前调用，继承类可重载此函数进行数据预处理。
	/// ARG >> rsParameter : 加工参数记录集。
	/// RET << 返回TRUE继续加工；返回FALSE中断加工。
	/// </summary>
	virtual BOOL OnBeforeProcess(L3RECORDSET rsParameter);

	/// <summary>
	/// 材料加工逻辑处理。继承类需要重载此函数进行其特定的材料加工处理。
	/// 注意：在此方法中不要对加工相关的数据进行直接修改！调用它的主函数会做处理！
	/// ARG >> rsMaterials : 加工使用的原料信息。包括MaterialType,MaterialID,Amount字段。
	///		>> rsParameter : 加工使用的参数记录集。
	///		<< pnProcessType : 成功后返回加工类型。
	///		<< prsProducts : 成功后返回产品数据记录。
	///		<< prsMaterialMap : 如果加工类型是CreateNew，成功后返回原料成品对照表。否则无用。
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL ProcessMaterials(L3RECORDSET rsMaterials,L3RECORDSET rsParameter,L3LONG* pnProcessType,L3RECORDSET *prsProducts,L3RECORDSET *prsMaterialMap);

	/// <summary>
	/// 加工后续处理。在加工逻辑处理完成后调用，继承类可重载此函数进行额外处理。
	/// ARG >> rsMaterials : 加工使用的原料信息。包括MaterialType,MaterialID,Amount字段。
	///		>> rsParameter : 加工使用的参数记录集。
	///		>> pnProcessType : 加工类型。
	///		>> rsProducts : 产品数据记录。
	///		>> rsMaterialMap : 如果加工类型是CreateNew，为原料成品对照表。否则无用。
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL OnAfterProcessed(L3RECORDSET rsMaterials,L3RECORDSET rsParameter,L3LONG nProcessType,L3RECORDSET rsProducts,L3RECORDSET rsMaterialMap);

};
