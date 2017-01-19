#!/bin/bash

BASEDIR=`pwd`
TESTDIR="$BASEDIR"
RESULTDIR="$BASEDIR"
TIMEOUT=10
LIMIT=102400
MAX=10
GCC=g++
SHELL="/bin/sh -c"

function timeout()
{
	perl -e 'alarm shift; exec @ARGV' "$@";
}

function log()
{
    echo "$@" >&2
}

function write_status()
{
    log "$1"
}


function run_tests()
{
    TMPDIR="$BASEDIR"
 
    CPPOPTS=-std=c++11

    for ID in `seq 1 $MAX`
    do
	log "Testing program $ID"
	SRC=`find "$TMPDIR" -name "fn*_prob$ID\_*.cpp" -print0`
	EXE="$TMPDIR/prog$ID"
	if [ -f "$SRC" ]
	then
	    # try to compile
	    $GCC -o "$EXE" $CPPOPTS "$SRC" 2>/dev/null
	    if [ -x "$EXE" ]
	    then
		# start tests for this program one by one
		for TESTIN in "$TESTDIR/$ID"?.test
		do
		    TESTBASE=`basename "$TESTIN" .test`
		    TESTOUT="$TESTIN".ans
		    PROGRESULT="$RESULTDIR"/"$TESTBASE"
		    PROGOUT="$PROGRESULT".out
		    PROGERR="$PROGRESULT".err

		    log -n "Running test $TESTBASE: "

		    # cleanup first
		    rm -f "$PROGOUT" "$PROGERR"

		    # run in a subshell, timeboxed and with limited output
		    STATUS=`timeout $TIMEOUT "$EXE" < "$TESTIN" 2> "$PROGERR" | head -c $LIMIT > "$PROGOUT"; echo ${PIPESTATUS[0]}`

		    # check for timeout
		    if [ $STATUS = 124 ]
		    then
			write_status "TO"
		    # check for output limit
		    elif [ $STATUS = 141 ]
		    then
			write_status "OL"
		    # check for runtime error
		    elif [ $STATUS != 0 ]
		    then
			write_status "RE"
		    else
			# check against expected output
                        # ignore space changes to permit multiple spaces instead of one
                        # and to handle different Windows/Unix/MacOSX EOLs correctly
			if diff -b "$PROGOUT" "$TESTOUT" > /dev/null 2> /dev/null
			then
			    write_status "OK"
			else
			    write_status "WA"
			fi
		    fi
		done
	    else
		for TESTIN in "$TESTDIR/$ID"?.test
		do
		    write_status "CE"
		done
	    fi
	else
	    for TESTIN in "$TESTDIR/$ID"?.test
	    do
		write_status "NA"
	    done
	fi
    done
    
}

run_tests
