Imports System.Runtime.InteropServices

'extern "C" __declspec(dllexport)
'INT __stdcall plus(INT a, INT b) {
'	Return a + b;
'}

'extern "C" __declspec(dllexport) void __cdecl strReturn(LPSTR str) {
'	MessageBox(NULL, str, "test", MB_OK);
'}

'extern "C" __declspec(dllexport) BSTR __cdecl sprint(LPSTR str1, LPSTR str2) {
'	//TCHAR test[100];
'	//sprintf_s(test, 100, "%s %s", str1, str2);

'	//LPCSTR test2 = "helloworld";
'	BSTR test3 = SysAllocString(L"helloworld");
'	Return test3;
'}


Class MainWindow
    <DllImport("C:\Users\wings\source\repos\tickleMoa2\Debug\database.dll", CallingConvention:=CallingConvention.Cdecl)>
    Public Shared Function CreateDatabase() As IntPtr
    End Function

    <DllImport("C:\Users\wings\source\repos\tickleMoa2\Debug\database.dll", CallingConvention:=CallingConvention.Cdecl)>
    Public Shared Function connectDB(objptr As IntPtr, server As String, db As String, id As String, pw As String) As Boolean
    End Function

    <DllImport("C:\Users\wings\source\repos\tickleMoa2\Debug\database.dll", CallingConvention:=CallingConvention.Cdecl)>
    Public Shared Function DeleteDatabase(objptr As IntPtr)
    End Function
    '<DllImport("C:\Users\wings\source\repos\tickleMoa2\Debug\database.dll", CallingConvention:=CallingConvention.Cdecl)>
    'Private Shared Function sprint(ByVal str1 As String, ByVal str2 As String) As <MarshalAs(UnmanagedType.LPStr)> String
    'End Function

    Private retVal As Boolean
    Public Sub New()

        ' 디자이너에서 이 호출이 필요합니다. 그렇군요!
        InitializeComponent()

        '' DB 생성
        Dim dbPtr As IntPtr
        dbPtr = CreateDatabase()

        ' DB 관련 설정 내용
        Dim sqlConf = New sqlConfig

        ' DB 연결
        retVal = connectDB(dbPtr, sqlConf.SQL_SERVER, sqlConf.SQL_DB, sqlConf.SQL_ID, sqlConf.SQL_PW)


    End Sub

    Private Sub On_Submit_Btn_Clk(sender As Object, e As RoutedEventArgs)

    End Sub
End Class
