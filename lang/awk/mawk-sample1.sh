last | grep lumin | grep -v still | mawk 'NF==9{print $9} NF==10{print $10}' | sort -n | tr -d '()' | mawk '{FS=":"}{HOURS = $1; MINS = MINS + $2 + HOURS * 60; TO = MINS / 60}{print TO}' | tail -n1
