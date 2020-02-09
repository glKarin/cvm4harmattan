#
# Regular cron jobs for the cvm package
#
0 4	* * *	root	[ -x /usr/bin/cvm_maintenance ] && /usr/bin/cvm_maintenance
