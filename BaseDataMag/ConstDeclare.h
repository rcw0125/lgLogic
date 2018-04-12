
/********************************************************************************************
*  �ļ�����ConstDeclare.h																	*
*  ��  Ŀ���ϸ�MESϵͳ������ģ��												*
*  ��Ȩ���� (C) 2008-2009 ��������ֹ�˾													*
*  �����ˣ�	����																				*
*  ��  �ڣ�	2008-11-11																	*
*  �޸��ˣ�																					*
*  ��  �ڣ�																					*
*  ��  �������ļ�Ϊ���������塱�࣬���泣������												*
*  ��  ����V1.0																				*
*********************************************************************************************/ 


const CString MATERIAL_TYPE_STEEL = _T("CSteel_Data");
const CString MATERIAL_TYPE_IRON  = _T("CIron_Data");
const CString MATERIAL_TYPE_ALLOY = _T("CAlloy_Data");
const CString MATERIAL_TYPE_SCRAP = _T("CScrap_Data");
const CString MATERIAL_TYPE_BLOOM = _T("CBloom_Data");
const CString MATERIAL_TYPE_BULK  = _T("CBulk_Data");

//����0����ˮ��1������¯��2��ת¯��3��¯��4��LF��5��RH��6������,7��������,8:ԭ�Ͽ�

const CString UNIT_TYPE_IRON	= _T("0");//��ˮ����
const CString UNIT_TYPE_MIXF	= _T("1");//����¯����
const CString UNIT_TYPE_BOF		= _T("2");//ת¯����
const CString UNIT_TYPE_TAPSIDE	= _T("3");//¯������
const CString UNIT_TYPE_LF		= _T("4");//LF����
const CString UNIT_TYPE_RH		= _T("5");//RH����
const CString UNIT_TYPE_CASTER  = _T("6");//��������
const CString STROE_TYPE_BLOOM   = _T("7");//��������
const CString STROE_TYPE_MATERIAL  = _T("8");//ԭ�Ͽ���


const L3SHORT UNIT_AREA_IRON	= 0;//��ˮ����
const L3SHORT UNIT_AREA_MIXF	= 1;//����¯����
const L3SHORT UNIT_AREA_BOF		= 2;//ת¯����
const L3SHORT UNIT_AREA_TAPSIDE	= 3;//¯������
const L3SHORT UNIT_AREA_LF		= 4;//LF����
const L3SHORT UNIT_AREA_RH		= 5;//RH����
const L3SHORT UNIT_AREA_CASTER  = 6;//��������
const L3SHORT UNIT_AREA_BLOOM   = 7;//��������
const L3SHORT UNIT_AREA_MATERIAL  = 8;//ԭ�Ͽ���

//���顢������룬������ֻ��һ���ӹ���ʱ����ӹ���������������һ�£��ж���ӹ�λʱ�ڻ����������λ��ˮ��
//���水�ջ����������ʱ���ݹ���·��ֱ�ӽ����Ϸ����¹�����뻺���еķ�ʽ����

const CString UNIT_ID_IRON				= _T("S01");    //������ˮ���볧��ˮ����

const CString UNIT_ID_1DES				= _T("S02");    //1#������ 2009-10-20
const CString UNIT_ID_2DES				= _T("S03");    //2#������ 2009-10-20

const CString UNIT_ID_IRON_CACHE		= _T("S00N01"); //������ˮ���⻺��
const CString UNIT_ID_1MIX				= _T("S11");    //1#����¯���飬1#����¯�ӹ�λ
const CString UNIT_ID_2MIX				= _T("S12");	//2#����¯���飬2#����¯�ӹ�λ
//add by hyh 2012-04-03 ������3#����¯
const CString UNIT_ID_3MIX				= _T("S13");	//3#����¯���飬3#����¯�ӹ�λ
//end
const CString UNIT_ID_MIX_CACHE			= _T("S10N01");	//����¯��������ֱ����ˮ����

const CString UNIT_ID_1BOF				= _T("S21");    //1#ת¯���飬1#ת¯�ӹ�λ
const CString UNIT_ID_2BOF				= _T("S22");    //2#ת¯���飬2#ת¯�ӹ�λ
const CString UNIT_ID_3BOF				= _T("S23");    //3#ת¯���飬3#ת¯�ӹ�λ
const CString UNIT_ID_4BOF				= _T("S24");    //4#ת¯���飬4#ת¯�ӹ�λ

const CString UNIT_ID_1TAPSIDE_CACHE	= _T("S31P01"); //1#ת¯¯������ǰ����
const CString UNIT_ID_2TAPSIDE_CACHE	= _T("S32P01"); //2#ת¯¯������ǰ����
const CString UNIT_ID_3TAPSIDE_CACHE	= _T("S33P01"); //3#ת¯¯������ǰ����
const CString UNIT_ID_4TAPSIDE_CACHE	= _T("S34P01"); //4#ת¯¯������ǰ����
const CString UNIT_ID_1TAPSIDE			= _T("S31");	//1#ת¯¯����飬1#ת¯¯��ӹ�λ
const CString UNIT_ID_2TAPSIDE			= _T("S32");	//2#ת¯¯����飬2#ת¯¯��ӹ�λ
const CString UNIT_ID_3TAPSIDE			= _T("S33");	//3#ת¯¯����飬3#ת¯¯��ӹ�λ
const CString UNIT_ID_4TAPSIDE			= _T("S34");	//4#ת¯¯����飬4#ת¯¯��ӹ�λ

const CString UNIT_ID_1LF_CACHE			= _T("S41P01");	//1#LF¯����ǰ����
const CString UNIT_ID_2LF_CACHE			= _T("S42P01");	//2#LF¯����ǰ����
const CString UNIT_ID_3LF_CACHE			= _T("S43P01");	//3#LF¯����ǰ����
//Modify by llj 2011-1-18 ������޸�
const CString UNIT_ID_5LF_CACHE			= _T("S45P01");	//5#LF¯����ǰ����
//add by hyh 2012-05-09 ����4#LF
const CString UNIT_ID_4LF_CACHE			= _T("S44P01");	//4#LF¯����ǰ����

const CString UNIT_ID_1LF				= _T("S41");    //1#LF¯���飬1#LF¯�ӹ�λ
const CString UNIT_ID_2LF				= _T("S42");	//2#LF¯���飬2#LF¯�ӹ�λ
const CString UNIT_ID_3LF				= _T("S43");	//3#LF¯���飬3#LF¯�ӹ�λ
//Modify by llj 2011-1-18 ������޸�
const CString UNIT_ID_5LF				= _T("S45");	//5#LF¯���飬5#LF¯�ӹ�λ
//add by hyh 2012-05-09 ����4#LF
const CString UNIT_ID_4LF				= _T("S44");	//4#LF¯���飬4#LF¯�ӹ�λ

const CString UNIT_ID_1RH_CACHE			= _T("S51P01");	//1#RH¯����ǰ����
const CString UNIT_ID_1RH				= _T("S51");	//1#RH¯���飬1#RH¯�ӹ�λ

const CString UNIT_ID_1CASTER_CACHE		= _T("S61P01");	//1#��������ǰ����
const CString UNIT_ID_2CASTER_CACHE		= _T("S62P01");	//2#��������ǰ����
const CString UNIT_ID_3CASTER_CACHE		= _T("S63P01");	//3#��������ǰ����
const CString UNIT_ID_4CASTER_CACHE		= _T("S64P01");	//4#��������ǰ����
const CString UNIT_ID_5CASTER_CACHE		= _T("S65P01");	//5#��������ǰ����
//Modify by llj 2011-1-18 ������޸�
const CString UNIT_ID_7CASTER_CACHE		= _T("S67P01");	//7#��������ǰ����
//Modify by hyh 2012-05-09 ������޸�
const CString UNIT_ID_6CASTER_CACHE		= _T("S66P01");	//6#��������ǰ����


const CString UNIT_ID_1CASTER			= _T("S61");	//1#�������飬1#�����ӹ�λ
const CString UNIT_ID_2CASTER			= _T("S62");	//2#�������飬2#�����ӹ�λ
const CString UNIT_ID_3CASTER			= _T("S63");	//3#�������飬3#�����ӹ�λ
const CString UNIT_ID_4CASTER			= _T("S64");	//4#�������飬4#�����ӹ�λ
const CString UNIT_ID_5CASTER			= _T("S65");	//5#�������飬5#�����ӹ�λ
//Modify by llj 2011-1-18 ������޸�
const CString UNIT_ID_7CASTER			= _T("S67");	//7#�������飬7#�����ӹ�λ
//Modify by hyh 2012-05-09 ������޸�
const CString UNIT_ID_6CASTER			= _T("S66");	//6#�������飬6#�����ӹ�λ

const CString UNIT_ID_BLOOM_PCACHE		= _T("S71P01");	//����������⻺��
const CString STORE_ID_BLOOM			= _T("S71");	//������
const CString STORE_ID_BLOOM_STOCK		= _T("S71A01");	//���������
const CString STORE_ID_BLOOM_COOL		= _T("S71B01");	//�����⻺����
const CString STORE_ID_BLOOM_CACHE		= _T("S71N01");	//��������⻺��

const CString STORE_ID_ALLOY_PCACHE	= _T("S81P01");	//�Ͻ�ԭ�Ͽ���⻺��
const CString STORE_ID_ALLOY		= _T("S81");	//�Ͻ�ԭ�Ͽ�

//A:1#ת¯�߲�;B:�濾¯;C:1#LF�Ͻ�߲�;D:2#LF�Ͻ�߲�;E:LF���ø߲�
//1#ת¯�߲�
const CString STORE_ID_ALLOY_HIGH_1		= _T("S81A01");	//�Ͻ�ԭ�Ͽ�1#ת¯�߲�1#�ϲ�
const CString STORE_ID_ALLOY_HIGH_2		= _T("S81A02");	//�Ͻ�ԭ�Ͽ�1#ת¯�߲�2#�ϲ�
const CString STORE_ID_ALLOY_HIGH_3		= _T("S81A03");	//�Ͻ�ԭ�Ͽ�1#ת¯�߲�3#�ϲ�
const CString STORE_ID_ALLOY_HIGH_4		= _T("S81A04");	//�Ͻ�ԭ�Ͽ�1#ת¯�߲�4#�ϲ�
const CString STORE_ID_ALLOY_HIGH_5		= _T("S81A05");	//�Ͻ�ԭ�Ͽ�1#ת¯�߲�5#�ϲ�
const CString STORE_ID_ALLOY_HIGH_6		= _T("S81A06");	//�Ͻ�ԭ�Ͽ�1#ת¯�߲�6#�ϲ�
const CString STORE_ID_ALLOY_HIGH_7		= _T("S81A07");	//�Ͻ�ԭ�Ͽ�1#ת¯�߲�7#�ϲ�
const CString STORE_ID_ALLOY_HIGH_8		= _T("S81A08");	//�Ͻ�ԭ�Ͽ�1#ת¯�߲�8#�ϲ�

