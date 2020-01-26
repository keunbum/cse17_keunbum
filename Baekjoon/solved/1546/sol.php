<?php
	$n = intval(fgets(STDIN));
	$a = explode(' ', rtrim(fgets(STDIN)));
	$mx = max($a);
	$sum = array_sum($a);
	echo $sum / $n * 100 / $mx."\n";
?>
