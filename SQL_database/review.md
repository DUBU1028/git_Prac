CRUD = create, read, update, delete - input과 output을 의미한다.
Oracle 또한 database의 일종이다.
Relational DBMS = 관계형 데이터베이스
SQL = structured query language - 하나의 컴퓨터 언어

# Relational DBMS의 3요소#

1. table(표)
2. database or schema(데이터베이스 - table을 그룹핑한 모음)
3. database server(mysql과 같은 database들을 관리하는 server)

### MySQL 실행방법 - cmd
1. MySQL Server의 bin 위치를 가져온다.
2. cmd창에서 mysql -uroot -p 명령어를 입력한다.
3. password를 입력한다.

### MySQl 실행방법 - MySQL shell
1. MySQL shell에 \connect root@localhost:3306 명령어를 입력한다.
2. password를 입력한다.
3. password save는 n 한다.

### MySQl 기본 사용법
1. CREATE DATABASE "database 이름" = 새로운 database 생성
2. USE "database 이름" = 사용할 database 선택
3. SHOW DATABASES = 생성된 모든 database들을 나열
4. DROP DATABASE "database 이름" = database 삭제
5. \sql = sql 명령어를 받아드릴 준비를 시키는것

### MySQL table 관련 명령어
1. desc "table 이름" = table의 행및 열의 구성을 보여줌
2. select \*from "table 이름" = table 내부 자료들을 보여줌
3. show tables = "생성된 table들을 보여줌"
4. insert into "table 이름"(칼럼1, 칼럼2, ...) values('칼럼1의 data', '칼럼2의 data', '...'); = 생성된 table에 새로운 행을 생성함 - 생성시 각 열에 맞는 data를 추가함
5. NOW() = 함수로써 현재 시간을 보여줌
6. update "table 이름" set "칼럼이름 = '그 칼럼에 들어갈 값'" where id = 바꿀 행 값; = 특정 table의 특정 열의 특정 행의 값을 변경함
7. alter table "table 이름" add "칼럼이름" "데이터타입" not null; = table에 새로운 칼럼 생성
8. where "칼럼이름" = '"특정 값"'; = 특정 칼럼에 위치한 모든 값중 특정 값을지닌 부분만을 제한하는 조건
9. order by "칼럼이름" "정렬조건" = 특정 칼럼을 특정 정렬조건으로 정렬시킴
10. limit "갯수" = 트랜잭션될 항목의 최대갯수를 제한함
11. delete from "table 이름" where "칼럼이름 = '특정행'"; = 특정행을 제거함
12. alter table "table 이름" rename "바꿀 table 이름" = table이름을 바꿈
13. alter table "table 이름" change "원래 칼럼이름" "바꿀 칼럼이름" "바꿀 칼럼의 type"; = 칼럼 이름 및 타입변경
14. select "보여질 칼럼들" from "선행 table" left join "후행 table" on "두 table의 join 기준"; = 두 table이 하나로 결합되어 필요한 칼럼들을 보여줌

### MySQL 주의사항
1. where은 from 다음에 쓸것
2. delete 및 update시 where을 붙여주어야 한다. 그렇지 않으면table내 모든 항목들이 update되거나 delete된다. 매우중요!!!
3. order by 다음에 limit을 쓸것
4. 두 table join 및 select시 같은 이름의 칼럼이 있다면 꼭 앞에 "table이름.칼럼이름"이라고 정확히 명시해야 한다.
