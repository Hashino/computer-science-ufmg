LOAD DATA
INFILE works_on.csv
APPEND INTO TABLE works_on
FIELDS TERMINATED BY ','  OPTIONALLY ENCLOSED BY '"'
TRAILING NULLCOLS
(essn,pno,hours)
