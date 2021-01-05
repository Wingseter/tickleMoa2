Imports System.Runtime.InteropServices

extern "C" __declspec(dllexport)
INT __stdcall plus(INT a, INT b) {
	Return a + b;
}

extern "C" __declspec(dllexport) void __cdecl strReturn(LPSTR str) {
	MessageBox(NULL, str, "test", MB_OK);
}

extern "C" __declspec(dllexport) BSTR __cdecl sprint(LPSTR str1, LPSTR str2) {
	//TCHAR test[100];
	//sprintf_s(test, 100, "%s %s", str1, str2);

	//LPCSTR test2 = "helloworld";
	BSTR test3 = SysAllocString(L"helloworld");
	Return test3;
}


Class MainWindow
    <DllImport("C:\Users\wings\source\repos\tickleMoa2\Debug\database.dll", CallingConvention:=CallingConvention.Cdecl)>
    Public Shared Function plus(ByVal num1 As Integer, ByVal num2 As Integer) As Integer
    End Function

    <DllImport("C:\Users\wings\source\repos\tickleMoa2\Debug\database.dll", CallingConvention:=CallingConvention.Cdecl)>
    Private Shared Sub strReturn(ByVal str As String)
    End Sub

    <DllImport("C:\Users\wings\source\repos\tickleMoa2\Debug\database.dll", CallingConvention:=CallingConvention.Cdecl)>
    Private Shared Function sprint(ByVal str1 As String, ByVal str2 As String) As <MarshalAs(UnmanagedType.LPStr)> String
    End Function

    Private testStr As String
    Public Sub New()

        '' 디자이너에서 이 호출이 필요합니다. 그렇군요!
        InitializeComponent()

        'Dim etcStr As String
        'strReturn("Hello")


    End Sub

    Private Sub On_Submit_Btn_Clk(sender As Object, e As RoutedEventArgs)
        'testStr = sprint("hello", "world")
        testStr = "helloworld"
        MessageBox.Show(testStr)
    End Sub
End Class