//�濾¯
const CString STORE_ID_ALLOY_HOT_1		= _T("S81B01");	//�Ͻ�ԭ�Ͽ�濾¯1#�ϲ�
const CString STORE_ID_ALLOY_HOT_2		= _T("S81B02");	//�Ͻ�ԭ�Ͽ�濾¯2#�ϲ�
const CString STORE_ID_ALLOY_HOT_3		= _T("S81B03");	//�Ͻ�ԭ�Ͽ�濾¯3#�ϲ�
const CString STORE_ID_ALLOY_HOT_4		= _T("S81B04");	//�Ͻ�ԭ�Ͽ�濾¯4#�ϲ�
const CString STORE_ID_ALLOY_HOT_5		= _T("S81B05");	//�Ͻ�ԭ�Ͽ�濾¯5#�ϲ�
const CString STORE_ID_ALLOY_HOT_6		= _T("S81B06");	//�Ͻ�ԭ�Ͽ�濾¯6#�ϲ�
const CString STORE_ID_ALLOY_HOT_7		= _T("S81B07");	//�Ͻ�ԭ�Ͽ�濾¯7#�ϲ�
const CString STORE_ID_ALLOY_HOT_8		= _T("S81B08");	//�Ͻ�ԭ�Ͽ�濾¯8#�ϲ�
const CString STORE_ID_ALLOY_HOT_9		= _T("S81B09");	//�Ͻ�ԭ�Ͽ�濾¯9#�ϲ�
const CString STORE_ID_ALLOY_HOT_10		= _T("S81B10");	//�Ͻ�ԭ�Ͽ�濾¯10#�ϲ�
const CString STORE_ID_ALLOY_HOT_11		= _T("S81B11");	//�Ͻ�ԭ�Ͽ�濾¯11#�ϲ�
const CString STORE_ID_ALLOY_HOT_12		= _T("S81B12");	//�Ͻ�ԭ�Ͽ�濾¯12#�ϲ�
const CString STORE_ID_ALLOY_HOT_13		= _T("S81B13");	//�Ͻ�ԭ�Ͽ�濾¯13#�ϲ�
const CString STORE_ID_ALLOY_HOT_14		= _T("S81B14");	//�Ͻ�ԭ�Ͽ�濾¯14#�ϲ�
const CString STORE_ID_ALLOY_HOT_15		= _T("S81B15");	//�Ͻ�ԭ�Ͽ�濾¯15#�ϲ�
const CString STORE_ID_ALLOY_HOT_16		= _T("S81B16");	//�Ͻ�ԭ�Ͽ�濾¯16#�ϲ�
const CString STORE_ID_ALLOY_HOT_17		= _T("S81B17");	//�Ͻ�ԭ�Ͽ�濾¯17#�ϲ�
const CString STORE_ID_ALLOY_HOT_18		= _T("S81B18");	//�Ͻ�ԭ�Ͽ�濾¯18#�ϲ�

//1#LF¯�߲�
const CString STORE_ID_ALLOY_1LF_1		= _T("S81C01");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�1#�ϲ�
const CString STORE_ID_ALLOY_1LF_2		= _T("S81C02");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�2#�ϲ�
const CString STORE_ID_ALLOY_1LF_3		= _T("S81C03");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�3#�ϲ�
const CString STORE_ID_ALLOY_1LF_4		= _T("S81C04");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�4#�ϲ�
const CString STORE_ID_ALLOY_1LF_5		= _T("S81C05");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�5#�ϲ�
const CString STORE_ID_ALLOY_1LF_6		= _T("S81C06");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�6#�ϲ�
const CString STORE_ID_ALLOY_1LF_7		= _T("S81C07");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�7#�ϲ�
const CString STORE_ID_ALLOY_1LF_8		= _T("S81C08");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�8#�ϲ�
const CString STORE_ID_ALLOY_1LF_9		= _T("S81C09");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�9#�ϲ�
const CString STORE_ID_ALLOY_1LF_10		= _T("S81C10");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�10#�ϲ�

//2#LF¯�߲�
const CString STORE_ID_ALLOY_2LF_1		= _T("S81D01");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�1#�ϲ�
const CString STORE_ID_ALLOY_2LF_2		= _T("S81D02");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�2#�ϲ�
const CString STORE_ID_ALLOY_2LF_3		= _T("S81D03");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�3#�ϲ�
const CString STORE_ID_ALLOY_2LF_4		= _T("S81D04");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�4#�ϲ�
const CString STORE_ID_ALLOY_2LF_7		= _T("S81D05");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�5#�ϲ�
const CString STORE_ID_ALLOY_2LF_6		= _T("S81D06");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�6#�ϲ�

//1#2#LF¯���ø߲�
const CString STORE_ID_ALLOY_12LF_1		= _T("S81E01");	//�Ͻ�ԭ�Ͽ⹫�ø߲�1#�ϲ�
const CString STORE_ID_ALLOY_12LF_2		= _T("S81E02");	//�Ͻ�ԭ�Ͽ⹫�ø߲�2#�ϲ�
const CString STORE_ID_ALLOY_12LF_3		= _T("S81E03");	//�Ͻ�ԭ�Ͽ⹫�ø߲�3#�ϲ�
const CString STORE_ID_ALLOY_12LF_4		= _T("S81E04");	//�Ͻ�ԭ�Ͽ⹫�ø߲�4#�ϲ�
const CString STORE_ID_ALLOY_12LF_5		= _T("S81E05");	//�Ͻ�ԭ�Ͽ⹫�ø߲�5#�ϲ�
const CString STORE_ID_ALLOY_12LF_6		= _T("S81E06");	//�Ͻ�ԭ�Ͽ⹫�ø߲�6#�ϲ�
const CString STORE_ID_ALLOY_12LF_7		= _T("S81E07");	//�Ͻ�ԭ�Ͽ⹫�ø߲�7#�ϲ�


const CString STORE_ID_ALLOY_CACHE	= _T("S81N01");	//�Ͻ�ԭ�Ͽ���⻺��

const CString STORE_ID_SCRAP_PCACHE	= _T("S82P01");	//�ϸ�����ԭ�Ͽ���⻺��
const CString STORE_ID_SCRAP		= _T("S82");	//�ϸ�����ԭ�Ͽ�
const CString STORE_ID_SCRAP_CACHE	= _T("S82N01");	//�ϸ�����ԭ�Ͽ���⻺��


const CString STORE_ID_BULK_PCACHE	= _T("S83P01");	//ɢ״��ԭ�Ͽ���⻺��
const CString STORE_ID_BULK			= _T("S83");	//ɢ״��ԭ�Ͽ�
const CString STORE_ID_BULK_CACHE	= _T("S83N01");	//ɢ״��ԭ�Ͽ���⻺��

const CString STORE_ID_BULK_HIGH_1	= _T("S83A01");	//ɢ״��ԭ�Ͽ�1#ת¯�߲�1#�ϲ�
const CString STORE_ID_BULK_HIGH_2	= _T("S83A02");	//ɢ״��ԭ�Ͽ�1#ת¯�߲�2#�ϲ�
const CString STORE_ID_BULK_HIGH_3	= _T("S83A03");	//ɢ״��ԭ�Ͽ�1#ת¯�߲�3#�ϲ�
const CString STORE_ID_BULK_HIGH_4	= _T("S83A04");	//ɢ״��ԭ�Ͽ�1#ת¯�߲�4#�ϲ�
const CString STORE_ID_BULK_HIGH_5	= _T("S83A05");	//ɢ״��ԭ�Ͽ�1#ת¯�߲�5#�ϲ�
const CString STORE_ID_BULK_HIGH_6	= _T("S83A06");	//ɢ״��ԭ�Ͽ�1#ת¯�߲�6#�ϲ�
const CString STORE_ID_BULK_HIGH_7	= _T("S83A07");	//ɢ״��ԭ�Ͽ�1#ת¯�߲�7#�ϲ�
const CString STORE_ID_BULK_HIGH_8	= _T("S83A08");	//ɢ״��ԭ�Ͽ�1#ת¯�߲�8#�ϲ�


//NCͨѶ����URI
const CString NC_COMMUNICATOR_URI	= _T("XGMESLogic\\BaseDataMag\\CNCCommunicator\\NCComm");
//�������߼�����
const CString SHIFT_MAG_URI			= _T("XGMESLogic\\ShiftTeamMag\\CShiftMag\\1");

//���ϼ۸��
const CString CMATERIAL_PRICE_URI	= _T("XGMESLogic\\BaseDataMag\\CMaterial_Price");



//����ʵ����URI
const CString MATERIAL_BFIRON_URI	= _T("MES\\MaterialData\\CBFIron");
const CString MATERIAL_IRON_URI		= _T("MES\\MaterialData\\CIron_Data");
const CString MATERIAL_STEEL_URI	= _T("MES\\MaterialData\\CSteel_Data");
const CString ALLOY_DATA_CLASS_URI	= _T("MES\\MaterialData\\CAlloy_Data");//�Ͻ�����ʵ����
const CString SCRAP_DATA_CLASS_URI	= _T("MES\\MaterialData\\CScrap_Data");//�ϸ�����ʵ����
const CString BULK_DATA_CLASS_URI	= _T("MES\\MaterialData\\CBulk_Data");//ɢ״������ʵ����
const CString BLOOM_DATA_CLASS_URI	= _T("MES\\MaterialData\\CBloom_Data");//��������ʵ����

//���ϻ�����URI
const CString XGINTERCACHE_URI = _T("XGMESLogic\\BaseDataMag\\XGInterCache");		// ͨ�û������ϻ�����
const CString XGSTOREAREA_URI = _T("XGMESLogic\\BaseDataMag\\XGStoreArea");			// ͨ�ÿ�����
const CString XGPRODUCEAREA_URI = _T("XGMESLogic\\BaseDataMag\\XGProduceArea");		// ͨ���������鹤λ��

//����ģ��ʵ����URI
const CString DISPATCH_STEEL_BACK_CLASS_URI	= _T("XGMESLogic\\DispatchMag\\CDisp_SteelBack_App");
const CString DISPATCH_STEEL_DIV_CLASS_URI	= _T("XGMESLogic\\DispatchMag\\CDisp_SteelDiv_App");
const CString DISPATCH_STEEL_EXE_CLASS_URI		= _T("XGMESLogic\\DispatchMag\\CDisp_SteelExchange_App");
const CString DISPATCH_STEEL_TURN_CLASS_URI		= _T("XGMESLogic\\DispatchMag\\CDisp_SteelTurn_App");
const CString DISPATCH_LOG_CLASS_URI		= _T("XGMESLogic\\DispatchMag\\CDisp_Duty_Note");
const CString DISPATCH_OBJ_URI					= _T("XGMESLogic\\DispatchMag\\CDispatch_Mag\\Dispatch_Mag");

//�ƻ�ģ��ʵ����URI
const CString PLAN_ORDER_CLASS_URI			= _T("XGMESLogic\\PlanMag\\CPlan_Order");
const CString PLAN_CUR_PREHEATID_CLASS_URI	= _T("XGMESLogic\\PlanMag\\CPlan_Cur_PreHeatID");
const CString PLAN_CASTING_CLASS_URI		= _T("XGMESLogic\\PlanMag\\CPlan_Casting");
const CString PLAN_TAPPING_CLASS_URI		= _T("XGMESLogic\\PlanMag\\CPlan_Tapping");
const CString PLAN_TAPPING_ACT_CLASS_URI	= _T("XGMESLogic\\PlanMag\\CPlan_Tapping_Act");
const CString PLAN_BOF_CLASS_URI			= _T("XGMESLogic\\PlanMag\\CPlan_BOF_Status");
const CString PLAN_BOF_NON_PROC_CLASS_URI	= _T("XGMESLogic\\PlanMag\\CPlan_BOFNon_Proc_Time");
const CString PLAN_EQUIMENT_CLASS_URI		= _T("XGMESLogic\\PlanMag\\CPlan_Equipment");
//�ƻ������߼�������
const CString PLAN_OBJ_URI					= _T("XGMESLogic\\PlanMag\\CPlan_Mag\\Plan_Mag");

