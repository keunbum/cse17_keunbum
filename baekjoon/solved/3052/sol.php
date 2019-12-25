<?php
	$a = [];
	for ($i = 0; $i < 10; $i++) {
		$n = (int) fgets(STDIN);
		$a[$i] = $n % 42;
	}
	$a = array_unique($a);
	echo count($a)."\n";
?>
