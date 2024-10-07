


range=$1
which=$2

function die() {
    local msg="$1"

    echo "ERROR: $1"
    exit 1
}

[ -z "$which" ] && die "arg2 must be one of -r (reverse sorted), -R (random) or -s (sorted)"
[ ! -z "$which" ] && [ "$which" != "-r" -a "$which" != "-s" -a "$which" != "-R" ] && die "arg2 must be one of -r (reverse sorted), -R (random) or -s (sorted)"

case "$which" in
    -s)
        param="-g"
        param_str="sorted"
	;;
    -r)
        param="-r -g"
        param_str="reverse_sorted"
	;;
    -R)
        param=-R
        param_str="random"
	;;
esac

# generate 
echo "Generating $param_str sequece data in the range 1..$range"
fname=$range.$param_str.dat
time seq 1 $range | sort $param > $fname

echo "Data written to $fname"
echo "________________________________________________________"

exit 0

