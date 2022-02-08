CRUD = create, read, update, delete - input과 output을 의미한다.
Oracle 또한 database의 일종이다.
Relational DBMS = 관계형 데이터베이스
SQL = structured query language - 하나의 컴퓨터 언어

# Relational DBMS의 3요소#

1. table(표)
2. database or schema(데이터베이스 - table을 그룹핑한 모음)
3. database server(mysql과 같은 database들을 관리하는 server)

# MySQL 실행방법 - cmd
1. MySQL Server의 bin 위치를 가져온다.
2. cmd창에서 mysql -uroot -p 명령어를 입력한다.
3. password를 입력한다.

# MySQl 실행방법 - MySQL shell
1. MySQL shell에 \connect root@localhost:3306 명령어를 입력한다.
2. password를 입력한다.
3. password save는 n 한다.

# MySQl 기본 사용법
1. CREATE DATABASE "database 이름" = 새로운 database 생성
2. USE "database 이름" = 사용할 database 선택
3. SHOW DATABASES = 생성된 모든 database들을 나열
4. DROP DATABASE "database 이름" = database 삭제
5. \sql = sql 명령어를 받아드릴 준비를 시키는것

# MySQL table 관련 명령어
1. desc "table 이름" = table의 행및 열의 구성을 보여줌
2. select \*from "table 이름" = table 내부 자료들을 보여줌
3. show tables = "생성된 table들을 보여줌"
4. insert into "table 이름"(칼럼1, 칼럼2, ...) values('칼럼1의 data', '칼럼2의 data', '...'); = 생성된 table에 새로운 행을 생성함 - 생성시 각 열에 맞는 data를 추가함
5. NOW() = 함수로써 현재 시간을 보여줌
6. update "table 이름" set "칼럼이름 = '그 칼럼에 들어갈 값'" where id = 바꿀 행 값; = 특정 table의 특정 열의 특정 행의 값을 변경함