//���ڴ洢�û�������Ϣ��ʵ�ֶ�������δ�޸�������˻�
//add by hyh 2012-03-31
const CString UserPwd_Lock_URI = _T("XGMESLogic\\BaseDataMag\\CBase_UserPwd_Lock");
//end



//����ģ��ʵ����URI
const CString QA_STG_RELATION_CLASS_URI		= _T("XGMESLogic\\QualityMag\\CQA_SteelGradeIndex_R");
const CString QA_PROD_SHEET_CLASS_URI		= _T("XGMESLogic\\QualityMag\\CQA_Product_Sheet");
const CString QA_CAL_WEIGHT_CLASS_URI	= _T("XGMESLogic\\QualityMag\\CQA_Cal_Weight_Std");
const CString QA_UNIT_PROC_TIME_CLASS_URI	= _T("XGMESLogic\\QualityMag\\CQA_Unit_Proc_Time");
const CString QA_UNIT_ROUTE_CLASS_URI	= _T("XGMESLogic\\QualityMag\\CQA_Unit_Route");
const CString QA_UNIT_TRANS_TIME_CLASS_URI		= _T("XGMESLogic\\QualityMag\\CQA_Unit_Trans_Time");
const CString QA_HOT_JUDGE_CLASS_URI		=_T("XGMESLogic\\QualityMag\\CQA_Bloom_HotJudge_Data");
const CString QA_FIN_JUDGE_CLASS_URI		=_T("XGMESLogic\\QualityMag\\CQA_Bloom_FinJudge_Data");
//����ģ�������׼ʵ����URI
const CString QA_BOF_STD_AR_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Ar");
const CString QA_BOF_STD_BASE_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Base");
const CString QA_BOF_STD_BLOW_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Blow");
const CString QA_BOF_STD_BLOWO2_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_BOF_Std_BlowO2");
const CString QA_BOF_STD_BULK_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Bulk");
const CString QA_BOF_STD_FEED_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Feed");
const CString QA_BOF_STD_INCTR_ELE_CLASS_URI		= _T("XGMESLogic\\QualityMag\\CQA_BOF_Std_InCtr_Ele");
const CString QA_BOF_STD_INTOCONVER_CLASS_URI		= _T("XGMESLogic\\QualityMag\\CQA_BOF_Std_InToConver");
const CString QA_BOF_STD_LADLE_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Ladle");
const CString QA_BOF_STD_SLAG_ELE_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Slag_Ele");
const CString QA_BOF_STD_TAPPING_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Tapping");
 
const CString QA_LF_STD_ALLOY_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_LF_Std_Alloy");
const CString QA_LF_STD_BASE_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_LF_Std_Base");
const CString QA_LF_STD_FEED_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_LF_Std_Feed");
const CString QA_LF_STD_INCTR_ELE_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_LF_Std_InCtr_Ele");
const CString QA_LF_STD_LADLE_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_LF_Std_Ladle");
const CString QA_LF_STD_PROC_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_LF_Std_Proc");
const CString QA_LF_STD_SLAG_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_LF_Std_Slag");
const CString QA_LF_STD_SLAG_ELE_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_LF_Std_Slag_Ele");

const CString QA_RH_STD_ALLOY_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_RH_Std_Alloy");
const CString QA_RH_STD_BASE_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_RH_Std_Base");
const CString QA_RH_STD_FEED_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_RH_Std_Feed");
const CString QA_RH_STD_INCTR_ELE_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_RH_Std_InCtr_Ele");
const CString QA_RH_STD_PROC_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_RH_Std_Proc");

const CString QA_CCM_STD_FLUX_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_Caster_Std_Flux");
const CString QA_CCM_STD_PROC_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_Caster_Std_Proc");
const CString QA_CCM_STD_PRODPROC_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_Caster_Std_ProdProc");
const CString QA_CCM_STD_SPEC_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_Caster_Std_Spec");
const CString QA_CCM_STD_SPEED_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_Caster_Std_Speed");
const CString QA_CCM_STD_TUNDISH_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_Caster_Std_Tundish");
const CString QA_CCM_STD_BASE_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_Caster_Std_Base");

const CString QA_LAB_SHEET_APPID_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_Lab_Sheet_AppID");
const CString QA_LAB_SHEET_APP_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_Lab_Sheet_App");
const CString QA_LAB_ELEMENT_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_Lab_Element");
const CString QA_LAB_ELEMENT_TEXT_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_Lab_Element_Text");
const CString QA_LAB_S_PRINT_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_Lab_S_Print");
const CString QA_LAB_SLAGELE_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_Lab_SlagEle");
const CString QA_LAB_SLAGELE_TEXT_CLASS_URI			= _T("XGMESLogic\\QualityMag\\CQA_Lab_SlagEle_Text");
const CString BASE_ADDRESS_BULK_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CBase_Address_Bulk_Relation");


const CString CHEMICAL_EXCEPTIONAL_CODE = _T("501");
//�ְ�����
const L3LONG OLD_LADLE_WEIGHT = 46000;
const L3LONG NEW_LADLE_WEIGHT = 76000;
const L3LONG BALANCE_WEIGHT = 10000;

const CString EMPTY_ERR = _T("Empty");


//������URI
const CString BFIronInLog_URI = _T("XGMESLogic\\BFMag\\CBFIronInLog");	// �볧��ˮ����¼
const CString BFIronOutLog_URI = _T("XGMESLogic\\BFMag\\CBFIronOutLog"); // �볧��ˮ�����¼
const CString MIXFMag_URI = _T("XGMESLogic\\MIXFMag\\CMIF_Mag");	// ����¯���������
const CString MIXFUnit_URI = _T("XGMESLogic\\MIXFMag\\CMIF_Unit_Mag"); // ����¯����
const CString MIXFArea_URI = _T("XGMESLogic\\MIXFMag\\CMIF_Area"); // ����¯����ӹ�λ
const CString MIXF_FeedLog_URI = _T("XGMESLogic\\MIXFMag\\CMIF_Feed_Log"); // ������־

//�������URI
const CString BFIronStore_URI = _T("XGMESLogic\\BFMag\\CBF_Iron_Mag\\BFIronMag");	// �볧��ˮ�ⷿ
const CString BFIronStoreArea_URI = _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S01");	// �볧��ˮ����
const CString BFIronStoreOutCache_URI = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\S00N01"); // �볧��ˮ��󻺴�
const CString BFIronCastCache_URI = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\Cast"); // ������ȥ����ˮ����

const CString MIXFMagObj_URI = _T("XGMESLogic\\MIXFMag\\CMIF_Mag\\MIFMag"); // ��������������
const CString MIXFProduceUnit1_URI = _T("XGMESLogic\\MIXFMag\\CMIF_Unit_Mag\\S11");	// 1�Ż���¯����
const CString MIXFProduceUnit2_URI = _T("XGMESLogic\\MIXFMag\\CMIF_Unit_Mag\\S12");	// 2�Ż���¯����
const CString MIXFProduceArea1_URI = _T("XGMESLogic\\MIXFMag\\CMIF_Area\\S11"); // 1�Ż���¯�ӹ�λ
const CString MIXFProduceArea2_URI = _T("XGMESLogic\\MIXFMag\\CMIF_Area\\S12"); // 1�Ż���¯�ӹ�λ

const CString MIXFProduceCache_URI = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\S10N01"); // ����¯������������


//ת¯���������
const CString BOF_CLASS_URI = _T("XGMESLogic\\BOFMag\\CBOF_Unit_Mag");
//ת¯����ʵ����
const CString BOF_BASE_DATA_CLASS_URI		= _T("XGMESLogic\\BOFMag\\CBOF_Base_Data"); // ת¯¯�λ�������
const CString BOF_FEED_DATA_CLASS_URI		= _T("XGMESLogic\\BOFMag\\CBOF_Feed_Data");	// ת¯¯��ԭ������
const CString BOF_PROC_STATUS_CLASS_URI		= _T("XGMESLogic\\BOFMag\\CBOF_Process_Status"); // ת¯�����¼�����
const CString BOF_ADDITION_DATA_CLASS_URI	= _T("XGMESLogic\\BOFMag\\CBOF_Addition_Data"); // ת¯��������
const CString BOF_TOP_BLOWING_CLASS_URI		= _T("XGMESLogic\\BOFMag\\CBOF_Top_Blowing"); // ������¼
const CString BOF_BOTTOM_BLOWING_CLASS_URI	= _T("XGMESLogic\\BOFMag\\CBOF_Bottom_Blowing"); // ������¼
const CString BOF_OXYGEN_DATA_CLASS_URI		= _T("XGMESLogic\\BOFMag\\CBOF_Oxygen_Data"); // �����¼���¼
const CString BOF_TEMP_DATA_CLASS_URI		= _T("XGMESLogic\\BOFMag\\CBOF_Temp_Data"); // �����¼���¼
const CString BOF_EQUIPMENT_STATUS_CLASS_URI = _T("XGMESLogic\\BOFMag\\CBOF_Equipment_Status"); // �豸״̬��־
const CString BOF_PROCESS_DATA_CLASS_URI	= _T("XGMESLogic\\BOFMag\\CBOF_Process_Data"); // ���ֹ�������
const CString UNIT_DUTY_CLASS_URI	= _T("XGMESLogic\\BOFMag\\CDuty_Definition"); // ������Ա


//ת¯�������URI
//ת¯����
const CString BOF1_UNIT_URI = _T("XGMESLogic\\BOFMag\\CBOF_Unit_Mag\\S21");
const CString BOF2_UNIT_URI = _T("XGMESLogic\\BOFMag\\CBOF_Unit_Mag\\S22");
const CString BOF3_UNIT_URI = _T("XGMESLogic\\BOFMag\\CBOF_Unit_Mag\\S23");
const CString BOF4_UNIT_URI = _T("XGMESLogic\\BOFMag\\CBOF_Unit_Mag\\S24");

// ת¯�ӹ���λ
const CString BOF1_AREA_URI = _T("XGMESLogic\\BOFMag\\CBOF_Prod_Area\\S21");
const CString BOF2_AREA_URI = _T("XGMESLogic\\BOFMag\\CBOF_Prod_Area\\S22");
const CString BOF3_AREA_URI = _T("XGMESLogic\\BOFMag\\CBOF_Prod_Area\\S23");
const CString BOF4_AREA_URI = _T("XGMESLogic\\BOFMag\\CBOF_Prod_Area\\S24");

//ת¯���ڻ���
const CString BOF1_OutCache_URI = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\S31P01");
const CString BOF2_OutCache_URI = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\S32P01");
const CString BOF3_OutCache_URI = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\S33P01");
const CString BOF4_OutCache_URI = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\S34P01");

//¯���������
const CString BOF_SIDE_CLASS_URI = _T("XGMESLogic\\TapSideMag\\CTap_Unit_Mag");
//¯�����
const CString TAPSIDE1_UNIT_URI = _T("XGMESLogic\\TapSideMag\\CTap_Unit_Mag\\S31");
const CString TAPSIDE2_UNIT_URI = _T("XGMESLogic\\TapSideMag\\CTap_Unit_Mag\\S32");
const CString TAPSIDE3_UNIT_URI = _T("XGMESLogic\\TapSideMag\\CTap_Unit_Mag\\S33");
const CString TAPSIDE4_UNIT_URI = _T("XGMESLogic\\TapSideMag\\CTap_Unit_Mag\\S34");
//¯����鴦��λ
const CString TAPSIDE1_AREA_URI = _T("XGMESLogic\\BaseDataMag\\XGProduceArea\\S31");
const CString TAPSIDE2_AREA_URI = _T("XGMESLogic\\BaseDataMag\\XGProduceArea\\S32");
const CString TAPSIDE3_AREA_URI = _T("XGMESLogic\\BaseDataMag\\XGProduceArea\\S33");
const CString TAPSIDE4_AREA_URI = _T("XGMESLogic\\BaseDataMag\\XGProduceArea\\S34");

