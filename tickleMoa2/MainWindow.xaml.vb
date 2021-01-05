Imports System.Runtime.InteropServices

Class MainWindow
    '' 데이터 베이스 생성
    <DllImport("C:\Users\wings\source\repos\tickleMoa2\Debug\database.dll", CallingConvention:=CallingConvention.Cdecl)>
    Public Shared Function CreateDatabase() As IntPtr
    End Function
    '' 데이터 베이스 제거
    <DllImport("C:\Users\wings\source\repos\tickleMoa2\Debug\database.dll", CallingConvention:=CallingConvention.Cdecl)>
    Public Shared Function DeleteDatabase(objptr As IntPtr)
    End Function
    '' DB 연결
    <DllImport("C:\Users\wings\source\repos\tickleMoa2\Debug\database.dll", CallingConvention:=CallingConvention.Cdecl)>
    Public Shared Function connectDB(objptr As IntPtr, server As String, db As String, id As String, pw As String) As Boolean
    End Function
    '' Query 실행
    <DllImport("C:\Users\wings\source\repos\tickleMoa2\Debug\database.dll", CallingConvention:=CallingConvention.Cdecl)>
    Public Shared Function execQuery(objptr As IntPtr, query As String, opt As Integer) As Boolean
    End Function
    '' 실행 결과 다음 row로 이동
    <DllImport("C:\Users\wings\source\repos\tickleMoa2\Debug\database.dll", CallingConvention:=CallingConvention.Cdecl)>
    Public Shared Function nextObj(objptr As IntPtr) As Boolean
    End Function
    '' 해당 row 결과 모두 전송
    <DllImport("C:\Users\wings\source\repos\tickleMoa2\Debug\database.dll", CallingConvention:=CallingConvention.Cdecl)>
    Public Shared Function getResultString(objptr As IntPtr) As <MarshalAs(UnmanagedType.LPStr)> String
    End Function
    '' 해당 row 결과 선택된 col 전송
    <DllImport("C:\Users\wings\source\repos\tickleMoa2\Debug\database.dll", CallingConvention:=CallingConvention.Cdecl)>
    Public Shared Function getResult(objptr As IntPtr, nSubItem As Integer) As <MarshalAs(UnmanagedType.LPStr)> String
    End Function
    '' 결과 초기화
    <DllImport("C:\Users\wings\source\repos\tickleMoa2\Debug\database.dll", CallingConvention:=CallingConvention.Cdecl)>
    Public Shared Sub clearResult(objptr As IntPtr)
    End Sub

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

        ' 전체 데이터 불러오기
        refresh()
    End Sub

    '' 소멸자
    Protected Overrides Sub Finalize()
        ' DB 삭제
        DeleteDatabase(dbPtr)
    End Sub


    '' 전체 데이터로 새로 고침
    Private Sub refresh()
        ' 전체 목록 비우기
        clear()

        ' 전체 목록 불러오기
        retVal = execQuery(dbPtr, "SELECT * FROM Spends", 1)

        ' 목록 불러오기 실패하면 종료
        If retVal = False Then
            Close()
        End If

        ' 목록 업데이트 
        update()
    End Sub

    '' 테이블 비우기
    Private Sub clear()
        ' db 결과 버퍼 비우기
        clearResult(dbPtr)

        ' 전체 삭제
        gridUsage.Items.Clear()

    End Sub

    '' 목록 내용 업데이트
    Private Sub update()
        While nextObj(dbPtr)
            Dim test As String = getResultString(dbPtr)
            Dim usage As String = getResult(dbPtr, 0)
            Dim money As String = getResult(dbPtr, 1)
            Dim useDate As String = getResult(dbPtr, 2)
            Dim item = New UseInfo With {.Usage = usage, .Money = money, .UseDate = useDate}
            gridUsage.Items.Add(item)
        End While
    End Sub

    Private Sub On_Submit_Btn_Clk(sender As Object, e As RoutedEventArgs)
        Dim usage As String
        Dim money As String

        'execQuery(dbPtr, "SELECT * FROM Spends", 1)

        usage = inputUsage.Text
        money = inputMoney.Text

        Dim query As String = String.Format("EXEC dbo.input_new_user '{0}','{1}'", usage, money)
        refresh()
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

