<?php
	$n = (int) fgets(STDIN);
	$s = fgets(STDIN);
	$ans = 0;
	for ($i = 0; $i < $n; $i++) {
		$ans += $s[$i];
	}
	echo $ans."\n";
?>
