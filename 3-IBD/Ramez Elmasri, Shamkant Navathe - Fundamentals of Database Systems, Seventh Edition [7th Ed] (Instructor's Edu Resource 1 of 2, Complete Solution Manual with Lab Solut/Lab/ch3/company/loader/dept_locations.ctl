LOAD DATA
INFILE dept_locations.csv
APPEND INTO TABLE dept_locations
FIELDS TERMINATED BY ','  OPTIONALLY ENCLOSED BY '"'
TRAILING NULLCOLS
(dnumber,dlocation)