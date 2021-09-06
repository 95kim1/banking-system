# banking-system
practice for cpp and oop
---
### version 0.1
- banking system 틀 만들기
- C style

### version 0.2
- change struct Account to class Account
- constructor, destructor
- information hiding
- encapsulation 

### version 0.3
- add copy constructor

### version 0.4
- const member function

### version 0.5
- Control Class
  + to implement AccountHandler class

### version 0.6
- Inheritance
  + Account <-- NormalAccount
  + NormalAccount <-- HighCreditAccount

### version 0.7
- 파일 분할
  + Account.h, Account.cpp
  + NormalAccount.h
  + HighCreditAccount.h
  + CommonDeclare.h
  + BankingSystemMain.cpp

### version 0.8
- to add Dynamic array class
  + AccountDArray
- to update AccountHandler
  + to apply AccountDArray
- to update Account
  + to add operator functions

### version 0.9
- to add String class
  + String
- to update Acount
  + char* to String
- to update NormalAcount
  + char* to String
- to update HighCreditAcount
  + char* to String

### version 0.92
- to update AccountDArray into a template
  + file name changed (AccountDArray -> BoundCheckDArray)
  + 2 files were integrated (BoundCheckDArray = AccountDArray.h + AccountDArray.cpp)

### version 0.93
- 예외 처리
  + AccountHandler.h
    * 에러 처리 적용
  + AccountException.h
    * 음수 금액 입력
    * 잔액 부족
    * 동일 계좌 입력
    * 개설되지 않은 계좌 입력
    * 신뢰등급: 잘못된 번호 입력
    * 문자 포함된 금액 입력