//¯��ʵ����
const CString TAP_BASE_DATA_CLASS_URI = _T("XGMESLogic\\TapSideMag\\CTap_Base_Data");
const CString TAP_PROCESS_DATA_CLASS_URI = _T("XGMESLogic\\TapSideMag\\CTap_Process_Data");
const CString TAP_ADDITION_DATA_CLASS_URI = _T("XGMESLogic\\TapSideMag\\CTap_Addition_Data");
const CString TAP_LADLE_WEIGHT_CLASS_URI = _T("XGMESLogic\\TapSideMag\\CTap_Ladle_Weight");
const CString TAP_OXYGEN_DATA_CLASS_URI = _T("XGMESLogic\\TapSideMag\\CTap_Oxygen_Data");
const CString TAP_TEMP_DATA_CLASS_URI = _T("XGMESLogic\\TapSideMag\\CTap_Temp_Data");

//LF���������
const CString LF_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Unit_Mag");
const CString LF_AREA_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Prod_Area");

//LF����
const CString LF1_UNIT_URI = _T("XGMESLogic\\LFMag\\CLF_Unit_Mag\\S41");
const CString LF2_UNIT_URI = _T("XGMESLogic\\LFMag\\CLF_Unit_Mag\\S42");
const CString LF3_UNIT_URI = _T("XGMESLogic\\LFMag\\CLF_Unit_Mag\\S43");
//Modify by llj 2011-1-18 ������޸�
const CString LF5_UNIT_URI = _T("XGMESLogic\\LFMag\\CLF_Unit_Mag\\S45");//5#LF
//Modify by hyh 2012-05-09 ������޸�
const CString LF4_UNIT_URI = _T("XGMESLogic\\LFMag\\CLF_Unit_Mag\\S44");//4#LF

//LF����ʵ����
const CString LF_BASE_DATA_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Base_Data");
const CString LF_ADDITION_DATA_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Addition_Data");
const CString LF_EQUIPMENT_STATUS_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Equipment_Status");
const CString LF_FEED_DATA_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Feed_Data");
const CString LF_HEATREMARK_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_HeatRemark");
const CString LF_LADLE_WEIGHT_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Ladle_Weight");
const CString LF_OXYGEN_DATA_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Oxygen_Data");
const CString LF_PROCESS_DATA_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Process_Data");
const CString LF_PROCESS_STATUS_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Process_Satus");
const CString LF_TEMP_DATA_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Temp_Data");
const CString LF_WIRE_DATA_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Wire_Data");
const CString LF_LADLE_INFO_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Ladle_Info");

//RH���������
const CString RH_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Unit_Mag");
const CString RH_AREA_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Prod_Area");

//RH����
const CString RH1_UNIT_URI =  _T("XGMESLogic\\RHMag\\CRH_Unit_Mag\\S51");

//RH����ʵ����
const CString RH_BASE_DATA_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Base_Data");
const CString RH_ADDITION_DATA_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Addition_Data");
const CString RH_EQUIPMENT_STATUS_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Equipment_Status");
const CString RH_FEED_DATA_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Feed_Data");
const CString RH_HEATREMARK_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_HeatRemark");
const CString RH_LADLE_WEIGHT_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Ladle_Weight");
const CString RH_OXYGEN_DATA_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Oxygen_Data");
const CString RH_PROCESS_DATA_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Process_Data");
const CString RH_PROCESS_STATUS_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Process_Satus");
const CString RH_TEMP_DATA_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Temp_Data");
const CString RH_WIRE_DATA_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Wire_Data");
const CString RH_LADLE_INFO_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Ladle_Info");

//�������������
const CString CCM_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Unit_Mag");
const CString CCM_AREA_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Prod_Area");

//��������
const CString CCM1_UNIT_URI = _T("XGMESLogic\\CCMMag\\CCCM_Unit_Mag\\S61");
const CString CCM2_UNIT_URI = _T("XGMESLogic\\CCMMag\\CCCM_Unit_Mag\\S62");
const CString CCM3_UNIT_URI = _T("XGMESLogic\\CCMMag\\CCCM_Unit_Mag\\S63");
const CString CCM4_UNIT_URI = _T("XGMESLogic\\CCMMag\\CCCM_Unit_Mag\\S64");
const CString CCM5_UNIT_URI = _T("XGMESLogic\\CCMMag\\CCCM_Unit_Mag\\S65");
//Modify by llj 2011-1-18 ������޸�
const CString CCM7_UNIT_URI = _T("XGMESLogic\\CCMMag\\CCCM_Unit_Mag\\S67");//7#����
//Modify by hyh 2012-05-09 ������޸�
const CString CCM6_UNIT_URI = _T("XGMESLogic\\CCMMag\\CCCM_Unit_Mag\\S66");//6#����

//����ʵ����
const CString CCM_BASE_DATA_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_Base_Data");	
const CString CCM_BLOOM_DATA_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_Bloom_Data");
const CString CCM_CASTING_DATA_CLASS_URI	= _T("XGMESLogic\\CCMMag\\CCCM_Casting_Data");
const CString CCM_CASTING_STRANDINFO_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Casting_StrandInfo");
const CString CCM_EQUIPMENT_STATUS_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Equipment_Status");
const CString CCM_HEAT_COOLING_CLASS_URI	= _T("XGMESLogic\\CCMMag\\CCCM_Heat_Cooling");
const CString CCM_HEAT_COVER_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_Heat_Cover");
const CString CCM_HEAT_ELECSTIRRING_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Heat_ElecStirring");
const CString CCM_HEAT_FAULTYGOODS_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Heat_FaultyGoods");
const CString CCM_HEAT_HOLDTEMPMAT_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Heat_HoldTempMat");
const CString CCM_HEAT_LADLE_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_Heat_Ladle");
const CString CCM_HEAT_MOLD_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_Heat_Mold");
const CString CCM_HEAT_PROTECTCASTING_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Heat_ProtectCasting");
const CString CCM_HEAT_PROTECTMAT_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Heat_ProtectMat");
const CString CCM_HEAT_PROTECTSLAG_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Heat_ProtectSlag");
const CString CCM_HEAT_REMARK_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_Heat_Remark");
const CString CCM_HEAT_SPEED_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_Heat_Speed");
const CString CCM_HEAT_STRANDINFO_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Heat_StrandInfo");
const CString CCM_HEAT_TUNDISHTEMP_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Heat_TundishTemp");
const CString CCM_HEAT_WASTER_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_Heat_Waster");
const CString CCM_MOLD_HEIGHT_CURVE_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Mold_Height_Curve");
const CString CCM_MOLD_INTEMP_CURVE_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Mold_InTemp_Curve");
const CString CCM_MOLD_OUTTEMP_CURVE_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Mold_OutTemp_Curve");
const CString CCM_PLUGBAR_CURVE_CLASS_URI	= _T("XGMESLogic\\CCMMag\\CCCM_PlugBar_Curve");
const CString CCM_PROCESS_DATA_CLASS_URI	= _T("XGMESLogic\\CCMMag\\CCCM_Process_Data");
const CString CCM_PROCESS_STATUS_CLASS_URI	= _T("XGMESLogic\\CCMMag\\CCCM_Process_Status");
const CString CCM_RUNTIME_DATA_CLASS_URI	= _T("XGMESLogic\\CCMMag\\CCCM_Runtime_Data");
const CString CCM_SMOOTHBLOCK_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_SmoothBlock");
const CString CCM_SPEED_CURVE_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_Speed_Curve");
const CString CCM_TEMP_CURVE_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_Temp_Curve");
const CString CCM_TUNDISH_DATA_CLASS_URI	= _T("XGMESLogic\\CCMMag\\CCCM_Tundish_Data");
const CString CCM_TUNDISH_STRANDINFO_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Tundish_StrandInfo");
const CString CCM_WATERGAP_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_WaterGap");
const CString CCM_BIGWATERGAP_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_BigWaterGap");



//������

const CString BLOOM_STORE_CLASS_URI		= _T("XGMESLogic\\BloomStoreMag\\CBloom_Store_Mag");//����������߼���

const CString BLOOM_IN_CLASS_URI		= _T("XGMESLogic\\BloomStoreMag\\CBloom_Input_Log");//�������ʵ��ʵ����
const CString BLOOM_OUT_CLASS_URI		= _T("XGMESLogic\\BloomStoreMag\\CBloom_Output_Log");//��������ʵ��ʵ����
const CString BLOOM_TEL_CLASS_URI		= _T("XGMESLogic\\BloomStoreMag\\CBloom_Tel_Data");//��������ʵ����

const CString BLOOM_STORE_OBJ_URI		= _T("XGMESLogic\\BloomStoreMag\\CBloom_Store_Mag\\S71");//����ԭ�Ͽ�����߼�����
const CString BLOOM_STORE_INCACHE_OBJ_URI   =   _T("XGMESLogic\\BaseDataMag\\XGInterCache\\S71P01");//����ԭ�Ͽ���⻺��
const CString BLOOM_STORE_OUTCACHE_OBJ_URI	=	_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S71N01");//����ԭ�Ͽ������⻺��

//����״̬														   
const CString BLOOM_STATUS_CUT					=_T("6");//01:�ж�	
const CString BLOOM_STATUS_HOT_JUDGE			=_T("7");//02:�ȼ�Ǵ���
const CString BLOOM_STATUS_HOT_WAIT				=_T("8");//02:�ȼ첻������
const CString BLOOM_STATUS_FIN_JUDGE			=_T("9");//03:��һ������
const CString BLOOM_STATUS_DOWN					=_T("10");//03:����
const CString BLOOM_STATUS_INSTORE            	=_T("11");//04:���
const CString BLOOM_STATUS_CHECK				=_T("12");//05:�������
const CString BLOOM_STATUS_COOL_JUDGE           =_T("13");//06:����ж����ٴ����У�
const CString BLOOM_STATUS_OUTSTORE				=_T("14");//07:����


const CString WAITING_FIN_JUDGE = _T("YY000000");


const CString BLOOM_STOCK_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S71A01");	//���������
const CString BLOOM_COOL_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S71B01");	//�����⻺����

//�ϸ�����ԭ�Ͽ�

const CString SCRAP_STORE_CLASS_URI		= _T("XGMESLogic\\ScrapStoreMag\\CScrap_Store_Mag");//�ϸ�ԭ�Ͽ�����߼���
const CString SCRAP_CODE_CLASS_URI		= _T("XGMESLogic\\ScrapStoreMag\\CScrap_Code");//�ϸֱ���ʵ����

const CString SCRAP_IN_CLASS_URI		= _T("XGMESLogic\\ScrapStoreMag\\CScrap_Input_Log");//�ϸ����ʵ��ʵ����
const CString SCRAP_OUT_CLASS_URI		= _T("XGMESLogic\\ScrapStoreMag\\CScrap_Output_Log");//�ϸֳ���ʵ��ʵ����
const CString SCRAP_TRANS_TEL_CLASS_URI		= _T("XGMESLogic\\ScrapStoreMag\\CScrap_Trans_Tel_Data");//�ϸ���ת�����ʵ����
const CString SCRAP_PUR_TEL_CLASS_URI		= _T("XGMESLogic\\ScrapStoreMag\\CScrap_Purchase_Tel_Data");//�ϸ����⹺����ʵ����

