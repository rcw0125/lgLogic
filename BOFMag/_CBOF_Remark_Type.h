// 逻辑类CBOF_Remark_Type头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBOF_Remark_Type :
	public CL3Object
{
public:
	CBOF_Remark_Type(void);
	virtual ~CBOF_Remark_Type(void);

	DECLARE_L3CLASS(CBOF_Remark_Type,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_Remark_Type)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBOF_Remark_Type" name="TypeID" type="L3SHORT">
	/// 
	/// 分类
	/// (1:安全
	///  2:设备
	///  3:生产
	///  4:其他)
	/// </Property>
	DECLARE_L3PROP_SHORT(TypeID)

	/// <Property class="CBOF_Remark_Type" name="TypeDes" type="L3STRING">
	/// 
	/// 分类
	/// (1:安全
	///  2:设备
	///  3:生产
	///  4:其他)
	/// </Property>
	DECLARE_L3PROP_STRING(TypeDes)

};
