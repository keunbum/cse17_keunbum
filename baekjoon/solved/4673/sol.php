<?php
	function D($n) {
		$res = $n;
		while ($n > 0) {
			$res += $n % 10;
			$n /= 10;
		}
		return $res;
	}
	$MAX = (int) 1e4;
	$a = [];
	for ($i = 1; $i <= $MAX; $i++) {
		if (!in_array($i, $a)) {
			echo $i."\n";
		}
		$a[] = D($i);
	}
?>
