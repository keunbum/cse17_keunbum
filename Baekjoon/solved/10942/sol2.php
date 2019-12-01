<?php
	$n = (int) fgets(STDIN);
	$a = explode(' ', fgets(STDIN));
	for ($i = 0; $i < $n; $i++) {
		$a[$i] = (int) $a[$i];
	}
	$m = (int) fgets(STDIN);
	$dp[0][0] = 0;
	for ($i = 0; $i < $n; $i++) {
		for ($j = 0; $j < $n; $j++) {
			$dp[$i][$j] = -1;
		}
	}
	$F = function($x, $y) use ($dp, $a) {
		if ($dp[$x][$y] >= 0) {
			return $dp[$x][$y];
		}
		if ($a[$x] == $a[$y]) {
			return $dp[$x][$y] = $y - $x <= 2 ? 1 : $F($x + 1, $y - 1);
		}
		return $dp[$x][$y] = 0;
	};
	while ($m > 0) {
		$b = explode(' ', fgets(STDIN));
		$s = (int) $b[0];
		$e = (int) $b[1];
		echo $F($s - 1, $e - 1)."\n";
		$m--;
	}
?>