//Modify begin by llj 2011-03-22 ���ӷϸֺ���������
const CString SCRAP_OUT_STORE_DETAIL_CLASS_URI		= _T("XGMESLogic\\ScrapStoreMag\\CScrapOutStoreDetail");//�ϸ��������������ϸʵ����
//Modify end


const CString SCRAP_STORE_OBJ_URI		= _T("XGMESLogic\\ScrapStoreMag\\CScrap_Store_Mag\\S82");//�ϸ�ԭ�Ͽ�����߼�����

const CString SCRAP_STORE_INCACHE_OBJ_URI	=	_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S82P01");//�ϸ�ԭ�Ͽ������⻺��

const CString SCRAP_STORE_OUTCACHE_OBJ_URI	=	_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S82N01");//�ϸ�ԭ�Ͽ������⻺��

const CString SCRAP_SCRAP_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S82A01");	//�ϸֿ���
const CString SCRAP_IRON_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S82A02");	//������

//ɢ״��ԭ�Ͽ�

const CString BULK_STORE_CLASS_URI		= _T("XGMESLogic\\BulkStoreMag\\CBulk_Store_Mag");//ɢ״��ԭ�Ͽ�����߼���
const CString BULK_REL_CLASS_URI		= _T("XGMESLogic\\BulkStoreMag\\CBulk_Bulk_Relation");//ɢ״���ϲ����ֶ�Ӧ��ϵʵ����
const CString BULK_CODE_CLASS_URI		= _T("XGMESLogic\\BulkStoreMag\\CBulk_Code");//ɢ״�ϱ���ʵ����
const CString BULK_TRANS_CLASS_URI		= _T("XGMESLogic\\BulkStoreMag\\CBulk_Trans_Log");///ɢ״��ת��ʵ����

const CString BULK_IN_CLASS_URI			= _T("XGMESLogic\\BulkStoreMag\\CBulk_Input_Log");//ɢ״�����ʵ��ʵ����
const CString BULK_OUT_CLASS_URI		= _T("XGMESLogic\\BulkStoreMag\\CBulk_Output_Log");//ɢ״�ϳ���ʵ��ʵ����
const CString BULK_APP_CLASS_URI		= _T("XGMESLogic\\BulkStoreMag\\CBulk_App");//ɢ״��������ʵ����
const CString BULK_PUR_TEL_CLASS_URI	= _T("XGMESLogic\\BulkStoreMag\\CBulk_Purchase_Tel_Data");//ɢ״�ϲɹ�����ʵ����
const CString BULK_TRANS_TEL_CLASS_URI	= _T("XGMESLogic\\BulkStoreMag\\CBulk_Trans_Tel_Data");//ɢ״��ת�����ʵ����


const CString BULK_STORE_OBJ_URI		= _T("XGMESLogic\\BulkStoreMag\\CBulk_Store_Mag\\S83");//ɢ״��ԭ�Ͽ�����߼�����

const CString BULK_STORE_INCACHE_OBJ_URI	=	_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S83P01");//ɢ״��ԭ�Ͽ������⻺��

const CString BULK_STORE_OUTCACHE_OBJ_URI	=	_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S83N01");//ɢ״��ԭ�Ͽ������⻺��
//ɢ״��ԭ�Ͽ�����߼�����
const CString BULK_HIGH_1_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S83A01");	//ɢ״��ԭ�Ͽ�1#ת¯�߲�1#�ϲ�
const CString BULK_HIGH_2_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S83A02");	//ɢ״��ԭ�Ͽ�1#ת¯�߲�2#�ϲ�
const CString BULK_HIGH_3_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S83A03");	//ɢ״��ԭ�Ͽ�1#ת¯�߲�3#�ϲ�
const CString BULK_HIGH_4_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S83A04");	//ɢ״��ԭ�Ͽ�1#ת¯�߲�4#�ϲ�
const CString BULK_HIGH_5_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S83A05");	//ɢ״��ԭ�Ͽ�1#ת¯�߲�5#�ϲ�
const CString BULK_HIGH_6_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S83A06");	//ɢ״��ԭ�Ͽ�1#ת¯�߲�6#�ϲ�
const CString BULK_HIGH_7_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S83A07");	//ɢ״��ԭ�Ͽ�1#ת¯�߲�7#�ϲ�
const CString BULK_HIGH_8_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S83A08");	//ɢ״��ԭ�Ͽ�1#ת¯�߲�8#�ϲ�




//�Ͻ�ԭ�Ͽ�

const CString ALLOY_STORE_CLASS_URI		= _T("XGMESLogic\\AlloyStoreMag\\CAlloy_Store_Mag");//�Ͻ�ԭ�Ͽ�����߼���
const CString ALLOY_REL_CLASS_URI		= _T("XGMESLogic\\AlloyStoreMag\\CAlloy_Bulk_Relation");//�Ͻ��ϲ����ֶ�Ӧ��ϵʵ����
const CString ALLOY_CODE_CLASS_URI		= _T("XGMESLogic\\AlloyStoreMag\\CAlloy_Code");//�Ͻ����ʵ����
const CString ALLOY_TRANS_CLASS_URI		= _T("XGMESLogic\\AlloyStoreMag\\CAlloy_Trans_Log");//�Ͻ�ת��ʵ����

const CString ALLOY_IN_CLASS_URI		= _T("XGMESLogic\\AlloyStoreMag\\CAlloy_Input_Log");//�Ͻ����ʵ��ʵ����
const CString ALLOY_OUT_CLASS_URI		= _T("XGMESLogic\\AlloyStoreMag\\CAlloy_Output_Log");//�Ͻ����ʵ��ʵ����
const CString ALLOY_APP_CLASS_URI		= _T("XGMESLogic\\AlloyStoreMag\\CAlloy_App");//�Ͻ�������ʵ����
const CString ALLOY_TRANS_TEL_CLASS_URI		= _T("XGMESLogic\\AlloyStoreMag\\CAlloy_Trans_Tel_Data");//�Ͻ��ϵ���ʵ����
const CString ALLOY_ELEMENT_TEL_CLASS_URI  = _T("XGMESLogic\\AlloyStoreMag\\CAlloy_Element_Tel_Data");//�Ͻ��ϵ���ʵ����


const CString ALLOY_STORE_OBJ_URI		= _T("XGMESLogic\\AlloyStoreMag\\CAlloy_Store_Mag\\S81");//�Ͻ�ԭ�Ͽ�����߼�����

const CString ALLOY_STORE_INCACHE_OBJ_URI	=	_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S81P01");//�Ͻ�ԭ�Ͽ������⻺��

const CString ALLOY_STORE_OUTCACHE_OBJ_URI	=	_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S81N01");//�Ͻ�ԭ�Ͽ������⻺��
//�Ͻ�ԭ�Ͽ�����߼�����
const CString ALLOY_HIGH_1_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81A01");	//�Ͻ�ԭ�Ͽ�1#ת¯�߲�1#�ϲ�
const CString ALLOY_HIGH_2_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81A02");	//�Ͻ�ԭ�Ͽ�1#ת¯�߲�2#�ϲ�
const CString ALLOY_HIGH_3_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81A03");	//�Ͻ�ԭ�Ͽ�1#ת¯�߲�3#�ϲ�
const CString ALLOY_HIGH_4_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81A04");	//�Ͻ�ԭ�Ͽ�1#ת¯�߲�4#�ϲ�
const CString ALLOY_HIGH_5_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81A05");	//�Ͻ�ԭ�Ͽ�1#ת¯�߲�5#�ϲ�
const CString ALLOY_HIGH_6_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81A06");	//�Ͻ�ԭ�Ͽ�1#ת¯�߲�6#�ϲ�
const CString ALLOY_HIGH_7_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81A07");	//�Ͻ�ԭ�Ͽ�1#ת¯�߲�7#�ϲ�
const CString ALLOY_HIGH_8_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81A08");	//�Ͻ�ԭ�Ͽ�1#ת¯�߲�8#�ϲ�

//�濾¯
const CString ALLOY_HOT_1_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B01");	//�Ͻ�ԭ�Ͽ�濾¯1#�ϲ�
const CString ALLOY_HOT_2_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B02");	//�Ͻ�ԭ�Ͽ�濾¯2#�ϲ�
const CString ALLOY_HOT_3_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B03");	//�Ͻ�ԭ�Ͽ�濾¯3#�ϲ�
const CString ALLOY_HOT_4_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B04");	//�Ͻ�ԭ�Ͽ�濾¯4#�ϲ�
const CString ALLOY_HOT_5_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B05");	//�Ͻ�ԭ�Ͽ�濾¯5#�ϲ�
const CString ALLOY_HOT_6_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B06");	//�Ͻ�ԭ�Ͽ�濾¯6#�ϲ�
const CString ALLOY_HOT_7_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B07");	//�Ͻ�ԭ�Ͽ�濾¯7#�ϲ�
const CString ALLOY_HOT_8_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B08");	//�Ͻ�ԭ�Ͽ�濾¯8#�ϲ�
const CString ALLOY_HOT_9_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B09");	//�Ͻ�ԭ�Ͽ�濾¯9#�ϲ�
const CString ALLOY_HOT_10_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B10");	//�Ͻ�ԭ�Ͽ�濾¯10#�ϲ�
const CString ALLOY_HOT_11_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B11");	//�Ͻ�ԭ�Ͽ�濾¯11#�ϲ�
const CString ALLOY_HOT_12_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B12");	//�Ͻ�ԭ�Ͽ�濾¯12#�ϲ�
const CString ALLOY_HOT_13_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B13");	//�Ͻ�ԭ�Ͽ�濾¯13#�ϲ�
const CString ALLOY_HOT_14_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B14");	//�Ͻ�ԭ�Ͽ�濾¯14#�ϲ�
const CString ALLOY_HOT_15_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B15");	//�Ͻ�ԭ�Ͽ�濾¯15#�ϲ�
const CString ALLOY_HOT_16_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B16");	//�Ͻ�ԭ�Ͽ�濾¯16#�ϲ�
const CString ALLOY_HOT_17_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B17");	//�Ͻ�ԭ�Ͽ�濾¯17#�ϲ�
const CString ALLOY_HOT_18_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B18");	//�Ͻ�ԭ�Ͽ�濾¯18#�ϲ�

//1#LF¯�߲�
const CString ALLOY_1LF_1_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81C01");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�1#�ϲ�
const CString ALLOY_1LF_2_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81C02");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�2#�ϲ�
const CString ALLOY_1LF_3_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81C03");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�3#�ϲ�
const CString ALLOY_1LF_4_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81C04");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�4#�ϲ�
const CString ALLOY_1LF_5_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81C05");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�5#�ϲ�
const CString ALLOY_1LF_6_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81C06");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�6#�ϲ�
const CString ALLOY_1LF_7_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81C07");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�7#�ϲ�
const CString ALLOY_1LF_8_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81C08");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�8#�ϲ�
const CString ALLOY_1LF_9_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81C09");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�9#�ϲ�
const CString ALLOY_1LF_10_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81C10");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�10#�ϲ�

//2#LF¯�߲�
const CString ALLOY_2LF_1_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81D01");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�1#�ϲ�
const CString ALLOY_2LF_2_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81D02");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�2#�ϲ�
const CString ALLOY_2LF_3_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81D03");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�3#�ϲ�
const CString ALLOY_2LF_4_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81D04");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�4#�ϲ�
const CString ALLOY_2LF_7_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81D05");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�5#�ϲ�
const CString ALLOY_2LF_6_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81D06");	//�Ͻ�ԭ�Ͽ�1#LF¯�߲�6#�ϲ�

