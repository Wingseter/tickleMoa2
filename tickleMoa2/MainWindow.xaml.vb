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
    Private dbPtr As IntPtr

    '' 생성자
    Public Sub New()

        ' 디자이너에서 이 호출이 필요합니다. 그렇군요!
        InitializeComponent()

        '' DB 생성
        dbPtr = CreateDatabase()
        ' DB 관련 설정 내용
        Dim sqlConf = New sqlConfig
        ' DB 연결
        retVal = connectDB(dbPtr, sqlConf.SQL_SERVER, sqlConf.SQL_DB, sqlConf.SQL_ID, sqlConf.SQL_PW)

        ' 연결 실패하면 종료
        If retVal = False Then
            Close()
        End If

    End Sub

    '' 소멸자
    Protected Overrides Sub Finalize()
        ' DB 삭제
        DeleteDatabase(dbPtr)
    End Sub

    Private Sub On_Submit_Btn_Clk(sender As Object, e As RoutedEventArgs)
        Dim usage As String
        Dim money As String
        Dim useDate As String

        usage = inputUsage.Text
        money = inputMoney.Text
        useDate = "2010.11.10"

        Dim item = New UseInfo With {.Usage = usage, .Money = money, .UseDate = useDate}
        gridUsage.Items.Add(item)
    End Sub
End Class


Public Class UseInfo
    '변수 정의 
    Private _usage As String '사용 목적
    Private _money As String '금액
    Private _useDate As String '사용 날짜
    ' 사용 목적 설정
    Property Usage() As String
        Get
            Return _usage
        End Get
        Set(ByVal Usage As String)
            Me._usage = Usage
        End Set
    End Property
    '금액 설정
    Property Money() As String
        Get
            Return _money
        End Get
        Set(ByVal Money As String)
            Me._money = Money
        End Set
    End Property
    ' 사용 날짜 설정
    Property UseDate() As String
        Get
            Return _useDate
        End Get
        Set(ByVal UseDate As String)
            Me._useDate = UseDate
        End Set
    End Property
End Class

