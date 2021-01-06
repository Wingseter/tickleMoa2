Imports System.Runtime.InteropServices

Class MainWindow
    '' 에러 변수
    Private retVal As Boolean
    '' DB 생성
    Private dbPtr As databaseLib.myDB

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
        dbPtr.exitDB()
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
        ' 사용 내역
        Dim usage As String
        ' 사용 금액
        Dim money As String
        ' 사용 시간
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

        ' 사용자 입력 가져오기
        usage = inputUsage.Text
        money = inputMoney.Text

        ' 사용 내역 공백
        If usage = "" Then
            MessageBox.Show("사용 내역을 입력하세요")
            ' 사용 금액 공백
        ElseIf money = "" Then
            MessageBox.Show("사용 금액을 입력하세요")
        End If

        ' 출금은 -(마이너스) 로 설정
        If radioInput.IsChecked = True Then
            money = money
        Else
            money = -money
        End If

        ' 입력 query 실행
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