//3#LF1#RH¯���ø߲�
const CString ALLOY_12LF_1_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E01");	//�Ͻ�ԭ�Ͽ⹫�ø߲�1#�ϲ�
const CString ALLOY_12LF_2_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E02");	//�Ͻ�ԭ�Ͽ⹫�ø߲�2#�ϲ�
const CString ALLOY_12LF_3_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E03");	//�Ͻ�ԭ�Ͽ⹫�ø߲�3#�ϲ�
const CString ALLOY_12LF_4_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E04");	//�Ͻ�ԭ�Ͽ⹫�ø߲�4#�ϲ�
const CString ALLOY_12LF_5_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E05");	//�Ͻ�ԭ�Ͽ⹫�ø߲�5#�ϲ�
const CString ALLOY_12LF_6_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E06");	//�Ͻ�ԭ�Ͽ⹫�ø߲�6#�ϲ�
const CString ALLOY_12LF_7_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E08");	//�Ͻ�ԭ�Ͽ⹫�ø߲�7#�ϲ�
const CString ALLOY_12LF_8_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E09");	//�Ͻ�ԭ�Ͽ⹫�ø߲�7#�ϲ�
const CString ALLOY_12LF_9_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E010");	//�Ͻ�ԭ�Ͽ⹫�ø߲�7#�ϲ�
const CString ALLOY_12LF_10_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E011");	//�Ͻ�ԭ�Ͽ⹫�ø߲�7#�ϲ�
const CString ALLOY_12LF_11_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E012");	//�Ͻ�ԭ�Ͽ⹫�ø߲�7#�ϲ�
const CString ALLOY_12LF_12_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E013");	//�Ͻ�ԭ�Ͽ⹫�ø߲�7#�ϲ�
const CString ALLOY_12LF_13_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E014");	//�Ͻ�ԭ�Ͽ⹫�ø߲�7#�ϲ�
const CString ALLOY_12LF_14_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E015");	//�Ͻ�ԭ�Ͽ⹫�ø߲�7#�ϲ�
const CString ALLOY_12LF_15_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E016");	//�Ͻ�ԭ�Ͽ⹫�ø߲�7#�ϲ�
const CString ALLOY_12LF_16_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E017");	//�Ͻ�ԭ�Ͽ⹫�ø߲�7#�ϲ�
const CString ALLOY_12LF_17_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E018");	//�Ͻ�ԭ�Ͽ⹫�ø߲�7#�ϲ�
const CString ALLOY_12LF_18_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E019");	//�Ͻ�ԭ�Ͽ⹫�ø߲�7#�ϲ�
const CString ALLOY_12LF_19_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E020");	//�Ͻ�ԭ�Ͽ⹫�ø߲�7#�ϲ�

//������

//����ʵ����URI
const CString CIRONLADLE_BASE_URI	= _T("XGMESLogic\\IronLadleMag\\CIronLadle_Base");
const CString CIRONLADLE_FIRE_URI	= _T("XGMESLogic\\IronLadleMag\\CIronLadle_Fire");
const CString CIRONLADLE_TIE_URI	= _T("XGMESLogic\\IronLadleMag\\CIronLadle_Tie");
const CString CIRONLADLE_USE_URI	= _T("XGMESLogic\\IronLadleMag\\CIronLadle_Use");

//����״̬
const CString CIRONLADLE_STATUS_TIE				= _T("01");//���
const CString CIRONLADLE_STATUS_COLD			= _T("02");//�䱸
const CString CIRONLADLE_STATUS_SMALL_FIRE		= _T("03");//С��
const CString CIRONLADLE_STATUS_MIDDLE_FIRE		= _T("04");//�л�
const CString CIRONLADLE_STATUS_BIG_FIRE		= _T("05");//���
const CString CIRONLADLE_STATUS_HOT				= _T("06");//�ȱ�
const CString CIRONLADLE_STATUS_DISTRIBUTE		= _T("07");//�ѷ���
const CString CIRONLADLE_STATUS_USE				= _T("08");//ʹ��
const CString CIRONLADLE_STATUS_SUSPEND			= _T("09");//ͣ��
const CString CIRONLADLE_STATUS_OFFLINE			= _T("10");//���ߴ���

//��������ԭ��
const CString CIRONLADLE_STOPREASON_DREG		= _T("01");//01:����ճ������,����ճ��
const CString CIRONLADLE_STOPREASON_TEMP		= _T("02");//02:���ڻ�����¶ȹ���

//�а�ʵ����URI
const CString CTUNDISH_BASE_URI				= _T("XGMESLogic\\TundishMag\\CTundish_Base");
const CString CTUNDISH_DAUB_URI				= _T("XGMESLogic\\TundishMag\\CTundish_Daub");
const CString CTUNDISH_INNER_BUILD_URI		= _T("XGMESLogic\\TundishMag\\CTundish_Inner_Build");
const CString CTUNDISH_INNER_FIRE_URI		= _T("XGMESLogic\\TundishMag\\CTundish_Inner_Fire");
const CString CTUNDISH_OT_HOT_FIRE_URI		= _T("XGMESLogic\\TundishMag\\CTundish_OT_Hot_Fire");
const CString CTUNDISH_OT_INSTALL_URI		= _T("XGMESLogic\\TundishMag\\CTundish_OT_Install");
const CString CTUNDISH_OT_REFRA_USE_URI		= _T("XGMESLogic\\TundishMag\\CTundish_OT_Refra_Use");
const CString CTUNDISH_TFF_INSTALL_URI		= _T("XGMESLogic\\TundishMag\\CTundish_TFF_Install");
const CString CTUNDISH_TFF_HOT_FIRE_URI		= _T("XGMESLogic\\TundishMag\\CTundish_TFF_Hot_Fire");
const CString CTUNDISH_TFF_REFRA_USE_URI	= _T("XGMESLogic\\TundishMag\\CTundish_TFF_Refra_Use");
const CString CTUNDISH_USE_INFO_URI			= _T("XGMESLogic\\TundishMag\\CTundish_Use_Info");

//�а�״̬
const CString CTUNDISH_STATUS_INNER_BUILD	= _T("01");//���ò�����
const CString CTUNDISH_STATUS_INNER_FIRE	= _T("02");//���ò�濾
const CString CTUNDISH_STATUS_WORK_DAUB 	= _T("03");//����������(���)
const CString CTUNDISH_STATUS_WORK_FIRE		= _T("04");//������濾
const CString CTUNDISH_STATUS_COLD			= _T("05");//�䱸
const CString CTUNDISH_STATUS_ISTALL		= _T("06");//�а��ϼ�
const CString CTUNDISH_STATUS_HOT_FIRE		= _T("07");//�ȱ��濾
const CString CTUNDISH_STATUS_HOT			= _T("08");//�ȱ�
const CString CTUNDISH_STATUS_USE			= _T("09");//ʹ��(��ת)
const CString CTUNDISH_STATUS_OFFLINE		= _T("10");//���ߴ���

//���а�������û��ʵ�������ò��Ż��������ŵĻ�ȡ����
const CString CTUNDISH_GET_TYPE_INNER_TIE		= _T("01");//���ò�����:���ò���
const CString CTUNDISH_GET_TYPE_INNER_FIRE		= _T("02");//���ò�濾:���ò���
const CString CTUNDISH_GET_TYPE_WORK_TIE 		= _T("03");//����������(���):��������
const CString CTUNDISH_GET_TYPE_OT_HOT_FIRE		= _T("14");//1��2#�����ȱ��濾:��������
const CString CTUNDISH_GET_TYPE_TFF_HOT_FIRE	= _T("24");//3��4��5#�����ȱ��濾:��������



//�ְ�ʵ����URI
const CString CLADLE_BASE_URI				= _T("XGMESLogic\\LadleMag\\CLadle_Base");
const CString CLADLE_PLAN_URI				= _T("XGMESLogic\\LadleMag\\CLadle_Plan");
const CString CLADLE_MAG_OBJ_URI			= _T("XGMESLogic\\LadleMag\\CLadle_Mag");
const CString CLADLE_IN_BUILD_URI			= _T("XGMESLogic\\LadleMag\\CLadle_In_Build");
const CString CLADLE_COM_TIE_URI			= _T("XGMESLogic\\LadleMag\\CLadle_Com_Tie");
const CString CLADLE_COM_LAD_REP_URI		= _T("XGMESLogic\\LadleMag\\CLadle_Com_Lad_Rep");
const CString CLADLE_FIN_BUILD_URI			= _T("XGMESLogic\\LadleMag\\CLadle_Fin_Build");
const CString CLADLE_CHA_DRE_LIN_URI		= _T("XGMESLogic\\LadleMag\\CLadle_Cha_Dre_Lin");
const CString CLADLE_USE_URI				= _T("XGMESLogic\\LadleMag\\CLadle_Use");
const CString CLADLE_FIRE_URI				= _T("XGMESLogic\\LadleMag\\CLadle_Fire");
const CString CLADLE_POUR_URI				= _T("XGMESLogic\\LadleMag\\CLadle_Pour");
const CString CLADLE_FOLD_URI				= _T("XGMESLogic\\LadleMag\\CLadle_Fold");//
const CString CLADLE_PROCESS_URI			= _T("XGMESLogic\\LadleMag\\CLadle_Process");

//�ְ�״̬
const CString CLADLE_STATUS_INNER_BUILD		= _T("01");//���ò���������ᣩ
const CString CLADLE_STATUS_INNER_FIRE		= _T("02");//���ò�濾
const CString CLADLE_STATUS_WORK_DAUB 		= _T("03");//��������������ᣩ
const CString CLADLE_STATUS_WORK_FIRE		= _T("04");//������濾
const CString CLADLE_STATUS_COLD			= _T("05");//�䱸
const CString CLADLE_STATUS_HOT_FIRE		= _T("06");//�ȱ��濾
const CString CLADLE_STATUS_HOT				= _T("07");//�ȱ�
const CString CLADLE_STATUS_DESIGN			= _T("08");//����
const CString CLADLE_STATUS_USE				= _T("09");//ʹ��(��ת)
const CString CLADLE_STATUS_OFFLINE			= _T("10");//���ߴ���


//�ְ��ƻ�״̬
const CString CLADLE_PLAN_STATUS_UNDESIGN	= _T("01");//δ����
const CString CLADLE_PLAN_STATUS_DESIGN		= _T("02");//����
const CString CLADLE_PLAN_STATUS_EXCUTING 	= _T("03");//ִ��
const CString CLADLE_STATUS_WORK_EXCUTED	= _T("04");//ִ�н���

//��ǹʵ����
const CString CLANCE_BASE_URI				= _T("XGMESLogic\\LanceMag\\CLance_Base");// 
const CString CLANCE_MAKE_URI				= _T("XGMESLogic\\LanceMag\\CLance_Make");//
const CString CLANCE_DEFEND_URI				= _T("XGMESLogic\\LanceMag\\CLance_Defend");//
const CString CLANCE_CHECK_URI				= _T("XGMESLogic\\LanceMag\\CLance_Check");//
const CString CLANCE_IN_YARD_URI			= _T("XGMESLogic\\LanceMag\\CLance_In_Yard");//
const CString CLANCE_OUT_YARD_URI			= _T("XGMESLogic\\LanceMag\\CLance_Out_Yard");//
const CString CLANCE_USE_URI				= _T("XGMESLogic\\LanceMag\\CLance_Use");// 
const CString CLANCE_MAG_URI				= _T("XGMESLogic\\LanceMag\\CLance_Mag");//

