<?php
	$t = (int) fgets(STDIN);
	$n = $t;
	$i = 0;
	do {
		$b = $n % 10;
		$a = $n / 10;
		$c = $a + $b;
		$n = $b * 10 + $c % 10;
		$i++;
	} while ($n != $t);
	echo $i."\n";
?>
