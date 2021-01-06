Imports System.Runtime.InteropServices

Class MainWindow
    Private retVal As Boolean
    Private dbPtr As databaseLib.myDB
    '' DB 생성

    '' 생성자
    Public Sub New()

        ' 디자이너에서 이 호출이 필요합니다. 그렇군요!
        InitializeComponent()
        dbPtr = New databaseLib.myDB

        ' DB 관련 설정 내용
        Dim sqlConf = New sqlConfig
        ' DB 연결
        retVal = dbPtr.connectDB(sqlConf.SQL_SERVER, sqlConf.SQL_DB, sqlConf.SQL_ID, sqlConf.SQL_PW)

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
    End Sub


    '' 전체 데이터로 새로 고침
    Private Sub refresh()
        ' 전체 목록 비우기
        clear()

        ' 전체 목록 불러오기
        retVal = dbPtr.execQuery("SELECT * FROM Spends", 1)

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
        dbPtr.clearResult()

        ' 전체 삭제
        gridUsage.Items.Clear()

    End Sub

    '' 목록 내용 업데이트
    Private Sub update()
        Dim usage As String
        Dim money As String
        Dim useDate As String
        While dbPtr.nextObj()
            usage = dbPtr.getResult(1)
            money = dbPtr.getResult(2)
            useDate = dbPtr.getResult(3)
            Dim item = New UseInfo With {.Usage = usage, .Money = money, .UseDate = useDate}
            gridUsage.Items.Add(item)
        End While
    End Sub

    Private Sub On_Submit_Btn_Clk(sender As Object, e As RoutedEventArgs)
        Dim usage As String
        Dim money As String

        usage = inputUsage.Text
        money = inputMoney.Text

        Dim query As String = String.Format("EXEC dbo.input_new_spend '{0}','{1}'", usage, money)
        retVal = dbPtr.execQuery(query, 0)
        If retVal = False Then
            Close()
        End If
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

