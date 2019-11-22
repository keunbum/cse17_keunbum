<?php
	$n = intval(fgets(STDIN));
	$a = [];
	for ($i = 0; $i < $n; $i++) {
		$a[$i] = intval(fgets(STDIN));
	}
	sort($a);
	ob_start();
	foreach ($a as $i) {
		echo $i."\n";
	}
	ob_flush();
?>
