// 逻辑类CSrap_Code头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CSrap_Code :
	public CL3Object
{
public:
	CSrap_Code(void);
	virtual ~CSrap_Code(void);

	DECLARE_L3CLASS(CSrap_Code,XGMESLogic\\ScrapStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CSrap_Code)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CSrap_Code" name="Scrap_Code" type="L3STRING">
	/// 废钢生铁代码
	/// </Property>
	DECLARE_L3PROP_STRING(Scrap_Code)

	/// <Property class="CSrap_Code" name="Scrap_Des" type="L3STRING">
	/// 废钢生铁名称
	/// </Property>
	DECLARE_L3PROP_STRING(Scrap_Des)

};
