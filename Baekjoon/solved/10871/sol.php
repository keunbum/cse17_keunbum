<?php
	fscanf(STDIN, "%d %d", $n, $x);
	$a = explode(' ', fgets(STDIN));
	$ans = [];
	foreach ($a as $y) {
		if ($y < $x) {
			$ans[] = $y;
		}
	}
	echo implode(' ', $ans)."\n";
?>
