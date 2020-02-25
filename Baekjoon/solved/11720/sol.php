<?php
	$n = intval(fgets(STDIN));
	$s = rtrim(fgets(STDIN));
	$a = str_split($s);
	$ans = 0;
	foreach ($a as $i) {
		$ans += $i;
	}
	echo $ans."\n";
?>
