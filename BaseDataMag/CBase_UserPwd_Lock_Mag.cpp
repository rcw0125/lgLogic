//add by hyh 2012-04-12 
//�����û�Ҫ��ʱ�����빦��
// �߼���CBase_UserPwd_Lock_Mag���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CBase_UserPwd_Lock_Mag.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CBase_UserPwd_Lock_Mag.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CBase_UserPwd_Lock_Mag.h"

//������װ�ص�ϵͳ��ʱ��������
void CBase_UserPwd_Lock_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CBase_UserPwd_Lock_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}

//
//

/// <Method class="CBase_UserPwd_Lock_Mag" name="GetUserLastUpdTime" type="L3STRING">
/// ��ȡ�û��ϴ��޸�����ʱ��
/// <Param name="userId" type="L3STRING">�û���</Param>
/// <Param name="passWord" type="L3STRING">����</Param>
/// </Method>
L3STRING CBase_UserPwd_Lock_Mag::GetUserLastUpdTime(L3STRING userId, L3STRING passWord)
{
	CString csId=String_BSTR2TChar(userId);//�û���
	CString csPwd=String_BSTR2TChar(passWord);//����
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	CString csCurDate = curTime.Format(_T("%Y-%m-%d %H:%M:%S"));

	//CString csTemp = _T(" select to_char(LASTMODTIME,'yyyy-MM-dd HH-mm-ss') from %s where userID ='%s' ");
	CString csTemp = _T(" select  LASTMODTIME from %s where userID ='%s' ");
	CString csSQL;
	csSQL.Format(csTemp,UserPwd_Lock_URI,csId);
	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs))
		return csCurDate.AllocSysString();
	if(rs.GetRowCount()<1)
		UpdPassWord(csId.AllocSysString(),csPwd.AllocSysString());
	else
	{
		rs.MoveFirst();
		CL3Variant vatDate=rs.GetFieldByName(_T("LASTMODTIME"));
		COleDateTime dt=COleDateTime(vatDate.ToDateTime());

		CString csdd=dt.Format(_T("%Y-%m-%d %H:%M:%S"));
		return csdd.AllocSysString();
	}
	return csCurDate.AllocSysString();
}

/// <Method class="CBase_UserPwd_Lock_Mag" name="UpdPassWord" type="L3SHORT">
/// ��¼�û��޸�������Ϣ
/// <Param name="userId" type="L3STRING"></Param>
/// <Param name="passWord" type="L3STRING"></Param>
/// </Method>
L3SHORT CBase_UserPwd_Lock_Mag::UpdPassWord(L3STRING userId, L3STRING passWord)
{
	//��ѯ�Ƿ���ڴ��û����������������������޸�
	CString csId=String_BSTR2TChar(userId);//�û���
	//CString csPwd=String_BSTR2TChar(passWord);//����
	CString csPwd=_T("******");
	CString csTemp = _T(" select * from %s where userId ='%s' ");
	CString csSQL;
	csSQL.Format(csTemp,UserPwd_Lock_URI,csId);
	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs))
		return 1;
	//if(rs.IsNull)
	//	return 1;
	//��һ���յı�
	CL3RecordSetWrap rsUserPwdLock;
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	if(!CreateClassPropSet(UserPwd_Lock_URI,rsUserPwdLock))
		return 1;
	rsUserPwdLock.AppendRecord();  
	rsUserPwdLock.SetFieldByName(_T("userID"),CL3Variant(csId));
	rsUserPwdLock.SetFieldByName(_T("passWord"),CL3Variant(csPwd));
	rsUserPwdLock.SetFieldByName(_T("lastModTime"),CL3Variant(curTime));

	if (rs.GetRowCount()> 0)//�У����޸������ʱ��  
	{
		if(SetObjPropValues(UserPwd_Lock_URI + CString(_T("\\")) + userId,rsUserPwdLock)==1)
			return 0;
	}
	else//�ޣ�������
	{
		if(CreateNewObjects(UserPwd_Lock_URI,rsUserPwdLock) < rsUserPwdLock.GetRowCount())        //����ָ����Ķ������
			return 0;
	}
}
