<?php
	$s = rtrim(fgets(STDIN));
	$n = strlen($s);
	$a = array_fill(0, 128, -1);
	for ($i = $n - 1; $i >= 0; $i--) {
		$a[ord($s[$i])] = $i;
	}
	$ans = [];
	for ($i = 0; $i < 26; $i++) {
		$ans[] = $a[$i + ord('a')];
	}
	echo implode(' ', $ans)."\n";
?>
