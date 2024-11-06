time_alg ()
{
  tput sc
  echo '' > "${1}_${2}.txt"
  for i in $(seq 1 $3); do 
    ret=$(echo -n $i ' ' && ./bin/pa3 -n $i -a $1 -$2)
    echo $ret >> "${1}_${2}.txt"

    tput rc;tput el # rc = restore cursor, el = erase to end of line
    echo -n $1 $2 "[${i}/${3}]"
  done
  echo ''
}

time_alg fib r 20
time_alg fib i 1200
time_alg fac r 1200
time_alg fac i 1200