//��ǹ״̬
const CString CLANCE_STATUS_REPAIR			= _T("01");//���� 
const CString CLANCE_STATUS_FREE			= _T("02");//����
const CString CLANCE_STATUS_USE				= _T("03");//ʹ��
const CString CLANCE_STATUS_CHECK			= _T("04");//���
const CString CLANCE_STATUS_OFFLINE			= _T("05");//���ߴ���

//��ǹ��ǹԭ��
const CString CLANCE_CHANGE_WIDE			= _T("01");//��ճ��������ɵ�ǹ��(�޷�ͨ�����ߴ�������) 
const CString CLANCE_CHANGE_LEAK			= _T("02");//���켰ǹͷ©
const CString CLANCE_CHANGE_ERODE			= _T("03");//ǹͷ��ʴ����(�������ݴ���5mm)�����ڱ���
const CString CLANCE_CHANGE_EFFICIENCY		= _T("04");//����Ч����

//��չ�ʵ����
const CString CVACTUBE_BASE_URI				= _T("XGMESLogic\\VacTubeMag\\CVacTube_Base");
const CString CVACTUBE_BUILD_URI			= _T("XGMESLogic\\VacTubeMag\\CVacTube_Build");
const CString CVACTUBE_REPAIR_URI			= _T("XGMESLogic\\VacTubeMag\\CVacTube_Repair");
const CString CVACTUBE_USE_URI				= _T("XGMESLogic\\VacTubeMag\\CVacTube_Use");
const CString CVACTUBE_USE_INFO_URI			= _T("XGMESLogic\\VacTubeMag\\CVacTube_Use_Info");
//const CString CVACTUBE_CIR_INSTALL_URI		= _T("XGMESLogic\\VacTubeMag\\CVacTube_Cir_Install");
const CString CVACTUBE_HOT_SYP_BUI_URI		= _T("XGMESLogic\\VacTubeMag\\CVacTube_Hot_Syp_Bui");
const CString CVACTUBE_HOT_SYP_REPAIR_URI	= _T("XGMESLogic\\VacTubeMag\\CVacTube_Hot_Syp_Repair");
const CString CVACTUBE_HOT_SYP_USE_URI		= _T("XGMESLogic\\VacTubeMag\\CVacTube_Hot_Syp_Use");
//const CString CVACTUBE_SOA_CIR_USE_URI		= _T("XGMESLogic\\VacTubeMag\\CVacTube_Soa_Cir_Use");
const CString CVACTUBE_FIRE_URI				= _T("XGMESLogic\\VacTubeMag\\CVacTube_Fire");
const CString CVACTUBE_FIRE_INFO_URI		= _T("XGMESLogic\\VacTubeMag\\CVacTube_Fire_Info");
const CString CVACTUBE_MAG_URI				= _T("XGMESLogic\\VacTubeMag\\CVacTube_Mag");


//��ղ�״̬
const CString CVACTUBE_STATUS_REPAIR		= _T("01");//ά��
const CString CVACTUBE_STATUS_COLD			= _T("02");//�䱸
const CString CVACTUBE_STATUS_PRE_FIRE		= _T("03");//Ԥ��
const CString CVACTUBE_STATUS_BIG_FIRE		= _T("04");//���
const CString CVACTUBE_STATUS_HOT			= _T("05");//�ȱ�
const CString CVACTUBE_STATUS_USE			= _T("06");//ʹ��
const CString CVACTUBE_STATUS_CHECK			= _T("07");//���߼��
const CString CVACTUBE_STATUS_OFFLINE		= _T("08");//���ߴ���

//��ղ�����ԭ��
const CString CVACTUBE_OFF_SOA_ERODE		= _T("01");//���չ���ʴ����
const CString CVACTUBE_OFF_SOA_BRICK		= _T("02");//���չܵ�ש
const CString CVACTUBE_OFF_SOA_WIDE 		= _T("03");//���չ�ճ��
const CString CVACTUBE_OFF_CIR_ERODE		= _T("04");//��������ʴ����
const CString CVACTUBE_OFF_DOWN_BRICK		= _T("05");//�²��۵�ש
const CString CVACTUBE_OFF_DOWN_RED			= _T("06");//�²��۷���
const CString CVACTUBE_OFF_DOWN_LEAK		= _T("07");//�²��۴���
const CString CVACTUBE_OFF_DEMAND			= _T("08");//���������Ų�����
const CString CVACTUBE_OFF_OTHER			= _T("09");//����

//��ղ�λ��
const CString CVACTUBE_POSITION_BUILD		= _T("1");//����λ
const CString CVACTUBE_POSITION_FIRE_A		= _T("2");//A�濾λ
const CString CVACTUBE_POSITION_FIRE_B 		= _T("3");//B�濾λ
const CString CVACTUBE_POSITION_WORK_A		= _T("A");//A��λ
const CString CVACTUBE_POSITION_WORK_B		= _T("B");//B��λ


//�ᾧ��ʵ����
const CString CMOLD_BASE_URI				= _T("XGMESLogic\\MoldMag\\CMold_Base");
const CString CMOLD_PIPE_INSTALL_URI		= _T("XGMESLogic\\MoldMag\\CMold_Pipe_Install");
const CString CMOLD_BOARD_INSTALL_URI		= _T("XGMESLogic\\MoldMag\\CMold_Board_Install");
const CString CMOLD_PIPE_PAR_USEI_URI		= _T("XGMESLogic\\MoldMag\\CMold_Pipe_Par_Use");
const CString CMOLD_BOARD_PAR_USE_URI		= _T("XGMESLogic\\MoldMag\\CMold_Board_Par_Use");
const CString CMOLD_MOLD_URI				= _T("XGMESLogic\\MoldMag\\CMold_Mag");

//�ᾧ��״̬
const CString CMOLD_STATUS_WAIT				= _T("01");//��װ  
const CString CMOLD_STATUS_REPAIR			= _T("02");//װ�� 
const CString CMOLD_STATUS_FREE				= _T("03");//����
const CString CMOLD_STATUS_USE				= _T("04");//����
const CString CMOLD_STATUS_OFFLINE			= _T("05");//���߼��

//�ᾧ������ԭ��
const CString CCMOLD_OFF_PLAN				= _T("01");//�ƻ�
const CString CCMOLD_OFF_WEAL				= _T("02");//ĥ��
const CString CCMOLD_OFF_LEAK_STEEL 		= _T("03");//©��
const CString CCMOLD_OFF_TRIPE				= _T("04");//�ѷ��Ķ�
const CString CCMOLD_OFF_SCRATCH			= _T("05");//����
const CString CCMOLD_OFF_TUBE				= _T("06");//ͭ�ܰ�͹
const CString CCMOLD_OFF_LEAK_WATER			= _T("07");//©ˮ
const CString CCMOLD_OFF_SIZE				= _T("08");//���¿ڳߴ粻��
const CString CCMOLD_OFF_OTHER				= _T("09");//����


//����ʵ����
const CString CDES_BASE_URI				    = _T("XGMESLogic\\DeSMag\\CDeS_Base_Data");
const CString CDES_PROCESS_URI				= _T("XGMESLogic\\DeSMag\\CDeS_Process_Data");
const CString CDES_ADDITION_URI				= _T("XGMESLogic\\DeSMag\\CDeS_Addition_Data");
const CString CDES_EQUIPMENT_URI			= _T("XGMESLogic\\DeSMag\\CDeS_Equipment_Status");
const CString CDES_STATUS_URI				= _T("XGMESLogic\\DeSMag\\CDeS_Process_Status");
const CString CDES_RUNTIME_URI				= _T("XGMESLogic\\DeSMag\\CDeS_Runtime_Data");
const CString CDES_LANCEDATA_URI			= _T("XGMESLogic\\DeSMag\\CDeS_Lance_Data");
const CString CDES_LANCELOG_URI			= _T("XGMESLogic\\DeSMag\\CDeS_Lance_Log");
//DES���������
const CString DES_CLASS_URI                 = _T("XGMESLogic\\DeSMag\\CDeS_Unit_Mag");
const CString DES_AREA_CLASS_URI            = _T("XGMESLogic\\DeSMag\\CDeS_Prod_Area");

//����ʵ����
const CString CDEP_BASE_URI				    = _T("XGMESLogic\\DePMag\\CDEP_Base_Data");
const CString CDEP_PROCESS_URI				= _T("XGMESLogic\\DePMag\\CDEP_Process_Data");
const CString CDEP_ADDITION_URI				= _T("XGMESLogic\\DePMag\\CDEP_Addition_Data");
const CString CDEP_EQUIPMENT_URI			= _T("XGMESLogic\\DePMag\\CDEP_Equipment_Status");
const CString CDEP_STATUS_URI				= _T("XGMESLogic\\DePMag\\CDEP_Process_Status");
const CString CDEP_RUNTIME_URI				= _T("XGMESLogic\\DePMag\\CDEP_Runtime_Data");

//DEP���������
const CString DEP_CLASS_URI                 = _T("XGMESLogic\\DePMag\\CDEP_Unit_Mag");
const CString DEP_AREA_CLASS_URI            = _T("XGMESLogic\\DePMag\\CDEP_Prod_Area");




//���ඨ��ļƻ�״̬���������䷢����ͻ
//enum ProducePlanStatus
//{
//	Unknown = 0,			// �ƻ�״̬δ֪�����ܽ����κκϷ��Ĳ���
//	Editing = 1,			// �ƻ����ڱ༭�������´��ִ�С�
//	Created = 2,			// �ƻ��Ѿ����ɣ����Խ��к���������
//	Confirmed = 3,			// �ƻ��Ѿ�ȷ�ϣ����ںϷ���Ч�ļƻ��ˡ�
//	Canceled = 4,			// �ƻ��Ѿ�ȡ����
//	Assigned = 5,			// �ƻ��Ѿ��´��ִ�в��š�
//	Executing = 6,			// �ƻ��Ѿ���ʼִ�С�
//	Paused = 7,				// �ƻ��Ѿ���ִͣ�С�
//	Executed = 8,			// �ƻ��Ѿ�ִ����ϡ�
//	Completed = 9,			// �ƻ��Ѿ�������������Ч��
//};


//�ƻ�����״̬
//const CString PLAN_ORDER_STATUS_UNCONFIRM           =_T("10");//00:δȷ��
const CString PLAN_ORDER_STATUS_UNINTEGRATE         =_T("11");//01:δ�Ų�
//const CString PLAN_ORDER_STATUS_INTEGRATED          =_T("12");//02:���ճ�
const CString PLAN_ORDER_STATUS_CASTING            	=_T("13");//03:�������ּƻ�
const CString PLAN_ORDER_STATUS_TAPPING             =_T("14");//04:�������ּƻ�
const CString PLAN_ORDER_STATUS_EXCUTING            =_T("15");//05:ִ��
const CString PLAN_ORDER_STATUS_EXCUTED             =_T("16");//06:ִ�����

//���ּƻ�״̬
const CString CASTING_PLAN_STATUS_UNSCHEDULING      =_T("10");//01:δ�Ų�
const CString CASTING_PLAN_STATUS_SCHEDULED			=_T("11");//02:���Ų�
const CString CASTING_PLAN_STATUS_EXCUTING			=_T("12");//03:ִ��
const CString CASTING_PLAN_STATUS_EXCUTED           =_T("13");//04:ִ�����


