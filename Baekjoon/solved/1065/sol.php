<?php
	$n = (int) fgets(STDIN);
	$ans = 0;
	function IsHan($x) {
		if ($x < 100) {
			return True;
		}
		$a = intdiv($x, 100);
		$b = intdiv($x, 10) % 10;
		$c = $x % 10;
		return $b + $b == $a + $c;
	}
	while ($n > 0) {
		$ans += (int) IsHan($n--);
	}
	echo $ans."\n";
?>
