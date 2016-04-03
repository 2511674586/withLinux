SQL Note
---

> sqlite.org  
> http://www.w3school.com.cn/sql/index.asp  

Note, SQL is case insensitive!  

A sql command is like
```
select LastName from Persons
```

SQL contains  
* DML, data manipulation language  
* DDL, data definition language  

DML is like  
* select  
* update  
* delete  
* insert into  

DDL is like  
* create database  
* alter database  
* create table  
* alter table  
* drop table  
* create index  
* drop index  

### SELECT
```
select <colomn_name> from <table_name>
select * from <table_name>
```

### SELECT DISTINCT
```
select distinct <column_name> from <table_name>
```

### WHERE
```
select <column_name> from <table_name> where <column> <operator> <value>

operators:
=  equal
<> inequal
>
<
>=
<=
BETWEEN
LIKE
```
e.g. `select * from Persons where City='Beijing'`

### AND, OR
e.g. `select * from Persons where FirstName='Thomas' and LastName='Carter'`  
e.g. `select * from Persons where FirstName='Thomas' or LastName='Carter'`  
e.g. `SELECT * FROM Persons WHERE (FirstName='Thomas' OR FirstName='William') AND LastName='Carter'`

### ORDER
e.g. `SELECT Company, OrderNumber FROM Orders ORDER BY Company`  
e.g. `SELECT Company, OrderNumber FROM Orders ORDER BY Company, OrderNumber`  
e.g. `SELECT Company, OrderNumber FROM Orders ORDER BY Company DESC`  
e.g. `SELECT Company, OrderNumber FROM Orders ORDER BY Company DESC, OrderNumber ASC`  

### INSERT INTO
```
insert into <table_name> values <value1, value2, ...>
insert into <table_name> (column1, column2, ...) values (<value1, value2, ...>)
```

### UPDATE
```
update <table_name> set <column_name> = <new_value> where <column_name> = <value>
```

## DELETE
```
delete from <table_name> where <column_name> = value
delete * from <table_name>
```

TODO