//���ּƻ�״̬
const CString TAPPING_PLAN_STATUS_UNSEND			=_T("10");//01:δ�´�
const CString TAPPING_PLAN_STATUS_SEND				=_T("11");//02:���´�
const CString TAPPING_PLAN_STATUS_EXCUTING			=_T("12");//03:ִ��
const CString TAPPING_PLAN_STATUS_EXCUTED           =_T("13");//04:ִ�����


//���ּƻ�ת¯״̬
const CString TAPPING_PLAN_BOF_STATUS_UNEXCUTING	=_T("01");//01:δִ��
const CString TAPPING_PLAN_BOF_STATUS_IRON			=_T("02");//02:����
const CString TAPPING_PLAN_BOF_STATUS_BLOW			=_T("03");//03:������ʼ
const CString TAPPING_PLAN_BOF_STATUS_TAPPING		=_T("04");//03:���ֿ�ʼ
const CString TAPPING_PLAN_BOF_STATUS_TAPPED        =_T("05");//04:���ֽ���


//���ּƻ�¯��״̬
const CString TAPPING_PLAN_SIDE_STATUS_UNEXCUTING		=_T("01");//01:δִ��
const CString TAPPING_PLAN_SIDE_STATUS_BEGIN			=_T("02");//02:����ʼ
const CString TAPPING_PLAN_SIDE_STATUS_END				=_T("03");//03:�������


//���ּƻ�LF¯״̬
const CString TAPPING_PLAN_LF_STATUS_UNEXCUTING		=_T("01");//01:δִ��
const CString TAPPING_PLAN_LF_STATUS_ARR			=_T("02");//02:��վ
const CString TAPPING_PLAN_LF_STATUS_BEGIN			=_T("03");//03:����ʼ
const CString TAPPING_PLAN_LF_STATUS_END			=_T("04");//04:�������
const CString TAPPING_PLAN_LF_STATUS_LEAVE			=_T("05");//05:��վ


//���ּƻ�RH¯״̬
const CString TAPPING_PLAN_RH_STATUS_UNEXCUTING		=_T("01");//01:δִ��
const CString TAPPING_PLAN_RH_STATUS_ARR			=_T("02");//02:��վ
const CString TAPPING_PLAN_RH_STATUS_BEGIN			=_T("03");//03:����ʼ
const CString TAPPING_PLAN_RH_STATUS_END			=_T("04");//04:�������
const CString TAPPING_PLAN_RH_STATUS_LEAVE			=_T("05");//05:��վ

//���ּƻ�����״̬
const CString TAPPING_PLAN_CCM_STATUS_UNEXCUTING	=_T("01");//01:δִ��
const CString TAPPING_PLAN_CCM_STATUS_ARR			=_T("02");//02:�������
const CString TAPPING_PLAN_CCM_STATUS_BEGIN			=_T("03");//03:�������
const CString TAPPING_PLAN_CCM_STATUS_END			=_T("04");//03:��ע����


//�����߲������
const CString IRONLADLE_FAC					=_T("IronLadleF");//����
const CString LANCE_FAC						=_T("Lance");//��ǹ
const CString LADLE_FAC						=_T("Ladle");//�ְ�
const CString VACTUBE_FAC					=_T("VacTube");//��չ�
const CString TUNDISH_FAC					=_T("Tundish");//�а�
const CString MOLD_FAC						=_T("Mold");//�ᾧ��

//����ȡ���ص�����
const CString MIF_SAMPLE_TYPE = _T("H");//����¯ȡ��
const CString BOF_SAMPLE_TYPE = _T("Z");//ת¯ȡ��
const CString LF_SAMPLE_TYPE  = _T("F");//LF¯ȡ��
const CString RH_SAMPLE_TYPE  = _T("R");//RH¯ȡ��
const CString CCM_SAMPLE_TYPE = _T("C");//����ȡ��
								
//�����������QA_Sample_Type
const CString QA_Sample_Type_ZF = _T("ZF");//LF������
const CString QA_Sample_Type_ZR = _T("ZR");//RH������
const CString QA_Sample_Type_ZL = _T("ZL");//�����а�����
const CString QA_Sample_Type_ZZ = _T("ZZ");//ת¯����
const CString QA_Sample_Type_GL = _T("GL");//�����а���
const CString QA_Sample_Type_TS = _T("TS");//������[����û����]
const CString QA_Sample_Type_TC = _T("TC");//�����ˮ��
const CString QA_Sample_Type_TH = _T("TH");//����¯��
const CString QA_Sample_Type_GZ = _T("GZ");//¯����
const CString QA_Sample_Type_GN = _T("GN");//������
const CString QA_Sample_Type_GG = _T("GG");//������
const CString QA_Sample_Type_GP = _T("GP");//��Ʒ��
const CString QA_Sample_Type_GE = _T("GE");//����
const CString QA_Sample_Type_GQ = _T("GQ");//������
const CString QA_Sample_Type_GD = _T("GD");//�����ͱ���
const CString QA_Sample_Type_TA = _T("TA");//���޻���¯ȫ����2009-04-11
const CString QA_Sample_Type_ZG = _T("ZG");//������2009-04-11
								  
//���������ص�QA_Sample_Addr			  
const CString QA_Sample_Addr_H1 = _T("H1");	//1#����¯	
const CString QA_Sample_Addr_H2 = _T("H2");	//2#����¯

const CString QA_Sample_Addr_TB = _T("TB");	//����
const CString QA_Sample_Addr_TC = _T("TC");	//����
const CString QA_Sample_Addr_Z1 = _T("Z1");	//1#ת¯	
const CString QA_Sample_Addr_Z2 = _T("Z2");	//2#ת¯	
const CString QA_Sample_Addr_Z3 = _T("Z3");	//3#ת¯	
const CString QA_Sample_Addr_Z4 = _T("Z4");	//4#ת¯	
const CString QA_Sample_Addr_F1 = _T("F1");	//1#LF¯	
const CString QA_Sample_Addr_F2 = _T("F2");	//2#LF¯	
const CString QA_Sample_Addr_F3 = _T("F3");	//3#LF¯
//Modify by llj 2011-1-18 ������޸�
const CString QA_Sample_Addr_F5 = _T("F5");	//5#LF¯
//Modify by hyh 2012-05-09 ������޸�
const CString QA_Sample_Addr_F4 = _T("F4");	//4#LF¯

const CString QA_Sample_Addr_R1 = _T("R1");	//1RH¯
const CString QA_Sample_Addr_C1 = _T("C1");	//1#����	
const CString QA_Sample_Addr_C2 = _T("C2");	//2#����	
const CString QA_Sample_Addr_C3 = _T("C3");	//3#����	
const CString QA_Sample_Addr_C4 = _T("C4");	//4#����	
const CString QA_Sample_Addr_C5 = _T("C5");	//5#����
//Modify by llj 2011-1-18 ������޸�
const CString QA_Sample_Addr_C7 = _T("C7");	//7#����	
//Modify by hyh 2012-05-09 ������޸�
const CString QA_Sample_Addr_C6 = _T("C6");	//6#����
										
//���ඨ��Ĳ���״̬���������䷢����ͻ	
//enum MaterialStatus
//{
//	Unknown=0,	//δ֪����״̬
//	Normal=1,	//������
//	Blocked=2,	//���ϱ���ա�
//	Lost=3,		//���϶�ʧ��
//	Outputted=4,//�����Ѿ���������Ѿ��۳�������Ϊ��Ʒ������
//	Deleted=5,	//���ϱ�ɾ����ϵͳ�Բ��ϵ�ɾ����������״̬��ǣ�����Ϊ�����ݰ�ȫ��
//};

//����״̬
const CString COIL_STATUS_UNSEND            		=_T("6");//0:�ƻ�δ�´�
const CString COIL_STATUS_L1            			=_T("7");//1:�ƻ��´�
const CString COIL_STATUS_FEED            			=_T("8");//2:װ¯
const CString COIL_STATUS_PROD            			=_T("9");//3:����
const CString COIL_STATUS_HOTBEGIN              	=_T("10");//4:���ȿ�ʼ
const CString COIL_STATUS_HOTEND              		=_T("11");//5:���Ƚ���
const CString COIL_STATUS_COLDBEGIN              	=_T("12");//6:��ȴ��ʼ
const CString COIL_STATUS_COLDEND	             	=_T("13");//7:��ȴ����
const CString COIL_STATUS_END						=_T("14");//8:��������
const CString COIL_STATUS_DEVLIVERY					=_T("15");//8:��¯

//���涨����ת¯��ˮ׼����������ʼ����
const double BOF_PREPARED_TIME = 5;						//��

const double BOF_TAPPING_TIME = 11;						//��

//���涨��������׼��ʱ�䳣��
const double CASTING_WAITED_TIME = 5;
//��
//Modify begin by llj 2011-1-18 ������޸ģ���14��Ϊ16
//��SAMPLE_ADDR���_T("F5")
//��UNIT_MAG_OBJECT���CCM5_UNIT_URI
//const L3LONG SAMPLE_ADDR_COUNT = 14;
//const CString SAMPLE_ADDR[SAMPLE_ADDR_COUNT] = {_T("H1"),_T("H2"),
//                                                _T("Z1"), _T("Z2"), _T("Z3"), _T("Z4"),
//                                                _T("F1"),_T("F2"),_T("F3"),
//                                                _T("L1"),_T("L2"),_T("L3"),_T("L4"),_T("L5")};
//
//const CString UNIT_MAG_OBJECT[SAMPLE_ADDR_COUNT] = {MIXFProduceUnit1_URI,MIXFProduceUnit1_URI,
//                                                    BOF1_UNIT_URI,BOF2_UNIT_URI,BOF3_UNIT_URI,BOF4_UNIT_URI,
//                                                    LF1_UNIT_URI,LF2_UNIT_URI,LF3_UNIT_URI,
//                                                    CCM1_UNIT_URI,CCM2_UNIT_URI,CCM3_UNIT_URI,CCM4_UNIT_URI,CCM4_UNIT_URI};

const L3LONG SAMPLE_ADDR_COUNT = 19;
//modify by hyh 2012-05-09
const CString SAMPLE_ADDR[SAMPLE_ADDR_COUNT] = {_T("H1"),_T("H2"),_T("H3"),
                                                _T("Z1"), _T("Z2"), _T("Z3"), _T("Z4"),
                                                _T("F1"),_T("F2"),_T("F3"),_T("F5"),_T("F4"),
                                                _T("L1"),_T("L2"),_T("L3"),_T("L4"),_T("L5"),_T("L7"),_T("L6")};

const CString UNIT_MAG_OBJECT[SAMPLE_ADDR_COUNT] = {MIXFProduceUnit1_URI,MIXFProduceUnit1_URI,
                                                    BOF1_UNIT_URI,BOF2_UNIT_URI,BOF3_UNIT_URI,BOF4_UNIT_URI,
                                                    LF1_UNIT_URI,LF2_UNIT_URI,LF3_UNIT_URI,LF5_UNIT_URI,LF4_UNIT_URI,
                                                    CCM1_UNIT_URI,CCM2_UNIT_URI,CCM3_UNIT_URI,CCM4_UNIT_URI,CCM5_UNIT_URI,CCM7_UNIT_URI,CCM6_UNIT_URI};
//end by hyh
//Modify end  

inline CString GetRealHeatID(LPCTSTR lpcszVirtualID)
{
	CString strRealID = lpcszVirtualID; strRealID.Trim();
	//if(strRealID.Mid(4,1) == _T("9"))
	//	strRealID.SetAt(4,_T('0'));
	return strRealID;
}